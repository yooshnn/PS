#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <queue>
#include <deque>
using namespace std;

deque<long long> n;
deque<char> oper;

bool cmpWeight(char l, char r) {
	int lw = 1, rw = 1;
	if (l == '+' or l == '-') lw = 0;
	if (r == '+' or r == '-') rw = 0;
	if (lw != rw) return lw > rw;

	long long p = 0, q = 0;
	if (l == '+') p = n[0] + n[1];
	else if (l == '-') p = n[0] - n[1];
	else if (l == '*') p = n[0] * n[1];
	else if (l == '/') p = n[0] / n[1];
	if (r == '+') q = n[n.size() - 2] + n[n.size() - 1];
	else if (r == '-') q = n[n.size() - 2] - n[n.size() - 1];
	else if (r == '*') q = n[n.size() - 2] * n[n.size() - 1];
	else if (r == '/') q = n[n.size() - 2] / n[n.size() - 1];
	return p >= q;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	char input;
	long long curNo = 0;
	bool isFNeg = false, isF = true;
	while (cin >> input) {
		if (isF && input == '-') { isFNeg = true; isF = false; continue; }
		isF = false;
		if ('0' <= input && input <= '9') {
			curNo *= 10;
			curNo += (long long)input - '0';
		}
		else {
			n.push_back(curNo);
			curNo = 0;
			oper.push_back(input);
		}
	}n.push_back(curNo);
	if (isFNeg) { long long temp = n.front(); n.pop_front(); temp *= -1; n.push_front(temp); }
	
	while (!oper.empty()) {
		if (cmpWeight(oper.front(), oper.back())) {
			char curOper = oper.front(); oper.pop_front();
			long long curNo = n.front(); n.pop_front();
			if (curOper == '+') curNo += n.front();
			if (curOper == '-') curNo -= n.front();
			if (curOper == '*') curNo *= n.front();
			if (curOper == '/') curNo /= n.front();
			n.pop_front();
			n.push_front(curNo);
		}
		else {
			char curOper = oper.back(); oper.pop_back();
			long long curNo = n.back(); n.pop_back();
			if (curOper == '+') curNo = n.back() + curNo;
			if (curOper == '-') curNo = n.back() - curNo;
			if (curOper == '*') curNo = n.back() * curNo;
			if (curOper == '/') curNo = n.back() / curNo;
			n.pop_back();
			n.push_back(curNo);
		}
	}

	cout << n.front();

	return 0;
}