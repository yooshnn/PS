#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		string line; getline(cin, line);
		if (line == "***") break;
		for (int c = 0; c < line.length(); ++c) {
			cout << line[line.length() - 1 - c];
		}
		cout << "\n";
	}

	return 0;
}