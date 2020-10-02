#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char S[100];
char S2[100];
char K[100];

int c = 0;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> S;
    cin >> K;
    for (int i = 0; i < strlen(S); ++i) if (S[i] < 48 || S[i] > 57) { S2[c] = S[i]; c++; }
    if (strstr(S2, K) != NULL) {
        cout << "1";
    }
    else {
        cout << "0";
    }
}
