#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class user_data {
public:
    user_data(string name, unsigned int pincode, float money, bool is_admin) : name(name), pincode(pincode), money(money), is_admin(is_admin) {}
    string getName() {
        return name;
    }
    unsigned int getPincode() {
        return pincode;
    }
    float getMoney() {
        return money;
    }
    bool getAdminAccess() {
		return is_admin;
    }
    float withdrawMoney(unsigned int money) {
        this->money -= money;
    }
private:
    string name;
    unsigned int pincode;
    float money;
    bool is_admin;
};
//------------------------------
class ATM {
private:
	//User info
    int userLogged;
    bool adminLogged;
    vector<user_data> UserList;
    //ATM money stored
    unsigned int ATM_money;
public:
	ATM(unsigned int ATM_money) : ATM_money(ATM_money) {
		userLogged = -1;
		adminLogged = false;
		UserList.clear();
	}

    void addUser(string name, unsigned int pincode, float money, bool is_admin) {
    	user_data newuser(name, pincode, money, is_admin);
        UserList.push_back(newuser);
    }

    //Check if it is a valid user pin or not
    void setUserLogin(unsigned int pin) {
        for (int i = 0; i < UserList.size(); ++i) {
            if (pin == UserList.at(i).getPincode()) {
                userLogged = i;
                adminLogged = UserList.at(i).getAdminAccess();
                cout << endl << "\tWelcome " << UserList.at(i).getName() << "!" << endl;
                return;
            }
        }
        cout  << "\tLogin failed." << endl;
    }

    //Print richest customer
    string getRichestCostumer() {
        float max_money = 0;
        unsigned int max_index = 0;
        for (int i = 0; i < UserList.size(); ++i) {
            if (UserList.at(i).getMoney() > max_money) {
                max_money = UserList.at(i).getMoney();
                max_index = i;
            }
        }
        return UserList.at(max_index).getName();
    }
    //--------------------------------------------------------
	void ATMScreenWelcome() {
		system("cls");
		cout << "===================================" << endl;
		cout << "*       Welcome to the Z-Bank!    *" << endl;
		cout << "-----------------------------------" << endl;
		cout << "The future of the reliable banking." << endl;
		cout << "-----------------------------------" << endl;
        cout << endl;
	}
	void ATMPinPromt() {
		unsigned int pin;
		do {
			cout << "Please enter your PIN number: ";
			cin >> pin;

			if (cin.good())				//If entered pin matches the type of "pin"...
				setUserLogin(pin);		//...call login function

			cin.clear();				//Clear error flag...
			cin.ignore(INT_MAX, '\n');	//...and ignore all the entered stuff from input buffer.
		} while (userLogged == -1);		//Ask for PIN while someone not logged in successfully.
	}
	void ATMAdminMenu() {
		unsigned int menu;
		do {
			cout << endl;
			cout << "[1] - Query ATM current balance" << endl;
			cout << "[2] - Deposit money to ATM" << endl;
			cout << "[3] - Get customer with the highest account value" << endl;
			cout << "[4] - Logout & return to main menu..." << endl;
			cout << "[ ]: ";
			cin >> menu;

			switch (menu) {
			case 1 : cout << "\t------------" << endl;
					 cout << "\tATM balance: " << ATM_money << "Ft." << endl;
					 cout << "\t------------" << endl;
					 break;
			case 2 : ATM_money = 10000000;
					 cout << "\t-----------------------------------" << endl;
					 cout << "\tATM money filled with 10.000.000 Ft" << endl;
					 cout << "\t-----------------------------------" << endl;
					 break;
			case 3 : cout << "\t---------------------------------" << endl;
					 cout << "\tUser with the highest deposit is: " << getRichestCostumer() << endl;
					 cout << "\t---------------------------------" << endl;
					 break;
			}
        } while (menu != 4);
	}
	void ATMUserMenu() {
		unsigned int menu;
		do {
			cout << endl;
			cout << "[1] - View Your account balance" << endl;
			cout << "[2] - Withdraw money" << endl;
			cout << "[3] - Logout & return to main menu..." << endl;
			cout << "[ ]: ";
			cin >> menu;

			switch (menu) {
			case 1 : cout << "\t-------------" << endl;
					 cout << "\tYour balance: " << UserList.at(userLogged).getMoney() << "Ft." << endl;
					 cout << "\t-------------" << endl;
					 break;
			case 2 : ATMUserWithdraw();
					 break;
			}
		} while (menu != 3);
	}
	void ATMUserWithdraw() {
		unsigned int money;
		cout << "Enter money to withdraw: ";
		cin >> money;

		if (!cin.good()) {
			cout << "Wrong input!" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			return;
		}

		if (money % 1000 != 0) {
			cout << "\t-----------------------------" << endl;
            cout << "\tSmallest banknote is 1000 Ft." << endl;
			cout << "\t-----------------------------" << endl;
		} else if (money > UserList.at(userLogged).getMoney()) {
			cout << "\t-----------------------------------" << endl;
            cout << "\tNot enough money to withdraw money." << endl;
			cout << "\t-----------------------------------" << endl;
		} else {
			UserList.at(userLogged).withdrawMoney(money);
			ATM_money -= money;
			cout << "\t----------------------------------" << endl;
			cout << "\tSuccess. Remove money from drawer." << endl;
			cout << "\t----------------------------------" << endl;
		}
	}
	void ATMLogout() {
		cout << endl << "Logging out...";
		Sleep(2000);
		userLogged = -1;
		adminLogged = false;
	}
    void ATMMenu() {
    	while(1) {
			ATMScreenWelcome();
			ATMPinPromt();

			switch (adminLogged) {
			case false : ATMUserMenu(); break;
			case true : ATMAdminMenu(); break;
			}
			ATMLogout();
    	}
    }
};

int main() {

	//Create ATM object with starting amount of money and an admin password
	ATM ATM_Machine(1000000);

	//Fill users data
    ATM_Machine.addUser("Zoli", 1234, 73500, false);
    ATM_Machine.addUser("Adam", 4321, 10500.5, false);
    ATM_Machine.addUser("Gergo", 3455, 234566.1, false);
	ATM_Machine.addUser("ATM Money Ltd.", 12345678, 0, true);

	ATM_Machine.ATMMenu();
    return 0;
}
