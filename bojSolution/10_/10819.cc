#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int N, res = -9999;
int arr[8];
bool visit[8]{ false, };
vector <int>v;

void dfs(int depth) {
    if (depth == N) {
        int temp = 0;
        for (int i = 1; i < N; ++i) {
            temp += abs(v[i] - v[i - 1]);
        }
        res = max(res, temp);
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (visit[i] == false) {
            visit[i] = true;
            v.push_back(arr[i]);
            dfs(depth + 1);
            visit[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    dfs(0);

    cout << res;

    return 0;
}