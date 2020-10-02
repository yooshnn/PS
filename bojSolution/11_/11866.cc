#include <iostream>
using namespace std;

bool jo[5001]{ false, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N, K, point = 0, escape = 0;
	cin >> N >> K;

	cout << "<";
	for (int i = 0; i < N; ++i) {
		while (escape < K) {
			point++;
			if (point > N) point = 1;
			if (jo[point] == false) {
				escape++;
			}
		}
		jo[point] = true;
		cout << point;
		escape = 0;

		if (i < N - 1) cout << ", ";
		else cout << ">";
	}

	return 0;
}