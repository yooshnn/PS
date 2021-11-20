#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 0)break;
		if (a + b <= c || a + c <= b || b + c <= a) {
			cout << "Invalid\n";
		}
		else if (a == b && b == c)cout << "Equilateral\n";
		else if (a == b && b != c)cout << "Isosceles\n";
		else if (a == c && b != c)cout << "Isosceles\n";
		else if (c == b && a != c)cout << "Isosceles\n";
		else cout << "Scalene\n";
	}
}