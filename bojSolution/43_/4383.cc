#include <bits/stdc++.h>
using namespace std;

int main() {

	int l;

	while (cin >> l) {
		vector<bool> visit(l + 1, false);
		vector<int> num(l);
		for (int i = 0; i < l; ++i) cin >> num[i];

		for (int i = 0; i < l - 1; ++i) {
			if (abs(num[i] - num[i + 1]) <= l) visit[abs(num[i] - num[i + 1])] = true;
		}

		bool jolly = true;
		if (l > 1) {
			for (int i = 1; i < l; ++i) {
				if (!visit[i]) jolly = false;
			}
		}

		cout << (jolly ? "Jolly" : "Not jolly") << "\n";
	}
}