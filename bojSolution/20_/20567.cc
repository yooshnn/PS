#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    int s[N]; s[N-1] = 0; 
    
    for (int i = 0; i < N-1; ++i) {
       cout << "? " << i+1 << " " << N << endl;
       cin >> s[i];
    }
    for (int i = 0; i < N-1; ++i) {
       s[i] -= s[i+1];
    }

    rope<int> seq;
    for (int i = 1; i <= N; ++i) {
       seq.push_back(i);
    }

    cout << "! ";
    for (int& i : s) {
       cout << seq.at(i) << " ";
       seq.erase(i, 1);
    }
    cout << endl;

    return_0;
}