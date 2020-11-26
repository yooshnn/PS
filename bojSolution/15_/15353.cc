#include <iostream>
using namespace std;

int A[100021], B[100021];


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string a, b; cin >> a >> b;
	for (int i = 0; i < a.size(); ++i) A[100020 - i] = a[a.size() - 1 - i] - '0';
	for (int i = 0; i < b.size(); ++i) B[100020 - i] = b[b.size() - 1 - i] - '0';

	int temp, carry = 0;
	for (int i = 0; i < max( (int)a.size(), (int)b.size() ); ++i) {
		temp = A[100020 - i] + B[100020 - i] + carry;
		A[100020 - i] = temp % 10;
		carry = temp / 10;
	}
	if (carry) cout << 1;

	for (int i = 100021 - max((int)a.size(), (int)b.size()); i < 100021; ++i) cout << A[i];
	
	return 0;
}