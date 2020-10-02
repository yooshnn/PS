#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque<int> q;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		string cm = "";
		int pushnum;
		cin >> cm;
		if (cm == "push_front") {
			cin >> pushnum;
			q.push_front(pushnum);
			continue;
		}
		else if (cm == "push_back") {
			cin >> pushnum;
			q.push_back(pushnum);
			continue;
		}
		else if (cm == "pop_front") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (cm == "pop_back") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.back() << "\n";
				q.pop_back();
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