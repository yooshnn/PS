#include <bits/stdc++.h>
using namespace std;

queue<int> que;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, t; cin >> N;
	while (1) {
		cin >> t; if (t == -1) break;
		if (t == 0) que.pop();
		else {
			if (que.size() < N) que.push(t);
		}
	}

	if (que.empty()) cout << "empty";
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}

	//cout << endl; system("pause");
}