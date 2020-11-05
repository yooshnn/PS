#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    crope r;
    int it = 0;

    int t; cin >> t; while (t--) {
        string oper; int v; cin >> oper;
        if (oper == "Insert") {
            cin >> v;
            int cnt = 0;
            string input;
            cin.ignore(); cin.clear();
            while (cnt < v) {
                getline(cin, input);
                r.insert(it + cnt, input.c_str());
                cnt += input.length();
            }
        }
        else if (oper == "Move") {
            cin >> v;
            it = v;
        }
        else if (oper == "Delete") {
            cin >> v;
            r = r.substr(0, it) + r.substr(it + v, r.length());
        }
        else if (oper == "Get") {
            cin >> v;
            cout << r.substr(it, v) << "\n";
            // for (int i = it; i < it + v; ++i) cout << r.at(i);
        }
        else if (oper == "Prev") {
            it -= 1;
        }
        else if (oper == "Next") {
            it += 1;
        }
    }
}