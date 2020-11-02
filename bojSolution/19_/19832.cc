#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int depth = 0;
multiset<string> rec[100000];
unordered_map<string, stack<int>> V;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string oper;
	while (cin >> oper) {
		if (oper == "{") {
			depth++;
			continue;
		}
		if (oper == "}") {
			for (auto& p : rec[depth]) {
				//cout << "V[" << p << "].size() == " << V[p].size() << "\n";
				if (!V[p].empty()) V[p].pop();
				//cout << "V[" << p << "].size() == " << V[p].size() << "\n";
			}
			rec[depth].clear();
			depth--;
			//cout << "\n";
			continue;
		}

		string p = "", q = ""; bool eqFound = false;
		for (char& c : oper) {
			if (c == '=') { eqFound = true; continue; }
			if (eqFound) q += c; else p += c;
		}
		if ('a' <= q[0] && q[0] <= 'z') {
			if (V[q].empty()) V[p].push(0);
			else V[p].push(V[q].top());
			cout << V[p].top() << "\n";
		}
		else {
			V[p].push(stoi(q));
		}
		rec[depth].insert(p);
	}
}