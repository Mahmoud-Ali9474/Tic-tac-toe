
#include <iostream>
#include<time.h>
using namespace std;
class tictactoe
{
	char board[3][3];
public:
	int getcoordx();
	int getcoordy();
	void clearboard();
	void printboard();
	void placemaker(int, int, char);
	bool checkvictory(char);
	void playagain(int&, bool&, char&);
};
void tictactoe::clearboard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}
void tictactoe::printboard() {
	std::cout << "   | 1  2  3|" << std::endl;
	std::cout << "   ___________" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << "  |";
		for (int j = 0; j < 3; j++) {
			std::cout << board[i][j] << ' ' << '|';
		}
		std::cout << "\n   ___________" << std::endl;
	}
}
int tictactoe::getcoordx() {
	int x;
	do {
		cout << "Enter value of x coordinate: ";
		cin >> x;
		if (x < 1 || x>3)
			cout << "wrong point your  range between 1 and 3" << endl;
	} while (x < 1 || x>3);
	return x;
}
int tictactoe::getcoordy() {
	int y;
	do {
		cout << "Enter value of y coordinate: ";
		cin >> y;
		if (y < 1 || y>3)
			cout << "wrong point your  range between 1 and 3" << endl;
	} while (y < 1 || y>3);
	return y;
}
void tictactoe::placemaker(int x, int y, char currentplayer) {
	bool isDone = false;
	while (isDone == false) {
		if (board[x - 1][y - 1] == ' ') {
			board[x - 1][y - 1] = currentplayer;
			isDone = true;
		}
		else {
			cout << "wrong point please enter anathor one " << endl;
			x = getcoordx();
			y = getcoordy();
		}
	}
}
bool tictactoe::checkvictory(char currentplayer) {
	for (int i = 0; i < 3; i++) {
		if (currentplayer == board[i][0] && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return true;
		else if (currentplayer == board[0][i] && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return true;
	}
	if (currentplayer == board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;
	else if (currentplayer == board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;
	return false;
}
void tictactoe::playagain(int& count, bool& isDone, char& currentplayer) {
	char c;
	cout << "\ndo you want to play again(y/n)" << endl;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		system("cls");
		count = 0;
		isDone = false;
		clearboard();
		currentplayer = 'X';
	}
}
bool gooodpoint(int x, int y, char arr[3][3]) {
	if (arr[x-1][y-1] == ' ') {
		arr[x - 1][y - 1] = 'f';
		return true;
	}
	return false;
}
int main() {
	srand(time(0));
	tictactoe t;
	char arr[3][3] = {' ',' ',' ',
	                  ' ',' ',' ',
	                  ' ',' ',' ' };
	int x, y;
	t.clearboard();
	bool isDone = false;
	int count = 0;
	char player1 = 'X';
	char player2 = 'O';
	char currentplayer = player1;
	while (isDone == false && count <= 9) {
		system("cls");
		t.printboard();
		if (currentplayer == 'X') {
			 x = t.getcoordx();
			 y = t.getcoordy();
			 gooodpoint(x, y, arr);
		}
		else {
			do {
				x = rand() % (3 - 1 + 1) + 1;
				y = rand() % (3 - 1 + 1) + 1;
			} while (gooodpoint(x, y, arr) == false);
		}
		t.placemaker(x, y, currentplayer);
		count++;
		if (t.checkvictory(currentplayer) == true) {
			system("cls");
			isDone = true;
			cout << "\nYou Won The game: " << currentplayer << '\n';
			t.playagain(count, isDone, currentplayer);
		}
		else {
			if (currentplayer == player1)
				currentplayer = player2;
			else
				currentplayer = player1;
		}
		if (count == 9&&t.checkvictory(currentplayer)==false) {
			system("cls");
			cout << "\n No winner\n";
			t.playagain(count, isDone, currentplayer);
		}
		system("pause");
	}
	return 0;
}