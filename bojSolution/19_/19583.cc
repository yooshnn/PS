#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int S, E, Q;
int res;
int state = 0;
map<string, int> chat;

int parseTime(string s) {
	return (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[3] - '0') * 10 + (s[4] - '0');
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	string input;
	cin >> input; S = parseTime(input);
	cin >> input; E = parseTime(input);
	cin >> input; Q = parseTime(input);

	string time_, name; int time;
	while (cin >> time_) { cin >> name;
		time = parseTime(time_);
		if (E <= time && time <= Q) state = 1;
		else if (time > S) continue;
		if (state == 0) {
			chat[name] += 1;
		}
		else if (state == 1) {
			if (chat[name] > 0) {
				res++;
				// cout << "*" << name << "\n";
				chat[name] = 0;
			}
		}
	}

	cout << res;

	return 0;
}