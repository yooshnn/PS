#include <iostream>
#include <vector>
#include <map>
using namespace std;

int root[222];

int memCnt;
bool res = true;

int search(int);
void merge(int, int);


int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	int testCase; cin >> testCase;
	for (int testcase = 1; testcase <= testCase; ++testcase) {
		for (int i = 1; i < 222; ++i) root[i] = i;
		memCnt = 0;
		map<int, vector<int>> enemy;
		map<string, int> id;

		string n1, n2;
		int pairNo; cin >> pairNo;

		for (int pairno = 1; pairno <= pairNo; ++pairno) {
			cin >> n1 >> n2;
			int i1, i2;
			if (id.find(n1) == id.end()) {
				memCnt++;
				id[n1] = memCnt;
				i1 = memCnt;
			}
			else { i1 = id[n1]; }
			if (id.find(n2) == id.end()) {
				memCnt++;
				id[n2] = memCnt;
				i2 = memCnt;
			}
			else { i2 = id[n2]; }

			enemy[i1].push_back(i2);
			enemy[i2].push_back(i1);
		}
		
		for (int i = 1; i <= memCnt; ++i) {
			int ee = search(enemy[i][0]);
			for (int j = 1; j < enemy[i].size(); ++j) {
				merge(ee, enemy[i][j]);
			}
		}

		res = true;
		for (int i = 1; i <= memCnt; ++i) {
			for (int j = 0; j < enemy[i].size(); ++j) {
				if (i == enemy[i][j]) continue;
				if (search(i) == search(enemy[i][j])) {
					res = false;
					i = memCnt + 1;
					break;
				}
			}
		}

		cout << "Case #" << testcase << ": " << (res ? "Yes" : "No") << "\n";

		/*cout << "***\n";
		for (int i = 1; i <= memCnt; ++i) {
			cout << i << "'s enemy : ";
			for (int j : enemy[i]) cout << j << " ";
			cout << "\n";
		}

		cout << "***\n";
		for (int x = 1; x <= memCnt; ++x) {
			cout << x << " : ";
			for (int i = 0; i < 222; ++i) {
				if (root[i] == x) cout << i << " ";
			}cout << "\n";
		}*/
	}

	return 0;
}

int search(int target) {
	if (target == root[target]) return target;
	root[target] = search(root[target]);
	return root[target];
}
void merge(int a, int b) {
	a = search(a); b = search(b);
	if (a == b) return;
	root[b] = a;
}