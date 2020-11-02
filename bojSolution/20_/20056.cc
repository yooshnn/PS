#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
struct Fire;

bool DEBUG = false;

int N, M, K;
vector<Fire> fires;
map<pii, vector<Fire>> fm;

inline int mod(int n) {
	if (n >= 0) return n % N;
	return ((-n / N + 1) * N + n) % N;
}

struct Fire {
	int r, c, m, s, d;
	Fire() { r = c = m = s = d = -1; }
	Fire(int R, int C, int M, int S, int D) {
		r = R, c = C, m = M, s = S, d = D;
	}

	void set(int R, int C, int M, int S, int D) {
		r = R, c = C, m = M, s = S, d = D;
	}
	bool empty() {
		return (d == -1);
	}
	void run() {
		int nr = r, nc = c;
		if (d == 0) nr -= s;
		if (d == 1) nr -= s, nc += s;
		if (d == 2) nc += s;
		if (d == 3) nr += s, nc += s;
		if (d == 4) nr += s;
		if (d == 5) nr += s, nc -= s;
		if (d == 6) nc -= s;
		if (d == 7) nr -= s, nc -= s;
		
		nr = mod(nr); nc = mod(nc);
		/*if (nr <= 0) nr = N; if (nr >= N + 1) nr = 1;
		if (nc <= 0) nc = N; if (nc >= N + 1) nc = 1;*/

		if (DEBUG) cout << "moved to " << nr << " " << nc << "\n";
		fm[{nr, nc}].emplace_back(nr, nc, m, s, d);
	}
};

void doMagic() {
	fires.clear();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (fm[{i, j}].size() == 0) continue;
			else if (fm[{i, j}].size() == 1) {
				if (DEBUG) cout << "only 1 at " << i << " " << j << "\n";
				fires.emplace_back(fm[{i, j}][0].r, fm[{i, j}][0].c, fm[{i, j}][0].m, fm[{i, j}][0].s, fm[{i, j}][0].d);
			}
			else {
				int mSum = 0, sSum = 0, is0246 = 0;
				for (Fire& f : fm[{i, j}]) {
					mSum += f.m; sSum += f.s;
					if (is0246 == -1) continue;
					else if (is0246 == 0) is0246 = (f.d % 2 == 0 ? 2 : 1);
					else if (is0246 == 2) is0246 = (f.d % 2 == 0 ? 2 : -1);
					else if (is0246 == 1) is0246 = (f.d % 2 == 1 ? 1 : -1);
				}
				if (DEBUG) cout << "mSum, sSum, size : " << mSum << " " << sSum << " " << fm[{i, j}].size() << "\n";
				if (mSum/5 > 0) {
					fires.emplace_back(i, j, mSum / 5, sSum / fm[{i, j}].size(), (is0246 > 0 ? 0 : 1));
					fires.emplace_back(i, j, mSum / 5, sSum / fm[{i, j}].size(), (is0246 > 0 ? 2 : 3));
					fires.emplace_back(i, j, mSum / 5, sSum / fm[{i, j}].size(), (is0246 > 0 ? 4 : 5));
					fires.emplace_back(i, j, mSum / 5, sSum / fm[{i, j}].size(), (is0246 > 0 ? 6 : 7));
				}
			}
		}
	}
	for (auto& i : fm) {
		i.second.clear();
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	int r, c, m, s, d;
	for (int i = 0; i < M; ++i) {
		cin >> r >> c >> m >> s >> d;
		fires.emplace_back(r-1, c-1, m, s, d);
	}

	while (K--) {
		for (auto& f : fires) f.run();
		doMagic();
		if (DEBUG) cout << " * \n";
	}
	
	int res = 0;
	for (auto f : fires) {
		if (DEBUG) cout << f.r << " " << f.c << " " << f.m << " " << f.s << " " << f.d << "\n";
		res += f.m;
	}if (DEBUG) cout << "\n";

	cout << res;
}