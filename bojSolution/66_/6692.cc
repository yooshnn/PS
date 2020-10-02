#include <iostream>
#include <string>
#include <cstring>
#include <queue>
//#include <fstream>
#define pii pair<int,int>
using namespace std;

int R1, C1, R2, C2;

string board[7][7];
string curBoard[7][7];
bool visit[7][7];

string parsePiece(string top, string mid, string bot);
bool insertPiece(int insRow, int insCol, string insPiece);
bool run();

//ofstream outfile;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	//outfile.open("xxxxtttt.txt");
	while (1) {
		if (!run()) break;
	}
	//outfile.close();
	return 0;
}

string parsePiece(string top, string mid, string bot) {
	string ret;
	int tmp = 0;
	if (top[1] == '|') tmp += 1000;
	if (mid[0] == '-') tmp += 100;
	if (mid[2] == '-') tmp += 10;
	if (bot[1] == '|') tmp += 1;
	ret = to_string(tmp);
	return string(4 - ret.length(), '0').append(ret);
}

bool insertPiece(int insRow, int insCol, string insPiece) {
	int r1 = R1, c1 = C1, r2 = R2, c2 = C2;

	memset(visit, false, sizeof(visit));
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			curBoard[i][j] = board[i][j];
		}
	}

	if (insRow == 0) {
		for (int r = 6; r > 0; --r) curBoard[r][insCol] = curBoard[r - 1][insCol];
		curBoard[0][insCol] = insPiece;
		if (r1 == 6 && c1 == insCol) {
			r1 = 0;
		}
		else if (c1 == insCol) r1++;
		if (r2 == 6 && c2 == insCol) return false;
		else if (c2 == insCol) r2++;
	}
	if (insRow == 6) {
		for (int r = 0; r < 6; ++r) curBoard[r][insCol] = curBoard[r + 1][insCol];
		curBoard[6][insCol] = insPiece;
		if (r1 == 0 && c1 == insCol) {
			r1 = 6;
		}
		else if (c1 == insCol) r1--;
		if (r2 == 0 && c2 == insCol) return false;
		else if (c2 == insCol) r2--;
	}
	if (insCol == 0) {
		for (int c = 6; c > 0; --c) curBoard[insRow][c] = curBoard[insRow][c - 1];
		curBoard[insRow][0] = insPiece;
		if (r1 == insRow && c1 == 6) {
			c1 = 0;
		}
		else if (r1 == insRow) c1++;
		if (r2 == insRow && c2 == 6) return false;
		else if (r2 == insRow) c2++;
	}
	if (insCol == 6) {
		for (int c = 0; c < 6; ++c) curBoard[insRow][c] = curBoard[insRow][c + 1];
		curBoard[insRow][6] = insPiece;
		if (r1 == insRow && c1 == 0) {
			c1 = 6;
		}
		else if (r1 == insRow) c1--;
		if (r2 == insRow && c2 == 0) return false;
		else if (r2 == insRow) c2--;
	}

	/*if (insRow == 1 && insCol == 6) {
		for (int row = 0; row < 7; ++row) {
			for (int col = 0; col < 7; ++col) {
				if (curBoard[row][col] == "0000") cout << " x ";
				if (curBoard[row][col] == "0001") cout << " i ";
				if (curBoard[row][col] == "0010") cout << " .-";
				if (curBoard[row][col] == "0100") cout << "-. ";
				if (curBoard[row][col] == "1000") cout << " ! ";
				if (curBoard[row][col] == "0011") cout << " ┌-";
				if (curBoard[row][col] == "0101") cout << "-┐ ";
				if (curBoard[row][col] == "1001") cout << " | ";
				if (curBoard[row][col] == "0110") cout << "-─-";
				if (curBoard[row][col] == "1010") cout << " └-";
				if (curBoard[row][col] == "1100") cout << "-┘ ";
				if (curBoard[row][col] == "0111") cout << "-┬-";
				if (curBoard[row][col] == "1011") cout << " ├-";
				if (curBoard[row][col] == "1101") cout << "-┤ ";
				if (curBoard[row][col] == "1110") cout << "-┴-";
				if (curBoard[row][col] == "1111") cout << "-┼-";
			}cout << "\n";
		}
		cout << "\n";
		cout << "\n";
	}*/

	bool isPossible = false;

	queue<pii> q;
	q.push({ r1, c1 });
	visit[r1][c1] = true;
	while (!q.empty()) {
		int curR = q.front().first, curC = q.front().second;
		q.pop();

		if (curR == r2 && curC == c2) {
			isPossible = true;
			break;
		}
		else {
			if (curBoard[curR][curC][0] == '1' && curR > 0 && curBoard[curR - 1][curC][3] == '1' && visit[curR - 1][curC] == false) {
				q.push({ curR - 1, curC });
				visit[curR - 1][curC] = true;
			}
			if (curBoard[curR][curC][3] == '1' && curR < 6 && curBoard[curR + 1][curC][0] == '1' && visit[curR + 1][curC] == false) {
				q.push({ curR + 1, curC });
				visit[curR + 1][curC] = true;
			}
			if (curBoard[curR][curC][1] == '1' && curC > 0 && curBoard[curR][curC - 1][2] == '1' && visit[curR][curC - 1] == false) {
				q.push({ curR, curC - 1 });
				visit[curR][curC - 1] = true;
			}
			if (curBoard[curR][curC][2] == '1' && curC < 6 && curBoard[curR][curC + 1][1] == '1' && visit[curR][curC + 1] == false) {
				q.push({ curR, curC + 1 });
				visit[curR][curC + 1] = true;
			}
		}
	}

	return isPossible;
}

