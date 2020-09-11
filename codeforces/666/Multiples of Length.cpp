#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];


    if (n == 1) {
        cout << "1 1" << "\n";
        cout << 1 << "\n";
        cout << "1 1" << "\n";
        cout << 1 << "\n";
        cout << "1 1" << "\n";
        cout << -(arr[1] + 2);
    }

    if (n == 2) {
        cout << "1 1" << "\n";
        cout << -arr[1] << "\n";
        cout << "2 2" << "\n";
        cout << 1 << "\n";
        cout << "2 2" << "\n";
        cout << -(arr[2] + 1);
    }

    if (n >= 3) {

        cout << "1 1" << "\n";
        cout << arr[1] * (n - 1) << "\n"; // n - 1 is always divisible by 1
        arr[1] += arr[1] * (n - 1);

        cout << "2 " << n << "\n"; // n - 1 is always divisible by n - 1
        for (int i = 2; i <= n; ++i) {
            cout << arr[i] * (n - 1) << " ";
            arr[i] += arr[i] * (n - 1);
        }
        cout << "\n";

        cout << "1 " << n << "\n"; // n is always divisible by n
        for (int i = 1; i <= n; ++i) {
            cout << -arr[i] << " ";
        }

    }

    return 0;
}