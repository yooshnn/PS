#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) cout << "*";
	else {
		vector<bool>li(4 * n - 3);
		vector<vector<bool>>v(4 * n - 1, li);

		int y = n * 2;
		int x = y - 2;
		v.at(y).at(x) = true;

		int dist = 2;
		while (1) {
			try {
				for (int i = 0; i < dist; ++i) {
					y -= 1;
					v.at(y).at(x) = true;
				}
				for (int i = 0; i < dist; ++i) {
					x += 1;
					v.at(y).at(x) = true;
				}
				dist += 2;
				for (int i = 0; i < dist; ++i) {
					y += 1;
					v.at(y).at(x) = true;
				}
				for (int i = 0; i < dist; ++i) {
					x -= 1;
					v.at(y).at(x) = true;
				}
				dist += 2;
			}
			catch (out_of_range) {
				break;
			}
		}

		for (int i = 0; i < 4 * n - 1; ++i) {
			if (i != 1) {
				for (int j = 0; j < 4 * n - 3; ++j) {
					if (v[i][j]) cout << "*";
					else cout << " ";
				}
			}
			else {
				cout << "*";
			}
			if (i < 4 * n - 2) { cout << "\n"; }
		}
	}

	return 0;
}