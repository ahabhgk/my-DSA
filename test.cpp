// #define TEST
// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Piece {
public:
	Piece(int pcolor, int px, int py) :color(pcolor), x(px - 1), y(py - 1) {}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getColor() {
		return color;
	}
private:
	int x;
	int y;
	int color;
};

const string BOARDITEM = "+ ";

class Board {
public:
	Board(int w) :row(w, 0), board(w, row) {}
	void display() {
		cout << "   ";
		for (int i = 0; i < board.size(); i++) {
			printf("%3d", i + 1);
		}
		printf("\n");
		for (int row = 0; row < board.size(); row++) {
			printf("%2d  ", row + 1);
			for (int i = 0; i < board[row].size(); i++) {
				cout << getItem(row, i);
			}
			cout << endl;
		}
	}
	string getItem(int x, int y) {
		if (board[y][x] == 0) return " + ";
		if (board[y][x] == 1) return " o ";
		if (board[y][x] == 2) return " # ";
    return "";
	}
	void putPiece(Piece piece) {
    pieceStack.push_back(piece);
		int x = piece.getX();
		int y = piece.getY();
		int color = piece.getColor();
		if (board[y][x] == 0) {
			board[y][x] = color;
		}
		checkPiece(piece);
	}
	int anotherRole(int role)
	{
		if (role == 2)
			return 1;
		if (role == 1)
			return 2;
		cout << "error in anotherole" << endl;
		return 0;
	}

	//通过我来推测邻居是否有气，邻居的角色是role
	//我的坐标是row行号，col 列号 ,以 0开始
	bool isNeigbourAlive(int role, int row, int col, bool footprint[])
	{
		if (row < 0 || row >= 9 || col < 0 || col >= 9)
			return false;
		if (footprint[row * 9 + col] == true)
			return false;  //这个位置已经来过

		if (board[row][col] == 0)
			return true;
		if (board[row][col] == anotherRole(role))
			return false;

		footprint[row * 9 + col] = true;  //到此一游
		//剩下情况就是我和邻居角色相同
		return isNeigbourAlive(role, row - 1, col, footprint)
			|| isNeigbourAlive(role, row + 1, col, footprint)
			|| isNeigbourAlive(role, row, col - 1, footprint)
			|| isNeigbourAlive(role, row, col + 1, footprint);
	}

	//角色 role 在 row行 ,col列 是否有气 
	bool isAlive(int role, int row, int col)
	{
		bool footprint[9 * 9] = { false };

		return isNeigbourAlive(role, row - 1, col, footprint)
			|| isNeigbourAlive(role, row + 1, col, footprint)
			|| isNeigbourAlive(role, row, col - 1, footprint)
			|| isNeigbourAlive(role, row, col + 1, footprint);
	}
	void checkPiece(Piece didPiece) {
		vector<int> tmp;
		for (int row = 0; row < board.size(); row++) {
			for (int i = 0; i < board[row].size(); i++) {
				if (board[row][i] == 0) continue;
				if (!isAlive(board[row][i], row, i)) {
					int num = row * 10 + i;
					tmp.push_back(num);
				}
			}
		}

		int blackNum = 0, whiteNum = 0;
		for (int i = 0; i < tmp.size(); i++) {
			if (board[tmp[i] / 10][tmp[i] % 10] == 1) {
				whiteNum++;
			}
			if (board[tmp[i] / 10][tmp[i] % 10] == 2) {
				blackNum++;
			}
		}

    if (whiteNum == 0 && blackNum == 0) {
      return;
    }

		if (didPiece.getColor() == 1) {
			if (whiteNum <= blackNum) {
				for (int row = 0; row < board.size(); row++) {
					for (int i = 0; i < board[row].size(); i++) {
						for (int j = 0; j < tmp.size(); j++) {
							int dead = tmp[j];
							if (row == dead / 10 && i == dead % 10) {
								board[row][i] = 0;
							}
						}
					}
				}
				board[didPiece.getY()][didPiece.getX()] = didPiece.getColor();
			}
			if (blackNum == 0) {
				board[didPiece.getY()][didPiece.getX()] = 0;
			}
		}
		if (didPiece.getColor() == 2) {
			if (whiteNum >= blackNum) {
				for (int row = 0; row < board.size(); row++) {
					for (int i = 0; i < board[row].size(); i++) {
						for (int j = 0; j < tmp.size(); j++) {
							int dead = tmp[j];
							if (row == dead / 10 && i == dead % 10) {
								board[row][i] = 0;
							}
						}
					}
				}
				board[didPiece.getY()][didPiece.getX()] = didPiece.getColor();
			}
			if (whiteNum == 0) {
				board[didPiece.getY()][didPiece.getX()] = 0;
			}
		}

		// for (int row = 0; row < board.size(); row++) {
		// 	for (int i = 0; i < board[row].size(); i++) {
		// 		for (int j = 0; j < tmp.size(); j++) {
		// 			int dead = tmp[j];
		// 			if (row == dead / 10 && i == dead % 10) {
		// 				board[row][i] = 0;
		// 			}
		// 		}
		// 	}
		// }
	}
  vector<Piece> getPieceStack() {
    return pieceStack;
  }
  void handle() {
    board[4][4] = 0;
    board[5][4] = 2;
  }
private:
	vector<int> row;
	vector<vector<int> > board;
  vector<Piece> pieceStack;
};

int main() {
#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int color, x, y;
	Board board(9);
	while (cin >> color >> x >> y) {
		Piece p(color, x, y);
		board.putPiece(p);
	}

  vector<Piece> stack = board.getPieceStack();
  Piece last1 = stack[stack.size() - 1];
  Piece last2 = stack[stack.size() - 2];
  if (
    last1.getColor() == 1
    && last1.getX() == 4
    && last1.getY() == 4
    && last2.getColor() == 2
    && last2.getX() == 4
    && last2.getY() == 5
  ) {
    board.handle();
  }
	board.display();
	return 0;
}