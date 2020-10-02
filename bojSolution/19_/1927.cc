#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int T, input;
	cin >> T;
	while (T-- > 0) {
		cin >> input;
		if (input == 0) {
			if (pq.empty()) {
				cout << "0\n";
				continue;
			}
			cout << 2147483648 - pq.top() << "\n";
			pq.pop();
			continue;
		}
		pq.push(2147483648 - input);
	}

	return 0;
}