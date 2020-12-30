#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s; getline(cin, s);
	stack<char> word;
	bool tag = false;
	for (char c: s) {
		if (c == '<' || tag) {
			if (c == '<') {
			while (!word.empty()) {
				cout << word.top();
				word.pop();
			}
			tag = true;
			}
			if (c == '>') tag = false;
			cout << c;
			continue;
		}
		if (c == ' ') {
			while (!word.empty()) {
				cout << word.top();
				word.pop();
			}
			cout << c;
		}
		else {
			word.push(c);
		}
	}
	while (!word.empty()) {
		cout << word.top(); word.pop();
	}
}