#include "algo.h"

int Log2n(unsigned int n)
{
	return (n > 1) ? 1 + Log2n(n / 2) : 0;
}
void InsertionSort(int *data, int count)
{
	for (int i = 1; i < count; ++i)
	{
		int j = i;

		while (j > 0)
		{
			if (data[j - 1] > data[j])
			{
				data[j - 1] ^= data[j];
				data[j] ^= data[j - 1];
				data[j - 1] ^= data[j];

				--j;
			}
			else
			{
				break;
			}
		}
	}
}

void MaxHeapify(int *data, int heapSize, int index)
{
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

	if (left < heapSize && data[left] > data[index])
		largest = left;
	else
		largest = index;

	if (right < heapSize && data[right] > data[largest])
		largest = right;

	if (largest != index)
	{
		int temp = data[index];
		data[index] = data[largest];
		data[largest] = temp;

		MaxHeapify(data, heapSize, largest);
	}
}

void HeapSort(int *data, int count)
{
	int heapSize = count;

	for (int p = (heapSize - 1) / 2; p >= 0; --p)
		MaxHeapify(data, heapSize, p);

	for (int i = count - 1; i > 0; --i)
	{
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		--heapSize;
		MaxHeapify(data, heapSize, 0);
	}
}

int Partition(int *data, int left, int right)
{
	int pivot = data[right];
	int temp;
	int i = left;

	for (int j = left; j < right; ++j)
	{
		if (data[j] <= pivot)
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
			i++;
		}
	}

	data[right] = data[i];
	data[i] = pivot;

	return i;
}

void QuickSortRecursive(int *data, int left, int right)
{
	if (left < right)
	{
		int q = Partition(data, left, right);
		QuickSortRecursive(data, left, q - 1);
		QuickSortRecursive(data, q + 1, right);
	}
}

void IntroSort(int *data, int numberOflines)
{
	struct timeval tv1, tv2;
	
	int partitionSize = Partition(data, 0, numberOflines - 1);

	if (partitionSize < 16)
	{
		InsertionSort(data, numberOflines);
	}
	else if (partitionSize > (2 * Log2n(numberOflines)))
	{
		HeapSort(data, numberOflines);
	}
	else
	{
		QuickSortRecursive(data, 0, numberOflines - 1);
	}

}
