#include <iostream>
#include <string>
using namespace std;
void f() {}


bool checkFormat(string move1, int& movesay, string& movesayx, int& movesayz,bool&turn,char&sign,bool&game_goes,int&count) {
	char yardim[3];

	if (move1.length() != 3) {
		cout << "Please enter correct move format!" << endl;
		return false;
	}



	if (move1[0] == '1') {
		movesay = 1;
		yardim[0] = '+';
	}

	else if (move1[0] == '2') {
		movesay = 2;
		yardim[0] = '+';
	}

	else if (move1[0] == '3') {
		movesay = 3;
		yardim[0] = '+';
	}
	else {
		cout << "Please enter correct move format!" << endl;
		return false;
	}





	if (move1[1] == '-') {
		movesayx = '-';
		yardim[1] = '+';
	}
	else {
		cout << "Please enter correct move format!" << endl;
		return false;
	}


	if (move1[2] == '1') {
		movesayz = 1;
		yardim[2] = '+';
	}

	else if (move1[2] == '2') {
		movesayz = 2;
		yardim[2] = '+';
	}

	else if (move1[2] == '3') {
		movesayz = 3;
		yardim[2] = '+';
	}
	else {
		cout << "Please enter correct move format!" << endl;
		return false;
	}


	char nokta[3] = { '+','+','+' };

	for (int j = 0; j < 3; j++) {
		if (yardim[j] != nokta[j]) {
			return false;

		}
	}
	return true;
}

void print(string& board1, string& board2, string& board3, string& board4, string& board5) {
	cout << "Current board: " << endl;
	cout << board1 << endl;
	cout << board2 << endl;
	cout << board3 << endl;
	cout << board4 << endl;
	cout << board5 << endl;
}

