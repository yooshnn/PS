#include <bits/stdc++.h>
using namespace std;

bool isdigit(char c) {
	return ('0' <= c && c <= '9');
}

bool wake = false;
int main() {
	string line; 
	while (getline(cin, line)) {
		if (wake) cout << "\n"; wake = true;
		vector<int> num;
		vector<char> oper;
		string rhs;

		int eqsign = 0;
		bool ent = true, neg = false, last = 0;
		for (char& c : line) {
			eqsign++;
			if (c == ' ') continue;
			if (c == '=') break;
			if (ent == true) {
				ent = false;
				if (c == '-' || c == '+') {
					neg = (c == '-');
					continue;
				}
			}
			if (isdigit(c)) {
				if (last == 1) {
					num[num.size() - 1] *= 10;
					num[num.size() - 1] += c - '0';
				}
				else {
					num.push_back(c - '0');
				}
				if (neg) {
					neg = false;
					num[num.size() - 1] *= -1;
				}
			}
			else {
				if (!ent) ent = true;
				oper.push_back(c);
			}
			last = isdigit(c);
		} ent = true;
		for (int i = eqsign; i < line.size(); ++i) {
			if (ent == true) {
				ent = false;
				while (line[i] == ' ') i++;
			}
			rhs.push_back(line[i]);
		}
		/*for (auto i : num) cout << i << " "; cout << "\n";
		for (auto i : oper) cout << i << " "; cout << "\n";
		cout << rhs << "\n";*/

		for (int i = 0; i < num.size(); ++i) {
			cout << num[i] << " ";
			if (i < num.size() - 1) cout << oper[i] << " ";
		}
		cout << "= " << rhs << "\n";

		while (num.size() > 1) {
			int pp = -1;
			for (int i = 0; i < oper.size(); ++i) {
				if (oper[i] == '*' || oper[i] == '/') {
					pp = i; break;
				}
				else if (oper[i] == '+' || oper[i] == '-') {
					if (pp == -1) pp = i;
				}
				else assert(0);
			}

			if (oper[pp] == '*') num[pp] *= num[pp + 1];
			else if (oper[pp] == '/') num[pp] /= num[pp + 1];
			else if (oper[pp] == '+') num[pp] += num[pp + 1];
			else if (oper[pp] == '-') num[pp] -= num[pp + 1];
			num.erase(num.begin() + pp + 1);
			oper.erase(oper.begin() + pp);

			for (int i = 0; i < num.size(); ++i) {
				cout << num[i] << " ";
				if (i < num.size() - 1) cout << oper[i] << " ";
			}
			cout << "= " << rhs << "\n";
		}
	}
}