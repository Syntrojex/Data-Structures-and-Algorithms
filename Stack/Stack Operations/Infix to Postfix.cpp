#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}

	if (op == '*' || op == '/' || op == '%')
	{
		return 2;
	}
	return 0;
}

string convertToPostFix(string expression)
{
	stack<char> st;
	string postFix = "";

	for (char ch : expression)
	{
		// 1. Agar operand (number ya letter) ho toh output mein add karein
		if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			postFix += ch;
		}

		// 2. Agar opening bracket ho toh stack mein push karein
		else if (ch == '(')
		{
			st.push(ch);
		}

		// 3. Agar closing bracket ho toh '(' tak sab pop karein
		else if (ch == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				postFix += st.top();
				st.pop();
			}
			if (!st.empty() && st.top() == '(')
			{
				st.pop(); // '(' ko hata dein
			}
		}

		// 4. Agar operator ho
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		{
			while (!st.empty() && precedence(st.top()) >= precedence(ch))
			{
				postFix += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}

	while (!st.empty())
	{
		postFix += st.top();
		st.pop();
	}

	return postFix;
}

int main()
{
	string expression;
	cout << "Enter an InFix Expression: ";
	cin >> expression;

	cout << "InFix: " << expression << endl;
	cout << "PostFix: " << convertToPostFix(expression) << endl;

	return 0;
}