void playerMove(string name1, string name2, int& movesay, string& movesayx, int& movesayz, string move1, string& board1, string& board2, string& board3, string& board4, string& board5, bool& turn, char& sign, bool& game_goes, int& count) {
	/*
	char row1[] = {' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '};
	char row2[] = { '-','-', '-', '-', '-', '-', '-', '-', '-', '-', '-' };
	char row3[] = { ' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ' };
	char row4[] = { '-','-', '-', '-', '-', '-', '-', '-', '-', '-', '-' };
	char row5[] = { ' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ' };
	*/
	bool yeter = true;
	if (turn) {
		sign = 'X';
	}
	else {
		sign = 'O';
	}

	if (movesay == 1) {
		if (movesayz == 1) {
			if (board1[1] == ' ') {
				board1[1] = sign;
				count += 1;
			}
			else {
				cout << "That location is already full!" << endl;
				yeter = false;
			}
		}
		else if (movesayz == 2) {
			if (board1[5] == ' ') {
				board1[5] = sign;
				++count;
			}
			else {
				cout << "That location is already full!" << endl;
				yeter = false;
			}
		}

		else if (movesayz == 3) {
			if (board1[9] == ' ') {
				board1[9] = sign;
				++count;
			}
			else {
				cout << "That location is already full!" << endl;
				yeter = false;
			}
		}
	}
	else if (movesay == 2) {
		if (movesayz == 1) {
			if (board3[1] == ' ') {
				board3[1] = sign;
				++count;
			}

			else {
				cout << "That location is already full!" << endl;
				yeter = false;

			}
		}
		else if (movesayz == 2) {
			if (board3[5] == ' ') {
				board3[5] = sign;
				++count;
			}
			else {
				cout << "That location is already full!" << endl;
				yeter = false;
			}
		}
		else if (movesayz == 3) {
			if (board3[9] == ' ') {
				board3[9] = sign;
				++count;
			}
			else {
				cout << "That location is already full!" << endl;
				yeter = false;

			}
		}
	}
	else if (movesay == 3) {
		if (movesayz == 1) {
			if (board5[1] == ' ') {
				board5[1] = sign;
				++count;
			}
			else {
				cout << "That location is already full!" << endl;
				yeter = false;

			}
		}


		else if (movesayz == 2) {
			if (board5[5] == ' ') {
				board5[5] = sign;
				++count;
			}
			else {
				cout << "That location is already full!" << endl;
				yeter = false;

			}
		}

		else if (movesayz == 3) {
			if (board5[9] == ' ') {
				board5[9] = sign;
				++count;
			}
			else {
				cout << "That location is already full!" << endl;
				yeter = false;

			}
		}
	}

	int gulsuyu = 0;
	for (int g = 1; g <= 9; g += 4) {
		if (board1[g] != ' ') {
			gulsuyu += 1;
		}
		if (board3[g] != ' ') {
			gulsuyu += 1;
		}
		if (board5[g] != ' ') {
			gulsuyu += 1;
		}
	}

	for (int a = 1; a <= 9; a += 4) {
		int sayim = 0;
		if (board1[a] == 'X') {
			sayim += 1;
		}
		if (board3[a] == 'X') {
			sayim += 1;
		}
		if (board5[a] == 'X') {
			sayim += 1;
		}

		if (sayim == 3) {
			game_goes = false;
			yeter = false;
			
			
		}
	}

	if (board1[1] == 'X' && board1[5] == 'X' && board1[9] == 'X') {
		game_goes = false;
		yeter = false;
		
	
	}
	if (board3[1] == 'X' && board3[5] == 'X' && board3[9] == 'X') {
		game_goes = false;
		yeter = false;
	}
	if (board5[1] == 'X' && board5[5] == 'X' && board5[9] == 'X') {
		game_goes = false;
		yeter = false;
	}

	for (int a = 1; a <= 9; a += 4) {
		int putin = 0;
		if (board1[a] == 'O') {
			putin += 1;
		}
		if (board3[a] == 'O') {
			putin += 1;
		}
		if (board5[a] == 'O') {
			putin += 1;
		}

		if (putin == 3) {
			game_goes = false;
			yeter = false;


		}
	}

	if (board1[1] == 'O' && board1[5] == 'O' && board1[9] == 'O') {
		game_goes = false;
		yeter = false;

	}
	if (board3[1] == 'O' && board3[5] == 'O' && board3[9] == 'O') {
		game_goes = false;
		yeter = false;
	}
	if (board5[1] == 'O' && board5[5] == 'O' && board5[9] == 'O') {
		game_goes = false;
		yeter = false;
	}

	if (game_goes != false && gulsuyu != 9 && yeter) {
		print(board1, board2, board3, board4, board5);
		/*cout << "Current board: " << endl;
		cout << board1 << endl;
		cout << board2 << endl;
		cout << board3 << endl;
		cout << board4 << endl;
		cout << board5 << endl;
		*/
	}
	yeter = true;
}


