#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); ++i) {
        if ((str[i] <= 'Z') && (str[i] >= 'A')) {
            cout << (char)(str[i] + 32);
        }
        else if ((str[i] <= 'z') && (str[i] >= 'a')) {
            cout << (char)(str[i] - 32);
        }
        else {
            cout << str[i];
        }
    }

    return 0;
}