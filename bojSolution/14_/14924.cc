#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int s, t, d;
    cin >> s >> t >> d;

    double ans;
    ans = d / (s * 2) * t;
    cout << ans;

    return 0;
}