bool checkWinner(string& board1, string& board2, string& board3, string& board4, string& board5,bool&game_goes,bool&win, bool&no_winner,int&tekrar, string name1, string name2,int&scoreofplayer1,int&scoreofpayer2) {
	
	for (int a = 1; a <= 9; a += 4) {
		int sayim = 0;
		if (board1[a] == 'X') {
			sayim += 1;
		}
		if (board3[a] == 'X') {
			sayim += 1;
		}
		if (board5[a] == 'X') {
			sayim += 1;
		}

		if (sayim == 3) {
			game_goes = false;
			win = true;
			return true;
		}
	}
	
	if (board1[1] == 'X' && board1[5] == 'X' && board1[9] == 'X') {
		game_goes = false;
		win = true;
		return true;
	}
	if (board3[1] == 'X' && board3[5] == 'X' && board3[9] == 'X') {
		game_goes = false;
		win = true;
		return true;;
	}
	if (board5[1] == 'X' && board5[5] == 'X' && board5[9] == 'X') {
		game_goes = false;
		win = true;
		return true;;
	}

	for (int a = 1; a <= 9; a += 4) {
		int sayim = 0;
		if (board1[a] == 'O') {
			sayim += 1;
		}
		if (board3[a] == 'O') {
			sayim += 1;
		}
		if (board5[a] == 'O') {
			sayim += 1;
		}
		if (sayim == 3) {
			game_goes = false;
			win = false;
			return true;
		}

	}
	
	if (board1[1] == 'O' && board1[5] == 'O' && board1[9] == 'O') {
		game_goes = false;
		win = false;
		return true;
	}
	if (board3[1] == 'O' && board3[5] == 'O' && board3[9] == 'O') {
		game_goes = false;
		win = false;
		return true;
	}
	if (board5[1] == 'O' && board5[5] == 'O' && board5[9] == 'O') {
		game_goes = false;
		win = false;
		return true;
	}
	
	if ((board1[1] == 'X') && (board3[5] == 'X') && (board5[9] == 'X')) {
		
		game_goes = false;
		win = true;
		return true;
	}

	if ((board1[9] == 'X') && (board3[5] == 'X') && (board5[1]) == 'X') {
		game_goes = false;
		win = true;
		return true;
	}

	if ((board1[1] == 'O') && (board3[5] == 'O') && (board5[9] == 'O')) {

		game_goes = false;
		win = false;
		return true;
	}

	if ((board1[9] == 'O') && (board3[5] == 'O') && (board5[1]) == 'O') {
		game_goes = false;
		win = false;
		return true;
	}

	/*
	for (int g = 1; g <= 9; g += 4) {
		
	}*/
	int zahlung = 0;
	for (int g = 1; g <= 9; g += 4) {
		if (board1[g] != ' ') {
			zahlung += 1;
		}
		if (board3[g] != ' ') {
			zahlung += 1;
		}
		if (board5[g] != ' ') {
			zahlung += 1;
		}
	}
	if (zahlung == 9) {
		game_goes = false;
		no_winner = true;
		cout << "The game ended in a draw!" << endl;
		tekrar += 1;
		cout << "Current Scores: " << endl;
		cout << name1 << ": " << scoreofplayer1 << "   " << name2 << ": " << scoreofpayer2 << endl;
		return false;
	}
	game_goes = true;
	return false;
}

void recursive(string name1, string name2, int& movesay, string& movesayx, int& movesayz, string move1, string& board1, string& board2, string& board3, string& board4, string& board5, bool&turn,char&sign,bool&game_goes,int&count) {
	if (count % 2 == 0) {
		turn = true;
	}
	else {
		turn = false;
	}
	while (!(checkFormat(move1, movesay, movesayx, movesayz,turn,sign,game_goes,count))) {
		if (turn) {
			
			cout << name1 << ", please enter your move: ";
			cin >> move1;
		}
		else {
			cout << name2 << ", please enter your move: ";
			cin >> move1;
		}
	}

	playerMove(name1, name2, movesay, movesayx, movesayz, move1, board1, board2,board3,board4,board5, turn,sign,game_goes,count);

}


