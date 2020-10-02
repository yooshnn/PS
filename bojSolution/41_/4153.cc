#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	string r[2]{ "wrong","right" };
	vector<int>num;
	while (1) {
		int input[3];
		cin >> input[0] >> input[1] >> input[2];
		if (input[0] == 0) break;
		num.push_back(input[0]);
		num.push_back(input[1]);
		num.push_back(input[2]);
		sort(num.begin(), num.end());
		cout << r[ pow(num[0],2)+pow(num[1],2) == pow(num[2],2) ] << "\n";
		num.erase(num.begin(), num.end());
	}

	return 0;
}