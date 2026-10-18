#include<iostream>
#include<stack>

using namespace std;

class MinStack
{
public:
	stack<int> minStack;
	stack<int> mainStack;

	MinStack()
	{
		// Stacks automatically empty create ho jayenge
	}

	// Value ko main stack mein push karta hai
	// Agar ye current minimum se choti ya equal ho
	// toh minStack mein bhi push kar dete hain
	void push(int value)
	{
		mainStack.push(value);

		if (minStack.empty() || minStack.top() >= value)
		{
			minStack.push(value);
		}
	}

	// Top value ko remove karta hai
	// Agar removed value current minimum ke equal ho
	// toh minStack se bhi remove kar dete hain
	void pop()
	{
		if (mainStack.empty())
		{
			cout << "Stack is Empty" << endl;
			return;
		}

		int poppedValue = mainStack.top();
		mainStack.pop();

		if (poppedValue == minStack.top())
		{
			minStack.pop();
		}
	}

	// Main stack ka top element return karta hai
	int top()
	{
		if (mainStack.empty())
		{
			cout << "Stack is Empty" << endl;
			return -1;
		}

		return mainStack.top();
	}

	// Current minimum value return karta hai
	int getMin()
	{
		if (minStack.empty())
		{
			cout << "Stack is Empty" << endl;
			return -1;
		}

		return minStack.top();
	}
};

int main()
{
	MinStack st;

	st.push(5);
	st.push(3);
	st.push(7);
	st.push(2);
	st.push(2);

	cout << "Top: " << st.top() << endl;
	cout << "Min: " << st.getMin() << endl;

	st.pop();

	cout << "Top after pop: " << st.top() << endl;
	cout << "Min after pop: " << st.getMin() << endl;

	st.pop();

	cout << "Top after pop: " << st.top() << endl;
	cout << "Min after pop: " << st.getMin() << endl;

	return 0;
}
