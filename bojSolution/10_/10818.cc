#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> v;
    int temp, t;
    cin >> t;
    while (t-- > 0) {
        cin >> temp;
        v.push_back(temp);
    }

    cout << *min_element(v.begin(), v.end()) << " " << *max_element(v.begin(), v.end());

    return 0;
}