#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Trie {
    unordered_map<char, Trie*> child;
    Trie* fail;
    bool isRet = false;

    void push(string& s) {
        Trie* cur = this;
        for (char const& c : s) {
            if (cur->child.find(c) == cur->child.end())
                cur->child[c] = new Trie;
            cur = cur->child[c];
            cur->fail = this;
        }
        cur->isRet = true;
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

    bool ask(string& s) {
        Trie* p = this;
        for (char& c : s) {
            while (p != this && p->child.find(c) == p->child.end()) p = p->fail;
            p = p->child[c];
            if (!p) p = this;
            if (p->isRet) return 1;
        }
        return 0;
    }

};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Trie* root = new Trie;

    int N, Q;
    string input;

    cin >> N; while (N--) {
        cin >> input; root->push(input);
    }
    root->build();
    cin >> Q; while (Q--) {
        cin >> input; cout << (root->ask(input) ? "YES" : "NO") << "\n";
    }

    return 0;
}