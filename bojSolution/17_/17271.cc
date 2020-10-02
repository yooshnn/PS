#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int>v{ 1 };

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int temp = v[i - 1];
        if (i >= m) temp += v[i - m];
        v.push_back(temp % 1000000007);
    }
    cout << v.back();

    return 0;
}