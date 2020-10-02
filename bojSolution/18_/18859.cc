#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool res = true;
int d;
int prv = 0, cnt = 0;
vector<int> v;
bool visit[402001];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		int input; cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	d = v[1] - v[0];

	if (d == 0) {
		cout << "No" << "\n";
		return 0;
	}

	int pos = 1, p0 = 0, pp = 0;
	while (pos < N) {
		pp = pos; // 마지막으로 쓴 index
		visit[pos] = true;
		int temp = find(v.begin() + pos + 1, v.end(), v[pos] + d) - v.begin();
		if (p0 == 0 && temp != pos + 1) p0 = pos + 1; // 처음 안 쓴 index
		pos = temp;
	}

	/*for (int i = 0; i < N; ++i) cout << visit[i] << " ";
	cout << "\n";*/

	prv = 0;
	cnt = 0;
	d = v[p0] - v[0];
	pos = p0 - 1;
	while (++pos < N) {
		if (visit[pos]) continue;
		if (v[pos] - v[prv] == d) {
			cnt++;
			prv = pos;
		}
		else {
			break;
		}
	}

	for (int i = 1; i < N; ++i) {
		if (visit[i] == 0 && cnt-- == 0) break;
		if (i == N - 1) {
			cout << "Yes" << "\n";
			return 0;
		}
	}

	// step 2
	visit[pp] = false;

	p0 = min(p0, pp);

	//cout << "pp: " << pp << "\np0: " << p0 << "\n";

	prv = 0;
	cnt = 0;
	d = v[p0] - v[0];
	pos = p0 - 1;
	while (++pos < N) {
		if (visit[pos]) continue;
		if (v[pos] - v[prv] == d) {
			cnt++;
			prv = pos;
		}
		else {
			break;
		}
	}

	for (int i = 1; i < N; ++i) {
		if (visit[i] == 0 && cnt-- == 0) break;
		if (i == N - 1) {
			cout << "Yes" << "\n";
			return 0;
		}
	}

	cout << "No" << "\n";
	//cout << (res ? "Yes" : "No") << "\n";

	return 0;
}