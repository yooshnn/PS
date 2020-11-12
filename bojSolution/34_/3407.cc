#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> tup;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

vector<string> d {"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"};

bool bfs(string& s) {
    bool dup[50001]; fill(dup, dup + 50001, false);

    priority_queue<int, vector<int>, greater<int>> que;

    for (que.push(0); !que.empty(); que.pop()) {
        int cur = que.top();
        if (cur == s.size()) return true;
        for (string& c : d) {
            if (c.size() == 2 && s.size() - cur >= 2 && !dup[cur + 2] && s[cur] == c[0] && s[cur+1] == c[1]) {
                que.push(cur + 2);
                dup[cur + 2] = true;
            }
            else if (c.size() == 1 && s.size() - cur >= 1 && !dup[cur + 1] && s[cur] == c[0]) {
                que.push(cur + 1);
                dup[cur + 1] = true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int TEST; cin >> TEST; while (TEST--) {
        string s; cin >> s;
        cout << (bfs(s) ? "YES" : "NO") << "\n";
    }
}