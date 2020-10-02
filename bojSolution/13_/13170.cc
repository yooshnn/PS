#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	double n, k, p, w;
	cin >> n >> k >> p >> w;

	cout << ceil(p / w);

	return 0;
}