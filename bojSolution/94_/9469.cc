#include <iostream>
#include <iomanip>
using namespace std;

int p;
int n;
double d, a, b, f;

int main() {
	cin >> p;
	while (p--) {
		cin >> n >> d >> a >> b >> f;
		cout << fixed << setprecision(6) << n << " " << d / (a + b) * f << "\n";
	}
	return 0;
}