#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<long long int>v{ 100000,100000,100000,1,100000,1 };
	int n;
	cin >> n;

	for (int i = 6; i <= n; ++i) {
		v.push_back(min(v[i - 3], v[i - 5]) + 1);
	}
	if (v[n] >= 100000) cout << "-1";
	else cout << v[n];

	return 0;
}