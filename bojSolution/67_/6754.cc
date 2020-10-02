#include <bits/stdc++.h>
using namespace std;

int M, N, group, i;
queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for (i = 0; i < N; ++i) {
        int input; cin >> input;
        
        if (i == 0) {
            if (input <= M) q.push(input);
            else break;
            group += input;
        }
        else {
            if (i >= 4) {
                group -= q.front();
                q.pop();
            }
            if (group + input <= M) {
                group += input;
                q.push(input);
            }
            else break;
        }
    }

    cout << i;

    return 0;
}