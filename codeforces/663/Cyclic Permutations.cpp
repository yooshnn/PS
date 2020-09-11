#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
unsigned long long f = 1;
unsigned long long g = 2;
int t;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        f *= i;
        f %= 1000000007;
        if (i < t-1) {
            g *= 2;
            g %= 1000000007;
        }
    }
    cout << (f + 1000000007 - g) % 1000000007;
    return 0;
}