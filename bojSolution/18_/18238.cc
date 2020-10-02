#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int dist[26][26];
int res = 0;
string s;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			dist[i][j] = 13 - abs(13 - abs(j - i));
		}
	}

	cin >> s;
	res = dist[0][s[0] - 'A'];
	for (int i = 1; i < s.size(); ++i) {
		res += dist[s[i - 1]-'A'][s[i]-'A'];
	}

	cout << res;

	return 0;
}