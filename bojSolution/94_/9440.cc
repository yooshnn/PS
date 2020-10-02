#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; ++i) {
			int input;
			cin >> input;
			pq.push(input);
		}
		int zeroCnt = 0, r = 0;
		while (pq.top() == 0) {
			pq.pop();
			zeroCnt++;
		}
		if (N % 2 == 1) {
			r += pq.top();
			pq.pop();
		}
		while (!pq.empty()) {
			r *= 10;
			r += pq.top();
			pq.pop();
			if (N % 2 == 1) while (zeroCnt-- > 0) pq.push(0);
			r += pq.top();
			pq.pop();
			if (N % 2 == 0) while (zeroCnt-- > 0) pq.push(0);
		}
		cout << r << "\n";
	}


	return 0;
}