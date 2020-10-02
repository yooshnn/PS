#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n[3];
    cin >> n[0] >> n[1] >> n[2];

    int res = n[0] + n[1] + n[2];

    int temp = 0;
    for (int i : n) {
        if (i > temp) temp = i;
    }
    res -= temp;

    temp = 101;
    for (int i : n) {
        if (i < temp) temp = i;
    }
    res -= temp;

    cout << res;

    return 0;
}