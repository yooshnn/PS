#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<long long int>v{ 0,1,2 };
	int n;
	cin >> n;

	if (n >= 2) {
		for (int i = 3; i <= n; ++i) {
			v.push_back((v[i - 2] + v[i - 1])%10007);
		}
		cout << v.back();
	}
	else {
		cout << v[n];
	}
	return 0;
}