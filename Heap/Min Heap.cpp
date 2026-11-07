#include<iostream>
using namespace std;

class MinHeap {
	int* arr;
	int count;
	int capacity;

	void heapifyUp(int i)
	{
		while (i > 0)
		{
			int p = (i - 1) / 2;

			if (arr[p] > arr[i])
			{
				swap(arr[p], arr[i]);
				i = p;
			}
			else
			{
				break;
			}
		}
	}


	/*
	 smallest = index = > filhaal current node ko smallest maan lete hain.
	 Left child ka index calculate karte hain : 2 * index + 1.
	 Right child ka index calculate karte hain : 2 * index + 2.
	 Check karte hain ke left child exist karta hai aur current smallest se chhota hai.Agar haan, smallest = left.
	 Right child ke saath bhi same comparison karte hain.
	 Ab smallest mein current node ya dono children mein se sabse chhote ka index hoga.
	 Agar smallest == index hai, toh current node already correct position par hai.Loop break.
	 Warna current node ko smallest child ke saath swap kar dete hain.
	 Swap ke baad index = smallest karte hain, taake ab usi node ko uske naye children ke saath check kar sakein.
	 Ye process repeat hota hai jab tak node correct position par na aa jaye.
	*/

	void heapifyDown(int i)
	{
		while (true)
		{
			int smallest = i;

			int left = (2 * i) + 1;
			int right = (2 * i) + 2;

			// left < count check krta ha k left child exist krta ha k nhi
			// or kia us left ki value current smallest se choti ha
			if (left < count && arr[left] < arr[smallest])
			{
				smallest = left;
			}

			if (right < count && arr[right] < arr[smallest])
			{
				smallest = right;
			}

			if (smallest == i)
			{
				break;
			}

			swap(arr[i], arr[smallest]);

			// Swap ke baad index ko child ki position par le jao
			// taake us node ko uske naye children ke saath check kar sakein
			i = smallest;
		}
	}

public:
	MinHeap(int c)
	{
		capacity = c;
		arr = new int[capacity];
		count = 0;
	}

	~MinHeap()
	{
		delete[] arr;
		arr = nullptr;
	}

	bool empty()
	{
		return count == 0;
	}

	void insert(int data)
	{
		arr[count] = data;
		int index = count;
		count++;

		heapifyUp(index);
	}

	int getMin()
	{
		if (!empty())
		{
			cout << "Heap is Empty" << endl;
			return -1;
		}

		return arr[0];
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

	bool remove(int key) // remove a specific element
	{
		int index = -1;
		for (int i = 0;i < count;i++)
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

		/*
		Jis index par value mili thi, wahan heap ka last element rakh dete hain.
		heapSize-- kar dete hain, taake last element heap se logically remove ho jaye.
		Check karte hain ke replacement element parent se chhota hai ya nahi :
			- Parent se chhota hai : heapifyUp(index) — element ko upar le jana hai.
			- Parent se chhota nahi : heapifyDown(index) — element ko neeche le jana hai.
		*/

		arr[index] = arr[count - 1];
		count--;

		if (index < count)
		{
			int p = (index - 1) / 2;

			if (index > 0 && arr[index] < arr[p])
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

	int extractMin()  // remove min element
	{
		int minValue = arr[0];
		arr[0] = arr[count - 1]; // last wali value ko top pr laate hain

		count--;


		// agar size 0 nahi hai to uper wale ko neeche bhejna hota ha is liye 0 bheja uper
		if (count > 0)
		{
			heapifyDown(0);
		}

		return minValue;
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
	MinHeap h(10);

	return 0;
}
