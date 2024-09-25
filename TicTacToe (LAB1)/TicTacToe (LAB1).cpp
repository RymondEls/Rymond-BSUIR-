#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

class TicTacToe {
private:
	int size;
	bool player;
	vector<vector<char>> grid;

	bool HorizontalCheckWin(int x, TicTacToe& game, char value) const {
		for (int i = 0; i < size - 2;i++) {
			if (game[x][i] == value && game[x][i + 1] == value && game[x][i + 2] == value) {
				return true;
				break;
			}
		}
		return false;
	}
	bool VerticalCheckWin(int y, TicTacToe& game,char value) const {
		for (int i = 0; i < size - 2;i++) {
			if (game[i][y] == value && game[i+1][y] == value && game[i+2][y] == value) {
				return true;
				break;
			}
		}
		return false;
	}
	bool DiagonalCheckWinLR(int x, int y, TicTacToe& game, char value) {
		if (x >= y) {
			x = FindStartPosition(x);
		}
		else {
			y = FindStartPosition(y);
		} //СДЕЛАТЬ САМУ ПРОВЕРКУ НА ПОБЕДУ (for-loop)
	}
public:
	TicTacToe(int size) {
		this->player = true;
		this->size = size;
		this->grid = vector<vector<char>>(size, vector<char>(size, '#'));
	}
	void ShowGrid() {
		system("cls");
		for (int i = 0; i < size;i++) {
			cout << ' ' << setw(4 * size + 2) << setfill('-') << '\n' << ' ';
			for (int j = 0; j < size; j++) {
				cout << "| " << this->grid[i][j] << ' ';
			}
			cout << "| " << '\n';
		}
		cout << ' ' << setw(4 * size + 2) << setfill('-') << '\n';
	}
	void SetValue(int x, int y, bool player) {
		if (GetValue(x, y) == '#') {
			if (player) {
				grid[x][y] = 'x';
				this->player = false;
			}
			else {
				grid[x][y] = 'o';
				this->player = true;
			}
		}
		else {
			cout << "Cannot set value in this position" << '\n';
			return;
		}
	}
	char GetValue(int x, int y) {
		return grid[x][y];
	}

	bool GetPlayer() const {
		return this->player;
	}
	vector<char>& operator[](int index) {
		return grid[index];
	}

	int FindStartPosition(int index) {

	}

	bool CheckWin(int x, int y, TicTacToe& game, bool player) const {
		char value;
		if (player) {
			value = 'x';
		}
		else {
			value = 'o';
		}
		if (HorizontalCheckWin(x, game, value)) {
			return true;
		}
		else if (VerticalCheckWin(y, game, value)) {
			return true;
		}
		else return false;
	}

	void WinAnnounce() {

	}
};

/*	
	FROM 25.09
	SOMEHOW MANAGED TO UNDERSTAND BOOLEAN LOGIC OF MY OWN FOO`S

	TODO:
	PRIORITIZED:
	MAKE FUCKING DIAGONAL CHECKS
	LESS PRIORITY:
	1. OUTDATED~~CHECK IF CAN PLACE IN CHOSEN PLACE (RELOAD OPERATOR)~~OUTDATED
	RELEVANT - ITS ALREADY IN SETTER 
	2. COMMON WIN CHECK (ALL CHECKS IN 1)
	4. CURE INT MAIN (THIS PIECE OF RANDOM SHIT IS SHITTIEST SHIT THAT I HAVE EVER SEEN IN MY LIFE)

*/

int main()
{
	int size;
	cout << "Enter game size ( 3x3+ ): " << '\n';
	cin >> size;
	TicTacToe Game(size);
	Game.ShowGrid();
	int x, y;
	for (int i = 0; i <= 4;i++) {
		cin >> x >> y;
		Game.SetValue(x, y, Game.GetPlayer());
		system("pause");
		Game.ShowGrid();
		
	}
	while (!Game.CheckWin(x, y, Game, !Game.GetPlayer())) {
		cin >> x >> y;
		Game.SetValue(x, y, Game.GetPlayer());
		system("pause");
		Game.ShowGrid();
	};
	
}