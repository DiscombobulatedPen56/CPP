#include <iostream>
#include <stack>
using namespace std;

int brackets_check(string brackets) {
	int count = 0;
	stack<char> BracketsStack;
	for (int i = 0; i < brackets.size(); i++) {
		if (brackets[i] == '[' || brackets[i] == '(' || brackets[i] == '{') {
			BracketsStack.push(brackets[i]);
		}
		else {
			if (brackets.empty()) {
				count++;
			}
			if (brackets[i] == ']' && BracketsStack.top() != '[') {
				count++;
			}
			else {
				BracketsStack.pop();
			}
			if (brackets[i] == ')' && BracketsStack.top() != '(') {
				count++;
			}
			else {
				BracketsStack.pop();
			}
			if (brackets[i] == '}' && BracketsStack.top() != '{') {
				count++;
			}
			else {
				BracketsStack.pop();
			}
		}
	}
	return count;
}

int main()
{
	string brackets;
	cin >> brackets;
	cout << brackets_check(brackets);
}

