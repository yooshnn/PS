#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;

int N;
vector<string> cow{ "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue" };
multimap<string, string> stmt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string cow1, cow2;
		cin >> cow1 >> cow2 >> cow2 >> cow2 >> cow2 >> cow2;
		stmt.insert({ cow1, cow2 });
	}
	
	do {
		bool good = true;
		for (int i = 0; i < 8; ++i) {
			for (auto& p : stmt) {
				if (cow[i] == p.first) {
					int valid = 2;
					if (i == 0 || cow[i - 1] != p.second) valid -= 1;
					if (i == 7 || cow[i + 1] != p.second) valid -= 1;
					if (valid == 0) good = false;
				}
			}
		}
		if (good) {
			for (string& s : cow) cout << s << "\n";
			break;
		}
	} while (next_permutation(cow.begin(), cow.end()));
}