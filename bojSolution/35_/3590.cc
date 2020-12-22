#include <bits/stdc++.h>
using namespace std;

map<string, string> abbr;
set<string> ambiguous;

char lower(char c) {
    if ('A' <= c && c <= 'Z') return c + 32;
    else if ('a' <= c && c <= 'z') return c;
    return '#';
}
char upper(char c) {
    if ('A' <= c && c <= 'Z') return c;
    else if ('a' <= c && c <= 'z') return c - 32;
    return '#';
}

int isAbbr(string& s) {
    if (s.size() <= 2) return -2;
    int ret = 0;
    if (('A' <= s[0] && s[0] <= 'Z' || 'a' <= s[0] && s[0] <= 'z') &&
        ('A' <= s[s.size() - 1] && s[s.size() - 1] <= 'Z' || 'a' <= s[s.size() - 1] && s[s.size() - 1] <= 'z')) {
        for (int i = 1; i < s.size() - 1; ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                ret = (ret * 10) + (s[i] - '0');
            }
            else return -1;
        }
        return ret;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line, word;
    while (getline(cin, line)) {
        line.push_back('#');
        for (char c : line) {
            if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9') word.push_back(c);
            else {
                if (word.size() != 0) {
                    int req = isAbbr(word);
                    if (req == -2) {
                        cout << word;
                    }
                    else if (req == -1) {
                        cout << word;
                        string abbreviated = lower(word[0]) + to_string(word.size() - 2) + lower(word[word.size() - 1]);
                        if (abbr.find(abbreviated) == abbr.end()) abbr[abbreviated] = word;
                        else {
                            for (int i = 1; i < abbr[abbreviated].size() - 1; ++i) {
                                if (lower(word[i]) != lower(abbr[abbreviated][i])) {
                                    ambiguous.insert(abbreviated); break;
                                }
                            }
                        }
                    }
                    else {
                        string abbreviated = lower(word[0]) + to_string(req) + lower(word[word.size() - 1]);
                        if (abbr.find(abbreviated) == abbr.end() || ambiguous.find(abbreviated) != ambiguous.end()) {
                            cout << word;
                        }
                        else {
                            bool tt = (word[0] <= 'Z') && (word[word.size() - 1] <= 'Z');
                            cout << word[0];
                            for (int i = 1; i < abbr[abbreviated].size() - 1; ++i) {
                                if (tt) cout << (abbr[abbreviated][i] <= 'Z' ? char(abbr[abbreviated][i]) : char(abbr[abbreviated][i] - 32));
                                else cout << lower(abbr[abbreviated][i]);
                            }
                            cout << word[word.size() - 1];
                        }
                    }
                    word = "";
                }
                if (c != '#') cout << c;
            }
        }
        cout << "\n";
    }
    
}