#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[12], oper[4];
int maxres = -1100000000, minres = 1100000000;

void c(int depth, int add, int sub, int mul, int div, int res) {
    if (++depth == N) {
        maxres = max(maxres, res);
        minres = min(minres, res);
        return;
    }
    if (add > 0) c(depth, add - 1, sub, mul, div, res + A[depth]);
    if (sub > 0) c(depth, add, sub - 1, mul, div, res - A[depth]);
    if (mul > 0) c(depth, add, sub, mul - 1, div, res * A[depth]);
    if (div > 0) c(depth, add, sub, mul, div - 1, res / A[depth]);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> oper[i];
    }
    c(0, oper[0], oper[1], oper[2], oper[3], A[0]);
    cout << maxres << "\n" << minres;

    return 0;
}