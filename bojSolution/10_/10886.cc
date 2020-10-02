#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int cute[2]{ 0, 0 };
	int T, vote;
	cin >> T;

	while (T-- > 0) {
		cin >> vote;
		cute[vote]++;
	}
	if (cute[0] > cute[1]) cout << "Junhee is not cute!";
	else cout << "Junhee is cute!";

	return 0;
}