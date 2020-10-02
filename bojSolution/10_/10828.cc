#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> s;
int main() {
	int T;
	cin >> T;

	while (T-- > 0) {
		string cm = "";
		int pushnum;
		cin >> cm;
		if (cm == "push") {
			cin >> pushnum;
			s.push(pushnum);
			continue;
		}
		else if (cm == "pop") {
			if (s.empty()) {
				cout << "-1\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (cm == "size") {
			cout << s.size() << "\n";
		}
		else if (cm == "empty") {
			if (s.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (cm == "top") {
			if (s.empty()) {
				cout << "-1\n";
			}
			else {
				cout << s.top() << "\n";
			}
		}
	}
	return 0;
}