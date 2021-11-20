#include <bits/stdc++.h>
using namespace std;

int main() {	
	int n, a, b; cin >> n;
	cout << "? 1" << endl;
	cin >> a;
	cout << "? " << n << endl;
	cin >> b;
	if (a == b) cout << "! 0";
	else if (a > b) cout << "! -1";
	else cout << "! 1";
	cout.flush();
}
