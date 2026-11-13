#include<iostream>
using namespace std;

class Queue {
	int* arr;
	int rear;
	int front;
	int capacity;
	int count;

public:
	Queue(int c)
	{
		capacity = c;
		arr = new int[capacity];
		front = 0;
		rear = -1;
		count = 0;
	}

	~Queue()
	{
		delete[] arr;
		arr = nullptr;
	}

	bool isFull()
	{
		return count == capacity;
	}

	// Rear pr add krna 
	void enqueue(int data)
	{
		if (isFull())
		{
			cout << "Queue Overflow!" << endl;
			return;
		}

		rear = (rear + 1) % capacity;
		arr[rear] = data;
		count++;
	}


	// Front se Element nikalna 
	void dequeue()
	{
		if (empty())
		{
			cout << "Queue Underflow!" << endl;
			return;
		}
		front = (front + 1) % capacity;
		count--;
	}

	int front()
	{
		return arr[front];
	}

	int rear()
	{
		return arr[rear];
	}

	bool empty()
	{
		return count == 0;
	}

	void display()
	{
		for (int i = 0;i < count;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	bool search(int key)
	{
		for (int i = 0;i < count;i++)
		{
			if (arr[i] == key)
			{
				return true;
			}
		}

		return false;
	}
};

int main()
{
	Queue q(10);

	return 0;
}
