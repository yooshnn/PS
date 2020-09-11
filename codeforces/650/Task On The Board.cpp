#include <bits/stdc++.h>
using namespace std;
int T;

string s;
int m;
int b[50];

int cc[26];
vector<vector<int> > v;
char res[50];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        v.clear();
        memset(cc, 0, sizeof(cc));

        cin >> s >> m;
        for (int i = 0; i < m; ++i) cin >> b[i];
        for (int i = 0; i < s.length(); ++i) { cc[s[i] - 'a']++; }

        while (1) {
            vector<int> temp;
            bool found = false;
            for (int i = 0; i < m; ++i) {
                if (b[i] == 0) {
                    temp.push_back(i);
                    found = true;
                }
            }
            if (!found) break;
            v.push_back(temp);
            //for (auto z : temp) cout << z << " ";
            for (int i = 0; i < m; ++i) {
                if (b[i] == 0) {
                    b[i] = -1;
                }
                else {
                    for (int j : temp) b[i] -= abs(j - i);
                }
            }
        }

        int ptr = 25;
        for (vector<int> cur : v) {
            while (!(cc[ptr] >= cur.size())) {
                //cout << "ptr : " << cc[ptr] << " , cur.size(): " << cur.size() << "\n";;
                ptr--;
            }
            for (int i : cur) {
                res[i] = char('a' + ptr);
                //cout << ptr;
            }
            ptr--;
        }

        for (int i = 0; i < m; ++i) {
            cout << res[i];
        }cout << "\n";
    }

    return 0;
}