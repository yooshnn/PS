#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); ++i) {
        if ((i % 10 == 0) && (i != 0)) cout << "\n";
        cout << s[i];
    }

    return 0;
}