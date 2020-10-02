#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n[5];
    int sum = 0;
    cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4];
    for (int i : n) {
        if (i < 40) i = 40;
        sum += i;
    }

    cout << sum / 5;

    return 0;
}