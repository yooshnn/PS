#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string line;
int N, M, K;
int pl, pr;
long long res = 0;

int block[26][200000];

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    pl = 0; pr = M;

    cin.ignore();
    cin.clear();

    /* DUNGEON

    2,0 2,1 2,2
    1,0 1,1 1,2
    0,0 0,1 0,2

    */

    for (int i = 0; i < K; ++i) {
        getline(cin, line);
        for (int j = 0; j < M; ++j) {
            if (line[j] == 'R') {
                block[i][j] = 0;
            }
            else {
                block[i][j] = 1;
            }
        }
    }

    getline(cin, line); // line[i]는 i번째 줄에 대응 BCA

    /*  
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << block[i][j] << " ";
        }
        cout << endl;
    }*/

    for (int i = M - 2; i >= 0; --i) {
        if (block[line[N - 1] - 'A'][i] == 1) {
            pl = i + 1;
            break;
        }
    }
    res = pr - pl;
            //cout << "@" << res << " { " << pl << ", " << pr << " } " << endl;
    for (int i = N - 2; i >= 0; i--) {
        int* cur = block[line[i] - 'A'];

        while (pl > 0) {
            if (cur[pl - 1] == 1) break;
            pl--;
        }
        while (pr > 0) {
            if (cur[pr - 1] == 1) break;
            pr--;
        }
        //cout << "@" << res << " { " << pl << ", " << pr << " } " << endl;
        res += pr - pl;

    }

    cout << res;

    return 0;
}