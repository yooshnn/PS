#include <iostream>
#include <algorithm>
using namespace std;

int N, input, p = 0;
int arr[100000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    while (p < N) {
        //5cout << "P: " << p << endl;
        for (int i = 0; i < N; i++) {
            //cout << arr[i] << " ";
        }
        if (arr[p] >= 3) {
            arr[p] %= 3;
        }
        if (arr[p] <= 0) {
            p++;
            continue;
        }
        else {
            arr[p]--;
            int q = upper_bound(arr + p, arr + N, 1) - arr;
            //cout << "q = " << q << ", arr[q] = " << arr[q] << endl;
            if (q >= N) {
                cout << "NO";
                return 0;
            }
            else {
                arr[q] -= 2;
            }
        }
    }
    cout << "YES";
    return 0;
}