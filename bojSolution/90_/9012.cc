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

	cin >> K;
	cin.ignore();
	cin.clear();

	while (K--) {
		res = true;
		getline(cin, input);
		for (char c : input) {
			if (c == '(') {
				stk.push('P');
			}
			else if (c == ')') {
				if (stk.empty()) { res = false; break; }
				else stk.pop();
			}
		}
		while (!stk.empty()) {
			res = false;
			stk.pop();
		}
		cout << (res ? "YES" : "NO") << "\n";
	}

	return 0;
}