void playGame(string name1, string move1, int&movesay, string&movesayx, int&movesayz, string name2,string& board1, string& board2, string& board3, string& board4, string& board5, bool&turn,char&sign,bool&game_goes,int&count,bool&win,bool&no_winner, int&scoreofplayer1,int&scoreofplayer2,int&tekrar,string&string_score1,string&string_score2,bool&anewgame) {
	
	if (anewgame) {
		/*board1 = "   |   |   ";
		board2 = "-----------";
		board3 = "   |   |   ";
		board4 = "-----------";
		board5 = "   |   |   ";
		*/

		board1 = "   |   |  ";
		board2 = "-----------";
		board3 = "   |   |  ";
		board4 = "-----------";
		board5 = "   |   |  ";
		cout << endl;
		cout << "Starting a new game..." << endl;
		print(board1, board2, board3, board4, board5);
		/*cout << "Current board: " << endl;
		cout << "   |   |  " << endl;
		cout << "-----------" << endl;
		cout << "   |   |  " << endl;
		cout << "-----------" << endl;
		cout << "   |   |  " << endl;
		*/
		

		count = 1;
		anewgame = false;
		game_goes = true;
	}

	while (game_goes) {

		if (count % 2 == 0) {
			turn = true;
		}
		else {
			turn = false;
		}

		if (turn) {
			cout << name1 << ", please enter your move: ";
			cin >> move1;

		}
		else {
			cout << name2 << ", please enter your move: ";
			cin >> move1;
		}
	
		recursive(name1, name2, movesay, movesayx, movesayz, move1, board1, board2, board3, board4, board5, turn, sign,game_goes,count);
		if (checkWinner(board1, board2, board3, board4, board5, game_goes, win, no_winner, tekrar, name1, name2, scoreofplayer1, scoreofplayer2)) {
			tekrar += 1;
			no_winner = false;
		}
		
		
	}
	

	if (game_goes == false && !no_winner) {
		if (win == true) {
			cout << name1 << " is the winner!" << endl;
			scoreofplayer1 += 1;
			
			//converter(scoreofplayer1,scoreofplayer2,string_score1,string_score2);
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << scoreofplayer1 << "   " << name2 << ": " << scoreofplayer2 << endl;
			game_goes = true;
		}
		else {
			cout << name2 << " is the winner!" << endl;
			scoreofplayer2 += 1;
			
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << scoreofplayer1 << "   " << name2 << ": " << scoreofplayer2 << endl;
			game_goes = true;
		}
	}
	
	
	}

int main() {
	bool game_goes = true;
	bool turn = true;
	int movesay, movesayz;
	string name1, name2 , move1, movesayx, bolge;
	char sign;
	int count = 0;
	bool win;
	bool no_winner = false;
	int scoreofplayer1 = 0;
	int scoreofplayer2 = 0;
	int tekrar = 0;
	string string_score1, string_score2;
	bool anewgame = false;

	cout << "Welcome to Tic-Tac-Toe!" << endl;
	cout << "Player 1, please enter your name: ";
	cin >> name1;
	cout << "Hello, "<< name1 << ". You are going to play with X" << endl;
	cout << "Player 2, please enter your name: ";
	cin >> name2;
	cout << "Hello, " << name2 <<". You are going to play with O" << endl;
	cout << endl;
	cout << "Starting a new game..." << endl;
	
	cout << "Current board: " << endl;
	cout << "   |   |  " << endl;
	cout << "-----------" << endl;
	cout << "   |   |  " << endl;
	cout << "-----------" << endl;
	cout << "   |   |  " << endl;


	string board1 = "   |   |  ";
	string board2 = "-----------";
	string board3 = "   |   |  ";
	string board4 = "-----------";
	string board5 = "   |   |  ";

	while (tekrar <= 1) {
		if (tekrar == 1) {
			anewgame = true;
		}
		playGame(name1, move1, movesay, movesayx, movesayz, name2, board1, board2, board3, board4, board5, turn, sign, game_goes, count, win, no_winner, scoreofplayer1, scoreofplayer2, tekrar,string_score1,string_score2,anewgame);
	}
	if (scoreofplayer1 > scoreofplayer2) {
		cout << endl;
		cout << "Final Scores: " << endl;
		
		cout << name1 << ": " << scoreofplayer1 << "   " << name2 << ": " << scoreofplayer2 << endl;
		cout << name1 << " is the overall winner!" << endl;
	}
	else if (scoreofplayer2 > scoreofplayer1) {
		cout << endl;
		cout << "Final Scores: " << endl;
		cout << name1 << ": " << scoreofplayer1 << "   " << name2 << ": " << scoreofplayer2 << endl;
		cout << name2 << " is the overall winner!" << endl;
	}
	else {
		cout << endl;
		cout << "Final Scores: " << endl;
		cout << name1 << ": " << scoreofplayer1 << "   " << name2 << ": " << scoreofplayer2 << endl;
		cout << "The overall game ended in a draw!" << endl;
	}

	return 0;

}