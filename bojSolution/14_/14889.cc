#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<vector<int>>vi;
bool team[20]{ false, };

int res = 99999999;

void setTeam(int, int);
void calc();

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	cin >> N;
	vector<int>vj;
	for (int i = 0; i < N; ++i) {
		vj.clear();
		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;
			vj.push_back(temp);
		}
		vi.push_back(vj);
	}

	setTeam(0, 0);
	cout << res;

	return 0;
}

void setTeam(int peep, int ind) {
	if (peep == N / 2) {
		calc();
	}
	else {
		for (int i = ind + 1; i < N; ++i) {
			if (team[i] == true) continue;
			team[i] = true;
			setTeam(peep + 1, i);
			team[i] = false;
		}
	}
}

void calc() {
	vector<int>start;
	vector<int>link;
	for (int i = 0; i < N; ++i) {
		if (team[i]) start.push_back(i);
		else link.push_back(i);
	}
	int temp = 0;
	for (int i = 0; i < N / 2; ++i) {
		for (int j = i + 1; j < N / 2; ++j) {
			temp += vi[start[i]][start[j]] + vi[start[j]][start[i]] - vi[link[i]][link[j]] - vi[link[j]][link[i]];
		}
	}
	res = min(res, abs(temp));
}