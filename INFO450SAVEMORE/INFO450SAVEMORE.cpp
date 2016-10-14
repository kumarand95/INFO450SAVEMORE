// INFO450SAVEMORE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <iomanip>

class account {
	char cust_name[20];
	int acc_no;
	char acc_type[20];
public:
	void get_accinfo() {
		std::cout << "\n\nEnter Customer Name :- ";
		std::cin >> cust_name;
		std::cout << "Enter Account Number :- ";
		std::cin >> acc_no;
		std::cout << "Enter Account Type :- ";
		std::cin >> acc_type;
	}
	void display_accinfo() {
		std::cout << "\n\nCustomer Name :- " << cust_name;
		std::cout << "\nAccount Number :- " << acc_no;
		std::cout << "\nAccount Type :- " << acc_type;
	}
};

class cur_acct : public account {
	static float balance;
public:
	void disp_currbal() {
		std::cout << "\nBalance :- " << balance;
		std::cout << "\nPress any key to continue...";
		system("read");
	}
	void deposit_currbal() {
		float deposit;
		std::cout << "\nEnter amount to Deposit :- ";
		std::cin >> deposit;
		balance = balance + deposit;
	}
	void withdraw_currbal() {
		float penalty, withdraw;
		std::cout << "\n\nBalance :- " << balance;
		std::cout << "\nEnter amount to be withdraw :-";
		std::cin >> withdraw;
		balance = balance - withdraw;
		if (balance < 500) {
			penalty = (500 - balance) / 10;
			balance = balance - penalty;
			std::cout << "\nBalance after deducting penalty : " << balance;
		}
		else if (withdraw > balance) {
			std::cout << "\n\nYou have to take permission for Bank Overdraft Facility\n";
			balance = balance + withdraw;
		}
		else
			std::cout << "\nAfter Withdrawl your Balance revels : " << balance;
	}
};

class sav_acct : public account {
	static float savbal;
public:
	void disp_savbal() {
		std::cout << "\n Balance :- " << savbal;
		std::cout << "\n Press any key to continue...\n";
		system("read");
	}
	void deposit_savbal() {
		float deposit, interest;
		std::cout << "\nEnter amount to Deposit :- ";
		std::cin >> deposit;
		savbal = savbal + deposit;
		if (savbal <= 10000){
			interest = savbal * 1 / 100;
		}
		if (savbal > 10000){
			interest = savbal * 2 / 100;
		}
		savbal = savbal + interest;
	}
	void withdraw_savbal() {
		float withdraw;
		std::cout << "\nBalance :- " << savbal;
		std::cout << "\nEnter amount to be withdraw :-";
		std::cin >> withdraw;
		savbal = savbal - withdraw;
		if (withdraw > savbal) {
			std::cout << "\n\nYou have to take permission for Bank Overdraft Facility\n";
			savbal = savbal + withdraw;
		}
		else
			savbal = savbal - 2;
		std::cout << "\nAfter Withdrawl your Balance revels : " << savbal;
	}
};

float cur_acct::balance;
float sav_acct::savbal;

int main() {
	printf("\e[1;1H\e[2J");
	cur_acct c1;
	sav_acct s1;

	std::cout << "\nEnter S for saving customer and C for current a/c customer\n\n";
	char type;
	std::cin >> type;

	int choice;

	if (type == 's' || type == 'S') {
		s1.get_accinfo();
		while (1) {
			printf("\e[1;1H\e[2J");
			std::cout << "\nChoose Your Choice\n";
			std::cout << "1) Deposit\n";
			std::cout << "2) Withdraw\n";
			std::cout << "3) Display Balance\n";
			std::cout << "4) Display with full Details\n";
			std::cout << "5) Exit\n";
			std::cout << "6) Choose Your choice:-";
			std::cin >> choice;
			switch (choice) {
			case 1:
				s1.deposit_savbal();
				break;
			case 2:
				s1.withdraw_savbal();
				break;
			case 3:
				s1.disp_savbal();
				break;
			case 4:
				s1.display_accinfo();
				s1.disp_savbal();
				break;
			case 5:
				goto end;
			default:
				std::cout << "\n\nEntered choice is invalid,\"TRY AGAIN\"";
			}
		}
	}
	else {
		c1.get_accinfo();
		while (1) {
			std::cout << "\nChoose Your Choice\n";
			std::cout << "1) Deposit\n";
			std::cout << "2) Withdraw\n";
			std::cout << "3) Display Balance\n";
			std::cout << "4) Display with full Details\n";
			std::cout << "5) Exit\n";
			std::cout << "6) Choose Your choice:-";
			std::cin >> choice;
			switch (choice) {
			case 1:
				c1.deposit_currbal();
				break;
			case 2:
				c1.withdraw_currbal();
				break;
			case 3:
				c1.disp_currbal();
				break;
			case 4:
				c1.display_accinfo();
				c1.disp_currbal();
				break;
			case 5:
				goto end;
			default:
				std::cout << "\n\nEntered choice is invalid,\"TRY AGAIN\"";
			}
		}
	}
end:
	return 0;
}