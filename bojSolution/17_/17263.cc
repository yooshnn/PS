#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    int T, input, m=0;
    cin >> T;
    while (T-- > 0) {
        cin >> input;
        if (input > m) {
            m=input;
        }
    }
    cout << m;
}