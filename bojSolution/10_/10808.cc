#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string s;
    getline(cin, s);
    for (int i = 0; i < 26; ++i) {
        cout << std::count(s.begin(), s.end(), static_cast<char>(i+97)) << " ";
    }

    return 0;
}