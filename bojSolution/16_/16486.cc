#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int d1, d2;
    cin >> d1 >> d2;

    cout.precision(6);
    cout << fixed << d1 + d1 + (d2 + d2) * 3.141592;

    return 0;
}