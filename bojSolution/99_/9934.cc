#include <bits/stdc++.h>
using namespace std;

int pos;
vector<int> l;
vector<int> res[10];

struct Tree {
    Tree* par;
    Tree* left, * right;
    int data;

    Tree() {
        par = nullptr;
        left = nullptr;
        right = nullptr;
        data = 0;
    }

    void gen(int height) {
        if (--height > 0) {
            left = new Tree;
            right = new Tree;
            right->par = left->par = this;
            left->gen(height);
            right->gen(height);
        }
    }

    void log(int depth) {
        if (left && left->data == 0) left->log(depth + 1);
        res[depth].push_back(l[pos++]);
        if (right && right->data == 0) right->log(depth + 1);
    }
};

int main() {
    int k, t; cin >> k;
    Tree T;
    T.gen(k);
    while (cin >> t) {
        l.push_back(t);
    }
    T.log(0);
    for (int i = 0; i < k; ++i) {
        for (int c : res[i]) cout << c << " ";
        cout << "\n";
    }
}