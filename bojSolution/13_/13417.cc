#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<char> q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int T, N;
	cin >> T;
	while (T-- > 0) {
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			char cha;
			cin >> cha;
			q.push(cha);
		}
		string res = "";
		res += q.front();
		q.pop();
		for (int i = 1; i <= N; ++i) {
			while (!q.empty()) {
				if (res[0] < q.front()) {
					res += q.front();
				}
				else {\
					res = q.front() + res;
				}
				q.pop();
			}
		}
		cout << res << "\n";
	}
	return 0;
}