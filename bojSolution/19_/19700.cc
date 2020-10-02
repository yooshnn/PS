#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
priority_queue<pii> stu;
deque<int> grp;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int h, k; cin >> h >> k;
		stu.push({ h, k });
	}
	
	while (!stu.empty()) {
		int cur = stu.top().second; stu.pop();

		if (grp.size() == 0) grp.push_back(1);
		else {
			int req = lower_bound(grp.begin(), grp.end(), cur) - grp.begin();
			if (req == 0) {
				grp.push_front(1);
				//cout << cur;
			}
			else {
				grp[req - 1]++;
			}
		}
	}

	cout << grp.size();

	return 0;
}