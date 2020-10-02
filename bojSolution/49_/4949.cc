#include <iostream>
#include <string>
#include <stack>
using namespace std;

int K;
string input;
bool res;
stack<char>stk;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	while (true) {
		res = true;
		getline(cin, input);
		if (input == ".") break;
		for (char c : input) {
			if (c == '(') {
				stk.push('(');
			}
			else if (c == '[') {
				stk.push('[');
			}
			else if (c == ')') {
				if (stk.empty()) { res = false; break; }
				else {
					if (stk.top() == '[') { res = false; break; }
					else stk.pop();
				}
			}
			else if (c == ']') {
				if (stk.empty()) { res = false; break; }
				else {
					if (stk.top() == '(') { res = false; break; }
					else stk.pop();
				}
			}
		}
		while (!stk.empty()) {
			res = false;
			stk.pop();
		}
		cout << (res ? "yes" : "no") << "\n";
	}

	return 0;
}