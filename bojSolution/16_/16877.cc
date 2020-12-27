#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[3000030];
int fibo[]{ 1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309 };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= 3000000; ++i) {
        bool next[100]{ 0, };
        for (int j : fibo) {
            if (i - j >= 0) next[dp[i - j]] = true;
            else break;
        }
        int tt = 0;
        while (next[tt]) tt++;
        dp[i] = tt;
    }

    int n, t, r = 0; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        r ^= dp[t];
    }
    cout << (r == 0 ? "cubelover" : "koosaga");
}