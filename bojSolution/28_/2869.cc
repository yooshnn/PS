#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int day = 0;
    int a, b, v;
    cin >> a >> b >> v;

    if ((v - a) % (a - b) == 0) {
        cout << (v - a) / (a - b) + 1;
    }
    else {
        cout << (v - a) / (a - b) + 2;
    }

    return 0;
}