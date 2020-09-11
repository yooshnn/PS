#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int T;
long long n;
long long cake[100001];
long long res = 0;

long long maxCake = 0;
vector<int> modecake;
long long rest = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> T;
    while (T--) {
        modecake.clear();
        maxCake = 0;
        rest = 0;
        res = 0;
        for (auto& next : cake) next = 0;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            int input;
            cin >> input;
            cake[input]++;

            if (cake[input] > maxCake) {
                modecake.clear();
                maxCake = cake[input];
                modecake.push_back(input);
            }
            else if (cake[input] == maxCake) {
                modecake.push_back(input);
            }
        }

        if (n == 2) {
            cout << 0 << "\n";
            continue;
        }

        for (int i = 1; i <= 100000; ++i) {
            if (cake[i] < maxCake) {
                rest += cake[i];
            }
        }

        res = max(0, (int)modecake.size() - 1);
        res += rest / (maxCake - 1);

        /*
        if (modecake.size() == 1) {
            res = rest / (maxCake - 1);
        }
        else {
            res = rest;
            res += modecake.size() - 1;
        }
        */

        cout << res << "\n";
    }

    return 0;
}