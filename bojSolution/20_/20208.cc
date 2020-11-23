#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Home {
    int r, c;
    Home() {}
    Home(int R, int C) {
        r = R, c = C;
    }
    int dist(int R, int C) {
        return abs(R - r) + abs(C - c);
    }
} home;

struct Milk {
    int r, c;
    Milk() {}
    Milk(int R, int C) {
        r = R, c = C;
    }
    int dist(int R, int C) {
        return abs(R - r) + abs(C - c);
    }
} milk[10];

int N, M, H;
int milkCnt = 0;

int solve(vector<int>& route) {
    int ret = 0;
    int hp = M;

    if (milk[route[0]].dist(home.r, home.c) > hp) return 0;
    hp += -milk[route[0]].dist(home.r, home.c) + H;
    if (home.dist(milk[route[0]].r, milk[route[0]].c) <= hp) ret = 1;

    for (int i = 1; i < milkCnt; ++i) {
        if (milk[route[i]].dist(milk[route[i - 1]].r, milk[route[i - 1]].c) > hp) break;
        hp += -milk[route[i]].dist(milk[route[i - 1]].r, milk[route[i - 1]].c) + H;

        if (home.dist(milk[route[i]].r, milk[route[i]].c) <= hp) ret = max(ret, i + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> H;

    int input;
    for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
        cin >> input;
        if (input == 2) {
            milk[milkCnt++] = Milk(r, c);
        }
        if (input == 1) {
            home = Home(r, c);
        }
    }

    if (milkCnt == 0) {
        cout << 0;
        return 0;
    }

    vector<int> route;
    for (int i = 0; i < milkCnt; ++i) route.push_back(i);

    int res = 0;
    do {
        res = max(res, solve(route));
    } while (next_permutation(route.begin(), route.end()));

    cout << res;
}