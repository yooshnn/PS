#include <iostream>
using namespace std;

int main() {
cin.tie(NULL);
cout.tie(NULL);
ios::sync_with_stdio(0);
int a,b;
while(1) {
cin >> a >> b;
if (a==0 && b==0) break;
if (a>b) cout << "Yes" << endl;
else cout << "No" << endl;
}
return 0;
}