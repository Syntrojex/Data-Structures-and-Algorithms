#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(string bracket)
{
	stack<char> input;

	for (char ch : bracket)
	{
		if (ch == '{' || ch == '[' || ch == '(')
		{
			input.push(ch);
		}

		else if (ch == '}')
		{
			if (!input.empty() && input.top() == '{')
			{
				input.pop();
				continue;
			}
			else
			{
				return false;
			}
		}
		else if (ch == ']')
		{
			if (!input.empty() && input.top() == '[')
			{
				input.pop();
				continue;
			}
			else
			{
				return false;
			}
		}
		else if (ch == ')')
		{
			if (!input.empty() && input.top() == '(')
			{
				input.pop();
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	return input.empty();
}

int main()
{
	string bracket;
	cout << "Enter Bracket Combination: ";
	cin >> bracket;

	if (isBalanced(bracket))
	{
		cout << "Balanced" << endl;
	}
	else
	{
		cout << "Not Balanced" << endl;
	}

	return 0;
}
