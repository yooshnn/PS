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
			cout << pq.top() << "\n";
			pq.pop();
			continue;
		}
		pq.push(input);
	}

	return 0;
}