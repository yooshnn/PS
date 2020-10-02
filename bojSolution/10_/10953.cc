#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int T;
    string s;
    cin >> T;
    cin.clear();
    cin.ignore();
    while(--T >= 0) {
        getline(cin, s);
        cout << int(s[0]) + int(s[2]) - 96 << "\n";
    }
    return 0;
}