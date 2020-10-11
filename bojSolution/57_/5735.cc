#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Trie {
    unordered_map<char, Trie*> child;
    Trie* fail;
    int isRet = false;

    void push(string& s) {
        Trie* cur = this;
        for (char const& c : s) {
            if (cur->child.find(c) == cur->child.end())
                cur->child[c] = new Trie;
            cur = cur->child[c];
            cur->fail = this;
        }
        cur->isRet = s.length();
    }

    void build() {
        queue<Trie*> Q;
        for (auto const& p : child)
            if (p.second) Q.push(p.second);
        while (!Q.empty()) {
            Trie* cur = Q.front(); Q.pop();
            for (auto const& c : cur->child) {
                Trie* p = cur->fail;
                while (p != this && p->child.find(c.first) == p->child.end()) p = p->fail;
                p = p->child[c.first];
                if (!p) p = this;
                c.second->fail = p;
                if (p->isRet) c.second->isRet = true;
                Q.push(c.second);
            }
        }
    }

    int ask(string& s) {
        int ret = 0;
        Trie* p = this;
        for (char& c : s) {
            while (p != this && p->child.find(c) == p->child.end()) p = p->fail;
            p = p->child[c];
            if (!p) p = this;
            if (p->isRet) {
                ret++;
                p = this;
            }
        }
        return ret;
    }

};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (1) {
        Trie* root = new Trie;

        int N, Q, res = 0;
        string input;

        cin >> N >> Q;
        if (N == 0 && Q == 0) break;
        while (N--) {
            cin >> input; root->push(input);
        }

        root->build();
        cin.ignore(); cin.clear();

        while (Q--) {
            getline(cin, input);
            res += root->ask(input);
        }
        cout << res << "\n";

        delete root;
    }

    return 0;
}