#include <iostream>
#include <string>
#include <queue>
using namespace std;
queue<int> q;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		string cm = "";
		int pushnum;
		cin >> cm;
		if (cm == "push") {
			cin >> pushnum;
			q.push(pushnum);
			continue;
		}
		else if (cm == "pop") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cm == "size") {
			cout << q.size() << "\n";
		}
		else if (cm == "empty") {
			if (q.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (cm == "front") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (cm == "back") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
	return 0;
}