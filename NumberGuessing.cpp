#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
	int number, attempt = 0, j = 1, userNumber;
	char choice;
public:
	void RandomNumberGenerator() {
		srand(time(0));
		//Generate Random Number between 1 and 100
		number = rand() % 100 + 1;
		PlayGame();
	}

	void PlayGame() {
		cout << endl << endl << "\033[33m***********************************************************************************************************************\033[0m" << endl;
		cout << "\t\t\t\t    \033[47m\033[30m**  Welcome to the Number Guessing Game!  **\033[0m\033[0m" << endl;
		cout << "\033[33m***********************************************************************************************************************\033[0m" << endl << endl;

		cout << "\t\t\t\t\033[35m I have selected a random number between 1 and 100\033[0m" << endl << endl << endl;
		do {
		label1:   label2:
			cout << "\t";
			cout << "Enter : ";
			cout << "\033[36m";
			cin >> userNumber;
			cout << "\033[0m";

			cout << endl;

			if (userNumber < 0) {
				cout << "\033[31mPlease Enter a Positive Number\033[0m" << endl << endl;
				goto label1;
			}

			else if (userNumber > 100) {
				cout << "\033[31mPlease Enter a Number Less than 100\033[0m" << endl << endl;
				goto label2;
			}

			else if (userNumber > number) {
				cout << "\033[32mToo High! Enter Smaller Number\033[0m" << endl << endl;
			}

			else if (userNumber < number) {
				cout << "\033[32mToo Low! Enter Bigger Number\033[0m" << endl << endl;
			}

			else if (userNumber == number) {
				cout << "\033[33m\t\t\t\tAMAZING! Congratulations! You are Absolutely Correct ! The Number is \033[0m" << number << endl << endl;
				cout << "\033[0m";
				break;
			}

			attempt++;
		} while (j);

		AttempCheck();
	}

	void AttempCheck() {
		if (attempt == 1) {
			cout << "\033[35m";
			cout << "\t\t\t\t\t       \033[35mOMG You have used only ONE Guess , BRAVO!! \033[0m" << endl << endl;
		}

		else if (attempt < 5) {
			cout << "\t\t\t\t\t\033[35mYou have used " << attempt + 1 << " guesses, ABSOLUTELY FANTANSTIC!! \033[0m" << endl << endl;
		}

		else if (attempt < 10) {
			cout << "\t\t\t\t\t    \033[35m You have used " << attempt + 1 << " guesses, WELLDONE!! \033[0m" << endl << endl;
		}

		else if (attempt > 10 && attempt < 20) {
			cout << "\t\t\t\t\t    \033[35m You have used " << attempt + 1 << " guesses, NICE!!\033[0m " << endl << endl;
		}
		else if (attempt > 20) {
			cout << "\t\t\t\t       \033[35mOOPS!! You have used " << attempt + 1 << " guesses, PLEASE IMPROVE hahaaa\033[0m " << endl << endl;
		}


		cout << endl << "\033[36mDo You Want to Play Again ? Press Any Key for Continue Otherwise Press 'q' / 'Q' for Quit\033[0m" << endl << endl;
		cout << "Enter : ";
		cout << "\033[36m";
		cin >> choice;
		cout << "\033[0m";

		if (choice == 'q' || choice == 'Q') {
			exit(0);
		}
		else {
			attempt = 0;
			PlayGame();
		}
	}
};
int main() {
	Game g;
	g.RandomNumberGenerator();
	return 0;
}
