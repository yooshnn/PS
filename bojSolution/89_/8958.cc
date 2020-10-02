#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string quiz;
    int T, streak, score;
    cin >> T;

    cin.clear();
    cin.ignore();
    while (--T >= 0) {
        getline(cin, quiz);
        streak = 0;
        score = 0;
        for (char q : quiz) {
            if (q == 'O') {
                streak++;
                score += streak;
            }
            else {
                streak = 0;
            }
        }
        cout << score << "\n";
    }


    return 0;
}