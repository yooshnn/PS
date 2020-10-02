#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int a[9];
    int t = 0, temp = 0, c;
    while (t++ < 9) {
        cin >> a[t - 1];
    }
    while (t-- > 0) {
        if (a[t] > temp) {
            temp = a[t];
            c = t + 1;
        }
    }
    cout << temp << "\n" << c;

    return 0;
}