bool run() {
	cin >> R1 >> C1 >> R2 >> C2;
	if (R1 == 0) return false;
	R1--; C1--; R2--; C2--;

	string piece = "0000";
	string pieceTop[7], pieceMid[7], pieceBot[7];

	for (int boardRow = 0; boardRow < 7; ++boardRow) {
		for (int i = 0; i < 7; ++i) cin >> pieceTop[i];
		for (int i = 0; i < 7; ++i) cin >> pieceMid[i];
		for (int i = 0; i < 7; ++i) cin >> pieceBot[i];

		for (int boardCol = 0; boardCol < 7; ++boardCol) {
			board[boardRow][boardCol] = parsePiece(pieceTop[boardCol], pieceMid[boardCol], pieceBot[boardCol]);
		}
	}

	string dPieceTop, dPieceMid, dPieceBot;
	cin >> dPieceTop >> dPieceMid >> dPieceBot;
	//cout << dPieceTop << " " << dPieceMid << " " << dPieceBot << "\n";
	piece = parsePiece(dPieceTop, dPieceMid, dPieceBot);

	bool req = false;
	string rotPiece = piece;

	for (int t = 0; t < 4; ++t) {
		string tempPiece;
		tempPiece = to_string((rotPiece[2] == '1') * 1000 + (rotPiece[0] == '1') * 100 + (rotPiece[3] == '1') * 10 + (rotPiece[1] == '1'));
		rotPiece = string(4 - tempPiece.length(), '0').append(tempPiece);
		//cout << rotPiece << "\n";

		for (int i = 0; i < 3; ++i) {
			req = insertPiece(0, i * 2 + 1, rotPiece);
			if (req) break;
			req = insertPiece(6, i * 2 + 1, rotPiece);
			if (req) break;
			req = insertPiece(i * 2 + 1, 0, rotPiece);
			if (req) break;
			req = insertPiece(i * 2 + 1, 6, rotPiece);
			if (req) break;
		}

		if (req) break;
	}

	if (req) cout << "You can win in one move.\n";
	else cout << "Bad luck!\n";

	/*if (req) outfile << "You can win in one move.\n";
	else outfile << "Bad luck!\n";*/

	return true;
}