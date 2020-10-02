#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int min(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	vector<tuple<int, int, int>> p{ make_tuple(0,0,0) };
	vector<tuple<int, int, int>> m{ make_tuple(0,0,0) };

	int tint[3];
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> tint[0] >> tint[1] >> tint[2];
		p.push_back(make_tuple(tint[0], tint[1], tint[2]));	// RGB ë³„ ê°€ê²© íŠœí”Œ
	}
	for (int i = 1; i <= N; ++i) {
		int temp1, temp2, temp3;
		temp1 = min(get<1>(m[i - 1]), get<2>(m[i - 1])) + get<0>(p[i]);
		temp2 = min(get<0>(m[i - 1]), get<2>(m[i - 1])) + get<1>(p[i]);
		temp3 = min(get<0>(m[i - 1]), get<1>(m[i - 1])) + get<2>(p[i]);
		m.push_back(make_tuple(temp1, temp2, temp3));
	}
	cout << min(min(get<0>(m[N]), get<1>(m[N])), get<2>(m[N]));

	return 0;
}