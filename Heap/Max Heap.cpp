#include<iostream>
using namespace std;

class MaxHeap {
	int* arr;
	int count;
	int capacity;

	void heapifyUp(int i)
	{
		while (i > 0)
		{
			int p = (i - 1) / 2;

			if (arr[i] > arr[p])
			{
				swap(arr[i], arr[p]);
				i = p;
			}
			else
			{
				break;
			}
		}
	}

	void heapifyDown(int i)
	{
		while (true)
		{
			int largest = i;
			int left = (i * 2) + 1;
			int right = (i * 2) + 2;

			if (left < count && arr[left]>arr[largest])
			{
				largest = left;
			}

			if (right < count && arr[right]>arr[largest])
			{
				largest = right;
			}

			if (largest == i)
			{
				break;
			}

			swap(arr[i], arr[largest]);
			i = largest;
		}
	}

public:
	MaxHeap(int c)
	{
		capacity = c;
		arr = new int[capacity];
		count = 0;
	}

	~MaxHeap()
	{
		delete[] arr;
		arr = nullptr;
	}

	bool empty()
	{
		return count == 0;
	}

	int extractMax()
	{
		int max = arr[0];
		arr[0] = arr[count - 1];
		count--;

		if (count > 0)
		{
			heapifyDown(0);
		}

		return max;
	}

	int getMax()
	{
		if (empty())
		{
			return -1;
		}

		return arr[0];
	}

	void insert(int value)
	{
		arr[count] = value;
		int index = count;
		count++;

		heapifyUp(index);
	}

	bool remove(int key)
	{
		int index = -1;
		for (int i = 0;i < count; i++)
		{
			if (arr[i] == key)
			{
				index = i;
				break;
			}
		}

		if (index == -1)
		{
			return false;
		}

		arr[index] = arr[count - 1];
		count--;

		if (index < count)
		{
			int p = (index - 1) / 2;
			if (index > 0 && arr[index] > arr[p])
			{
				heapifyUp(index);
			}
			else
			{
				heapifyDown(index);
			}
		}

		return true;

	}

	bool search(int key)
	{
		for (int i = 0;i < count; i++)
		{
			if (arr[i] == key)
			{
				return true;
			}
		}

		return false;
	}

	void display()
	{
		cout << "Array is: ";
		for (int i = 0;i < count;i++)
		{
			cout << arr[i];
			if (i != count - 1)
			{
				cout << ",";
			}
		}
		cout << endl;
	}
};

int main()
{
	MaxHeap h(10);
}
