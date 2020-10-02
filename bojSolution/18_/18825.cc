#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M, s = 1001, n = 1001, res = 0;

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		s = min(temp1, s);
		n = min(temp2, n);
	}

	if (s > n * 6) res = n * N; // ì„¸íŠ¸ê°’ > ë‚±ê°œ6ê°œ ê°’
	else res = s * (N / 6) + n * (N % 6); // ì„¸íŠ¸ê°’ <= ë‚±ê°œ 6ê°œ ê°’

	if (s * (N / 6 + 1) < res) res = s * (N / 6 + 1); // ì„¸íŠ¸ë¡œ ì˜¤ë°”í•´ì„œ êµ¬ë§¤ < í˜„ìž¬ê°’

	cout << res;

	return 0;
}