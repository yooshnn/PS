#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int>v;
int res;

void groupThree(int, int);
void calc();

bool chosen[100]{ false, };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	groupThree(0, 0);
	cout << res;

	return 0;
}

void groupThree(int count, int ind) {
	if (count == 3) {
		calc();
	}
	else {
		for (int i = ind + 1; i < N; ++i) {
			if (chosen[i]) continue;
			chosen[i] = true;
			groupThree(count + 1, i);
			chosen[i] = false;
		}
	}
}

void calc() {
	int cardsum = 0, tick = 0;
	for (int i = 0; i < N; ++i) {
		if (chosen[i]) {
			cardsum += v[i];
			if (tick++ == 3) break;
		}
	}
	if (cardsum > M) return;
	if (cardsum > res) res = cardsum;
}