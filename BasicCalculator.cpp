#include <iostream>
using namespace std;

class Calculator {
	int userChoice;
	char choice;
	double First, Second;
public :
	void Selection() {
		cout << endl << endl << "\033[33m***********************************************************************************************************************\033[0m" << endl;
		cout << "\t\t\t\t    \033[47m\033[30m**  Welcome to the Exciting Arithmetic Calculator!  **\033[0m\033[0m" << endl;
		cout << "\033[33m***********************************************************************************************************************\033[0m" << endl << endl;

		cout << "\t\t\t\t\033[35m Are You Ready to Perform Some Mathematical Magic?\033[0m" << endl << endl << endl;
		label1:
		cout << "\t\033[36mWhich Operations Do You Want To Perform ?\033[0m" << endl << endl;
		cout << "\033[32m";
		cout << "\t1) Addition" << endl;
		cout << "\t2) Subtraction" << endl;
		cout << "\t3) Multiplation" << endl;
		cout << "\t4) Division" << endl;
		cout << "\t5) Exit" << endl<<endl;
		cout << "\033[0m";

		cout << "\033[35mEnter Your Choice : ";
		cout << "\033[36m";
		cin >> userChoice;
		cin.ignore();
		cout << "\033[0m";

		switch (userChoice) {
		case 1:
			Addition();
			break;
		case 2:
			Subtraction();
			break;

		case 3 :
			Multiplication();
			break;

		case 4 :
			Division();
			break;

		case 5:
			exit(0);
			break;
		default :
			cout << endl << " \033[31m Invalid Choice \033[0m" << endl << endl;
			goto label1;
		}

		cout << endl << "\033[36mDo you Want to Perform Another Calculation?  Press Any Key for Continue Otherwise Press 'q' / 'Q' for Quit\033[0m" << endl << endl;
		cout << "Enter : ";
		cout << "\033[36m";
		cin >> choice;
		cout << "\033[0m";
		if (choice == 'q' || choice == 'Q') {
			cout <<endl<< "\t\t\t\t\033[33mGoodbye! Thank you for using the Calculator\033[0m" << endl;
			exit(0);
		}
		else {
			Selection();
		}
	}

	void Addition() {
		cout << endl << "Enter First Number : ";
		cout << "\033[36m";
		cin >> First;
		cout << "\033[0m";

		cout << "Enter Second Number : ";
		cout << "\033[36m";
		cin >> Second;
		cout << "\033[0m";
		cout << endl << "\033[33mYour Answer is : \033[32m" << First + Second << endl << endl;

	}

	void Subtraction() {
		cout << endl << "Enter First Number : ";
		cout << "\033[36m";
		cin >> First;
		cout << "\033[0m";

		cout << endl << "Enter Second Number : ";
		cout << "\033[36m";
		cin >> Second;
		cout << "\033[0m";
		cout << endl << "\033[33mYour Answer is : \033[32m" << First - Second << endl << endl;

	}

	void Multiplication() {
		cout << endl << "Enter First Number : ";
		cout << "\033[36m";
		cin >> First;
		cout << "\033[0m";

		cout << endl << "Enter Second Number : ";
		cout << "\033[36m";
		cin >> Second;
		cout << "\033[0m";
			cout << endl << "\033[33mYour Answer is : \033[32m" << First * Second << endl << endl;
		
	}

	void Division() {
		cout << endl << "Enter First Number : ";
		cout << "\033[36m";
		cin >> First;
		cout << "\033[0m";

		label:
		cout << endl << "Enter Second Number : ";
		cout << "\033[36m";
		cin >> Second;
		cout << "\033[0m";
		if (Second == 0) {
			cout << endl << "\033[31mUndefined! Division by Zero is Not Possible\033[0m" << endl << endl;
			goto label;
}
		else {
			cout << endl << "\033[33mYour Answer is : \033[32m" << First / Second << endl << endl;
		}
	}

	
};

int main() {
	Calculator c;
	c.Selection();
}
