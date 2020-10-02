#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int N;
int score;

vector<string>v(16);
vector<vector<string>>p(16);
bool visit[16];

string sortedString(string str) {
	vector<char>cv;
	for (int i = 0; i < str.size(); ++i) cv.push_back(str[i]);
	sort(cv.begin(), cv.end());
	string ret = "";
	for (int i = 0; i < str.size(); ++i) ret += cv[i];
	return ret;
}

void solve(int beg, int scr, string history) {
	visit[beg] = true;
	if (find(p[beg].begin(), p[beg].end(), history) != p[beg].end()) {
		return;
	}
	p[beg].push_back(history);

	int mylen = v[beg].length();
	for (int i = 0; i < N; ++i) {
		if (visit[i]) continue;
		if (v[beg].back() == v[i].front()) {
			solve(i, scr + mylen, sortedString(history + to_string(i)));
		}
	}
	visit[beg] = false;
	score = max(score, scr + mylen);
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N;
	cin.clear();
	cin.ignore();
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < N; ++i) {
		memset(visit, false, sizeof(visit));
		solve(i, 0, to_string(i));
	}

	cout << score;

	return 0;
}