#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int INF = 1e6;

int res;
map<char, pii> K;
char f0, f1;
string s;

int getCost(char a, char b) {
    return abs(K[a].first - K[b].first) + abs(K[a].second - K[b].second);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    K['q'] = { 0, 0 }, K['w'] = { 0, 1 }, K['e'] = { 0, 2 }, K['r'] = { 0, 3 }, K['t'] = { 0, 4 }, K['y'] = { 0, 5 }, K['u'] = { 0, 6 }, K['i'] = { 0, 7 }, K['o'] = { 0, 8 }, K['p'] = { 0, 9 },
        K['a'] = { 1, 0 }, K['s'] = { 1, 1 }, K['d'] = { 1, 2 }, K['f'] = { 1, 3 }, K['g'] = { 1, 4 }, K['h'] = { 1, 5 }, K['j'] = { 1, 6 }, K['k'] = { 1, 7 }, K['l'] = { 1, 8 },
        K['z'] = { 2, 0 }, K['x'] = { 2, 1 }, K['c'] = { 2, 2 }, K['v'] = { 2, 3 }, K['b'] = { 2, 4 }, K['n'] = { 2, 5 }, K['m'] = { 2, 6 };

    cin >> f0 >> f1;
    cin >> s;

    for (char& c : s) {
        if (c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'p' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'b' || c == 'n' || c == 'm') {
            res += 1 + getCost(f1, c);
            f1 = c;
        }
        else {
            res += 1 + getCost(f0, c);
            f0 = c;
        }
    }

    cout << res;

}