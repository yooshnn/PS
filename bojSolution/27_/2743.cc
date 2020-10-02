#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string str;
    getline(cin, str);
    cout << str.length();

    return 0;
}