#include "../include/header.h"

bool check(int x, int y, vector<vector<char> > &board){
		for (int i = 0; i < 9; i++)
			if (i != y && board[x][i] == board[x][y] || x != i && board[i][y] == board[x][y])
				return false;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (board[x / 3 * 3 + i][y / 3 * 3 + j] == board[x][y] && x != x / 3 * 3 + i &&y != y / 3 * 3 + j)
					return false;

		return true;
	}
	bool isValidSudoku(vector<vector<char> > &board) {
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				if (board[i][j] == '.') continue;
				if (!check(i, j, board)) return false;
			}
		}
		return true;
	}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}