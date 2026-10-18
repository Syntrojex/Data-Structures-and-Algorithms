#include<iostream>
#include<stack>

using namespace std;

class MaxStack
{
public:
	stack<int> maxStack;
	stack<int> mainStack;

	MaxStack()
	{
		// Stacks automatically empty create ho jayenge
	}

	// Value ko main stack mein push karta hai
	// Agar ye current minimum se choti ya equal ho
	// toh minStack mein bhi push kar dete hain
	void push(int value)
	{
		mainStack.push(value);

		if (maxStack.empty() || maxStack.top() >= value)
		{
			maxStack.push(value);
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

		if (poppedValue == maxStack.top())
		{
			maxStack.pop();
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
	int getMax()
	{
		if (maxStack.empty())
		{
			cout << "Stack is Empty" << endl;
			return -1;
		}

		return maxStack.top();
	}
};

int main()
{
	MaxStack st;

	st.push(5);
	st.push(3);
	st.push(7);
	st.push(2);
	st.push(2);

	cout << "Top: " << st.top() << endl;
	cout << "Min: " << st.getMax() << endl;

	st.pop();

	cout << "Top after pop: " << st.top() << endl;
	cout << "Min after pop: " << st.getMax() << endl;

	st.pop();

	cout << "Top after pop: " << st.top() << endl;
	cout << "Min after pop: " << st.getMax() << endl;

	return 0;
}
