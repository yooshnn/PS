#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    queue<string> q;
    char key[26] = { 'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U' };
    string line, garb, trans;

    while (1) {
        getline(cin, garb);
        if (garb == "ENDOFINPUT") break;
        getline(cin, line);
        getline(cin, garb);
        trans = "";
        for (char c : line) {
            if ((c >= 'A') && (c <= 'Z')) {
                trans += key[c - 65];
            }
            else { trans += c; }
        }
        q.push(trans);
    }
    while (!q.empty()) {
        cout << q.front() << "\n";
        q.pop();
    }
    return 0;
}