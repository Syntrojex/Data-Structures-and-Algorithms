#include <iostream>
using namespace std;

class Stack {
private:
	int* arr;
	int top;
	int count;
	int capacity;

public:

	class Iterator {
		int* current;
	public:

		Iterator(int* curr)
		{
			current = curr;
		}

		int& operator*()
		{
			return *current;
		}

		bool operator !=(const Iterator& other)
		{
			if (current != other.current)
			{
				return true;
			}
			return false;
		}

		Iterator& operator++()
		{
			current--; // bcz array me backward jana ha
			return*this;
		}

	};

	Stack()
	{
		capacity = 5;
		top = -1;
		arr = new int[capacity];
		count = 0;
	}

	Stack(int capacity)
	{
		this->capacity = capacity;
		top = -1;
		arr = new int[capacity];
		count = 0;
	}

	~Stack()
	{
		delete[] arr;
	}

	Iterator begin()
	{
		return Iterator(&arr[top]);
	}

	Iterator end()
	{
		return Iterator(&arr[-1]);
	}

	bool isEmpty()
	{
		return top == -1;
	}

	bool isFull()
	{
		return top == capacity - 1;
	}

	void push(int value)
	{
		if (isFull())
		{
			cout << "Stack Overflow" << endl;
			return;
		}
		top++;
		arr[top] = value;
		count++;
	}

	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack Underflow! Stack khali hai." << endl;
			return;
		}
		cout << "Popped element: " << arr[top] << endl;
		top--;
		count--;
	}

	int peek()
	{
		if (isEmpty())
		{
			cout << "Stack Underflow! Stack khali hai." << endl;
			return -1;
		}
		return arr[top];
	}

	int getElementCount()
	{
		return count;
	}

	void display()
	{
		if (isEmpty())
		{
			cout << "Stack Underflow! Stack khali hai." << endl;
			return;
		}

		cout << "\nStack is: " << endl;
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << endl;
		}
		cout << endl;
	}
};

void menu()
{
	cout << "\n===== STACK MENU =====" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Peek" << endl;
	cout << "4. Get Count" << endl;
	cout << "5. Display" << endl;
	cout << "6. Display Using Iterator" << endl;
}

int main()
{
	int cap;
	cout << "Enter Stack Capacity: ";
	cin >> cap;

	Stack s1(cap);

	int choice = -1;
	while (choice != 0)
	{
		menu();
		do
		{
			cout << "Enter Your choice (0-6): ";
			cin >> choice;

			if (choice < 0 || choice > 6)
			{
				cerr << "ERROR: Invalid Choice!" << endl;
			}
		} while (choice < 0 || choice > 6);

		switch (choice)
		{
		case 0:
			cout << "Exited Successfully." << endl;
			return 0;

		case 1:
		{
			int val;
			cout << "Enter Value to Push: ";
			cin >> val;
			s1.push(val);
			break;
		}

		case 2:
			s1.pop();
			break;

		case 3:
		{
			int p = s1.peek();
			if (p != -1)
			{
				cout << "Top Element is: " << p << endl;
			}
			break;
		}

		case 4:
			cout << "Total Elements in Stack: " << s1.getElementCount() << endl;
			break;

		case 5:
			s1.display();
			break;

		case 6:
			cout << "Traversing Stack using Iterator (Top to Bottom): " << endl;
			for (auto it = s1.begin(); it != s1.end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;
			break;

		default:
			cout << "Invalid Input" << endl;
		}
	}

	return 0;
}
