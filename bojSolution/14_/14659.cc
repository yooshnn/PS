#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int>height;

    int N;
    cin >> N;

    int htemp;
    for (int i = 0; i < N; ++i) {
        cin >> htemp;
        height.push_back(htemp);
    }

    int kimidori = 0;
    int streak = 0;
    int flag = 0;
    for (int i = 0; i < height.size(); ++i) {
        if (height[i] > flag) {
            flag = height[i];
            streak = 0;
        }
        else {
            streak++;
            if (kimidori < streak) {
                kimidori = streak;
            }
        }
    }

    cout << kimidori;

    return 0;
}