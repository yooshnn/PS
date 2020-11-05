#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int TEST; cin >> TEST; while (TEST--) {
        string s; cin >> s; 
        crope r(s.c_str());

        while (1) {
            string oper, input; int p, q; cin >> oper;
            if (oper == "I") {
                cin >> input >> p;
                if (p == r.length()) r.append(input.c_str());
                else r.insert(p, input.c_str());
            }
            else if (oper == "P") {
                cin >> p >> q;
                cout << r.substr(p, q-p+1) << "\n";
            }
            else {
                break;
            }
        }
    }
}