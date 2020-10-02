#include <iostream>
#include <string>
using namespace std;

string line[3072]{ "", };
int N, amnt2cpy = 3;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    line[0] = "*";
    line[1] = "* *";
    line[2] = "*****";

    cin >> N;
    for (int i = 3; i <= N; i += amnt2cpy) {
        for (int j = 0; j < amnt2cpy; ++j) {
            line[amnt2cpy + j] = line[j];
            for (int k = 0; k < amnt2cpy * 2 - 1 - j * 2; ++k) {
                line[amnt2cpy + j] += ' ';
            }
            line[amnt2cpy + j] += line[j];
        }
        amnt2cpy *= 2;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) cout << ' ';
        cout << line[i];
        for (int j = 0; j < N - 1 - i; ++j) cout << ' ';
        cout << "\n";
    }

    return 0;
}