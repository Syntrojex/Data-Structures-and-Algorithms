#include<iostream>
#include<stack>

using namespace std;

int evaluatePostFix(string exp)
{
	stack<int> st;

	int ans;

	for (char ch : exp)
	{
		// Agar character digit hai toh usay integer mein convert karke
		// stack mein push kar do
		if (ch >= '0' && ch <= '9')
		{
			st.push(ch - '0');
		}

		// Agar + operator hai toh stack ke top ke 2 operands nikalo
		// aur unko add karke result dobara stack mein push karo
		if (!st.empty() && ch == '+')
		{
			int num1 = st.top();
			st.pop();

			int num2 = st.top();
			st.pop();

			int result = num2 + num1;
			st.push(result);
		}

		// - mein pehle nikla hua number second operand hota hai
		// isliye num2 - num1 karna hota hai
		else if (!st.empty() && ch == '-')
		{
			int num1 = st.top();
			st.pop();

			int num2 = st.top();
			st.pop();

			int result = num2 - num1;
			st.push(result);
		}

		// * mein operand order matter nahi karta
		else if (!st.empty() && ch == '*')
		{
			int num1 = st.top();
			st.pop();

			int num2 = st.top();
			st.pop();

			int result = num2 * num1;
			st.push(result);
		}

		// / mein bhi num2 ko num1 se divide karna hota hai
		else if (!st.empty() && ch == '/')
		{
			int num1 = st.top();
			st.pop();

			int num2 = st.top();
			st.pop();

			int result = num2 / num1;
			st.push(result);
		}

		// % mein bhi num2 % num1 karna hota hai
		else if (!st.empty() && ch == '%')
		{
			int num1 = st.top();
			st.pop();

			int num2 = st.top();
			st.pop();

			int result = num2 % num1;
			st.push(result);
		}
	}

	// Final answer stack ke top par hoga
	ans = st.top();
	st.pop();

	return ans;
}

int main()
{
	string expression;

	cout << "Enter PostFix Expression: ";
	cin >> expression;

	cout << "Answer is: " << evaluatePostFix(expression) << endl;
}
