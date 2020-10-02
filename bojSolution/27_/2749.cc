#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct matrix {
	ll f[2][2];
}matrix;

matrix matrixProduct(matrix p, matrix q, ll m) {
	matrix ret;
	ret.f[0][0] = (p.f[0][0] * q.f[0][0] + p.f[0][1] * q.f[1][0]) % m;
	ret.f[0][1] = (p.f[0][0] * q.f[0][1] + p.f[0][1] * q.f[1][1]) % m;
	ret.f[1][0] = (p.f[1][0] * q.f[0][0] + p.f[1][1] * q.f[1][0]) % m;
	ret.f[1][1] = (p.f[1][0] * q.f[0][1] + p.f[1][1] * q.f[1][1]) % m;
	return ret;
}

matrix myPow(matrix a, ll b, ll m) {
	if (b == 1) return a;
	matrix ret, req = myPow(a, b / 2, m);

	ret = matrixProduct(req, req, m);
	if (b % 2 == 1) { ret = matrixProduct(ret, matrix{ 1,1,1,0 }, m); }
	/*cout << ret.f[0][0] << " " << ret.f[0][1] << "\n" << ret.f[1][0] << " " << ret.f[1][1] << "\n-\n";*/
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a, b, c; cin >> b; c = 1000000;
	matrix init{ 1, 1, 1, 0 };
	matrix req = myPow(init, b, c);

	cout << req.f[0][1];

	return 0;
}