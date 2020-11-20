#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dirConv(int face, char c) {
    if (c == 'F') return face;
    if (c == 'B') return (face + 2) % 4;
    if (c == 'R') return (face + 3) % 4;
    return (face + 1) % 4;
}

pii conv(char dir, pii cur) {
    if (dir == 0) return { cur.first, cur.second + 1 };
    if (dir == 1) return { cur.first - 1, cur.second };
    if (dir == 2) return { cur.first, cur.second - 1 };
    return { cur.first + 1, cur.second };
}

struct Bessie {
    int face, tripped;
    int rec[4];
    bool s[4];
    pii FL, FR, RL, RR;
    pii* Feet[4] = { &FL, &FR, &RL, &RR };

    Bessie() {
        tripped = 0;
        face = 1;
        fill(&s[0], &s[0] + 4, 0);
        FL = { 0, 0 }, FR = { 0, 1 }, RL = { 1, 0 }, RR = { 1, 1 };
        record();
    }

    bool trip() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i == j) continue;
                if (Feet[i]->first == Feet[j]->first && Feet[i]->second == Feet[j]->second) return true;
            }
        }
        return false;
    }
    void record() {
        for (int i = 0; i < 4; ++i) {
            if (!s[0] || rec[0] < Feet[i]->first) {
                rec[0] = Feet[i]->first;
                s[0] = true;
            }
            if (!s[1] || rec[1] < Feet[i]->second) {
                rec[1] = Feet[i]->second;
                s[1] = true;
            }
            if (!s[2] || rec[2] > Feet[i]->first) {
                rec[2] = Feet[i]->first;
                s[2] = true;
            }
            if (!s[3] || rec[3] > Feet[i]->second) {
                rec[3] = Feet[i]->second;
                s[3] = true;
            }
        }
    }
    void pivot(string feet) {
        pii c;
        if (feet == "FL") c = FL; if (feet == "FR") c = FR; if (feet == "RL") c = RL; if (feet == "RR") c = RR;
        FL = { c.first + FL.second - c.second, c.second -FL.first + c.first };
        FR = { c.first + FR.second - c.second, c.second -FR.first + c.first };
        RL = { c.first + RL.second - c.second, c.second -RL.first + c.first };
        RR = { c.first + RR.second - c.second, c.second -RR.first + c.first };
        face = (3 + face) % 4;
        record();
        if (trip()) tripped = true;
    }
    void step(string feet, char dir) {
        if (feet == "FR") FR = conv(dirConv(face, dir), FR);
        if (feet == "FL") FL = conv(dirConv(face, dir), FL);
        if (feet == "RR") RR = conv(dirConv(face, dir), RR);
        if (feet == "RL") RL = conv(dirConv(face, dir), RL);
        record();
        if (trip()) tripped = true;
    }
    void print() {
        cout << (rec[0] - rec[2] + 1) * (rec[1] - rec[3] + 1);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Bessie cow;

    int N; cin >> N; while (N--) {
        string cmd; cin >> cmd;
        if (cmd[2] == 'P') cow.pivot(cmd.substr(0, 2));
        else cow.step(cmd.substr(0, 2), cmd[2]);
    }
    if (cow.tripped) cout << -1;
    else cow.print();
}