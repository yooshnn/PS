#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tup;

struct Requirement {
	set<string> request;
	double price; int match; string who;

	Requirement() {
		price = 1e12;
		match = -1;
		who = "";
	}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int REQ, PROP, RFP = 1;

	while (cin >> REQ >> PROP) {
		if (REQ == 0) break;
		cin.ignore();
		if (RFP != 1) cout << "\n";
		Requirement R;
		for (int i = 0; i < REQ; ++i) {
			string req; getline(cin, req);
			R.request.insert(req);
		}
		for (int i = 0; i < PROP; ++i) {
			string who; getline(cin, who);
			double price; int cnt, match = 0; cin >> price >> cnt;
			cin.ignore();
			while (cnt--) {
				string req; getline(cin, req);
				while (req.size() != 0 && req[req.size()-1] == ' ') req.pop_back();
				if (R.request.find(req) != R.request.end()) match++;
			}
			if (match > R.match) {
				R.match = match;
				R.price = price;
				R.who = who;
			}
			else if (match == R.match && price < R.price) {
				R.match = match;
				R.price = price;
				R.who = who;
			}
		}
		cout << "RFP #" << RFP++ << "\n" << R.who << "\n";
	}


    return_0;
}