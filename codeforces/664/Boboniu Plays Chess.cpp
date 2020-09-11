#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool visit[101][101];

bool orun = true;
int N, M, r, c;
int vcount;

void prnt() {
    cout << r << " " << c << "\n";
}

void move(int r_, int c_) {
    r = r_;
    c = c_;
    if (!visit[r][c]) prnt();
    visit[r][c] = true;
}

void to_tl() {
    move(1, c);
    move(r, 1);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M >> r >> c;
    prnt();
    visit[r][c] = true;
    to_tl();
    while (1) {
        if (orun) {
            if (c + 1 <= M) move(r, c + 1);
            else {
                orun = false;
                if (r + 1 <= N) move(r + 1, c);
                else break;
            }
        }
        else {
            if (c - 1 > 0) move(r, c - 1);
            else {
                orun = true;
                if (r + 1 <= N) move(r + 1, c);
                else break;
            }
        }
    }

    return 0;
}