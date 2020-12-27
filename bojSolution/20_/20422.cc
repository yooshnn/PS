#include <bits/stdc++.h>
using namespace std;

map<char, char> qilip;
void ins(string s1, string s2) {
    for (int i = 0; i < s1.length(); i++) {
        qilip[s1[i]] = s2[i];
    }
}

bool ok(char& c1, char& c2) {
    if (c1 == '#' && c2 == '#') return 1;
    return (qilip[c1] == c2);
}

vector<int> manacher(string src) {
    int srcLen = src.size(); src.resize(srcLen * 2 + 1, '#');
    for (int i = srcLen - 1; i >= 0; --i) src[i * 2 + 1] = src[i], src[i] = '#';

    int c = 0, r = 0, len = src.size();
    vector<int> ret(len, 0);
    for (int i = 0; i < len; ++i) {
        if (i & 1 && qilip[src[i]] != src[i]) continue;
        int sym = 2 * c - i;
        if (i < r) ret[i] = min(r - i, ret[sym]);
        while (i - ret[i] > 0 && i + ret[i] - 1 < len && ok(src[i - ret[i] - 1], src[i + ret[i] + 1])) ret[i]++;
        if (ret[i] + i > r) r = ret[i] + i, c = i;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ins("AEHIMOSTUVWXYZbdilmnopqruvwx0123578", "A3HIMO2TUVWXY5dbilmnoqp7uvwx01SEZr8");

    string str; cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'A')str[i] = 'A';
        else if (str[i] == 'B' || str[i] == 'b')str[i] = 'b';
        else if (str[i] == 'D' || str[i] == 'd')str[i] = 'd';
        else if (str[i] == 'e' || str[i] == 'E')str[i] = 'E';
        else if (str[i] == 'h' || str[i] == 'H')str[i] = 'H';
        else if (str[i] == 'i' || str[i] == 'I')str[i] = 'I';
        else if (str[i] == 'l' || str[i] == 'L')str[i] = 'l';
        else if (str[i] == 'M' || str[i] == 'm')str[i] = 'M';
        else if (str[i] == 'N' || str[i] == 'n')str[i] = 'n';
        else if (str[i] == 'O' || str[i] == 'o')str[i] = 'O';
        else if (str[i] == 'P' || str[i] == 'p')str[i] = 'p';
        else if (str[i] == 'Q' || str[i] == 'q')str[i] = 'q';
        else if (str[i] == 'R' || str[i] == 'r')str[i] = 'r';
        else if (str[i] == 'S' || str[i] == 's')str[i] = 'S';
        else if (str[i] == 'T' || str[i] == 't')str[i] = 'T';
        else if (str[i] == 'U' || str[i] == 'u')str[i] = 'U';
        else if (str[i] == 'V' || str[i] == 'v')str[i] = 'V';
        else if (str[i] == 'W' || str[i] == 'w')str[i] = 'W';
        else if (str[i] == 'X' || str[i] == 'x')str[i] = 'X';
        else if (str[i] == 'Y' || str[i] == 'y')str[i] = 'Y';
        else if (str[i] == 'Z' || str[i] == 'z')str[i] = 'Z';
        else if (str[i] < '0' || str[i]>'9') {
            cout << "-1"; return 0;
        }
        else if (str[i] == '4' || str[i] == '6' || str[i] == '9') {
            cout << "-1"; return 0;
        }
    }

    if (str.size() == 1) {
        if (qilip[str[0]] == str[0]) cout << str;
        else cout << str << qilip[str[0]];
        return 0;
    }


    int M = 0, lr = 0, pp;
    vector<int> pal = manacher(str);
    for (int i = 0; i < pal.size(); ++i) {
        if (pal[i] & 1 && qilip[str[i/2]] != str[i/2]) continue;
        if (i + pal[i] == pal.size() - 1 || i - pal[i] == 0) {
            if (pal[i] > M) {
                M = pal[i];
                lr = (i + pal[i] == pal.size() - 1 ? 1 : -1);
            }
        }
    }

    //cout << "M : " << M << ", lr : " << lr << "\n";

    if (M == 0) {
        if (qilip[str[0]] == str[0]) {
            for (int i = str.size() - 1; i >= 1; --i) {
                cout << qilip[str[i]];
            }
            cout << str;
        }
        else if (qilip[str[str.size() - 1]] == str[str.size() - 1]) {
            pp = str.size() - M;
            cout << str;
            for (int i = pp - 1 - 1; i >= 0; --i) cout << qilip[str[i]];
        }
        else {
            cout << str;
            for (int i = str.size() - 1; i >= 0; --i) cout << qilip[str[i]];
        }
    }
    else {
        if (lr == 1) {
            pp = str.size() - M;
            cout << str;
            for (int i = pp - 1; i >= 0; --i) cout << qilip[str[i]];
        }
        else {
            pp = M;
            for (int i = str.size() - 1; i >= pp; --i) {
                cout << qilip[str[i]];
            }
            cout << str;
        }
    }

}