#include <iostream>
#include <stack>
using namespace std;

int K, input, res;
stack<int>stk;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> K;
	while (K--) {
		cin >> input;
		if (input == 0) stk.pop();
		else stk.push(input);
	}
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}

	cout << res;

	return 0;
}