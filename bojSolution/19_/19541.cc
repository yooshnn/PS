#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> moim[100000];

bool corona[100001];
bool orig[100001];
bool check[100001];


int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
	cin >> N >> M; // 사람의 수 모임의 수
	for (int i = 0; i < M; ++i) {
		int k, a;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> a;
			moim[i].push_back(a);
		}
	}
	for (int i = 1; i <= N; ++i) {
		cin >> corona[i];
		orig[i] = corona[i];
	}
	for (int i = M-1; i >= 0; --i) {
		for (int j = 0; j < moim[i].size(); ++j) {
			if (orig[moim[i][j]] == 0) {
				for (int k = 0; k < moim[i].size(); k++) {
					orig[moim[i][k]] = 0;
				}
				j = moim[i].size() + 1;
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		check[i] = orig[i];
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < moim[i].size(); ++j) {
			if (check[moim[i][j]] == 1) {
				for (int k = 0; k < moim[i].size(); ++k) {
					check[moim[i][k]] = 1;
				}
				break;
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (check[i] == corona[i]) continue;
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= N; ++i) {
		cout << orig[i] << " ";
	}
	return 0;
}