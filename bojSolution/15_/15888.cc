#include <bits/stdc++.h>
using namespace std;

set<int> s {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int a, b, c; cin >> a >> b >> c;

	vector<int> res;
	for (int i = -1000; i <= 1000; ++i) {
		if (a*i*i + b*i + c == 0) res.push_back(i);
	}

	int g = 0;
	if (res.size() == 2) {
		if (s.find(res[0]) != s.end()) g += 1;
		if (s.find(res[1]) != s.end()) g += 1;
	}

	if (g == 2) {
		cout << "이수근";
	}
	else if (res.size() == 2) {
		cout << "정수근";
	}
	else {
		cout << "둘다틀렸근";
	}

	//cout << endl; system("pause");
}