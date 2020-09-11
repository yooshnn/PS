#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int a[200000];

bool issorted(int arr[], int len) {
    if (len < 2) return true;
    for (int i = 1; i < len; ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        if (N == 1) { cout << "0\n"; continue; }

        short slope = 0; 
        int high = 0;

        for (int i = N - 1; i > 0; --i) {
            if (slope == 0) {
                if (a[i] > a[i - 1]) slope = -1;
                else if (a[i] < a[i - 1]) slope = 1;
            }
            else if (slope == -1) {
                if (a[i] < a[i - 1]) { high = i; break; }
            }
            else if (slope == 1) {
                if (a[i] > a[i - 1]) { high = i; break; }
            }
        }/*
        cout << "slope: " << slope << endl;
        cout << "high: " << high << endl;*/
        if (slope == 0) { cout << "0\n"; continue; }
        for (int i = high; i > 0; --i) {
            high = i;
            if (a[i] < a[i - 1]) break;
            if (high == 1) high = 0;
        }
        cout << high << "\n";
    }

    return 0;
}