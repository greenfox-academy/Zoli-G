#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
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
    unsigned int bn20k, bn10k, bn5k, bn2k, bn1k;
    unsigned int p20k, p10k, p5k, p2k, p1k;
public:
	ATM(unsigned int bn20k, unsigned int bn10k, unsigned int bn5k, unsigned int bn2k, unsigned int bn1k) : bn20k(bn20k), bn10k(bn10k), bn5k(bn5k), bn2k(bn2k), bn1k(bn1k) {
		userLogged = -1;
		adminLogged = false;
		UserList.clear();
		p20k = p10k = p5k = p2k = p1k = 0;
	}
	//---Add bank customer------------------------------------
    void addUser(string name, unsigned int pincode, float money, bool is_admin) {
    	user_data newuser(name, pincode, money, is_admin);
        UserList.push_back(newuser);
    }
    //---Check if it is a valid user pin or not---------------
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
    //---Print richest customer-------------------------------
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
    bool checkBanknotesForPayout(unsigned int money) {
    	//Reset payout board
		p20k = p10k = p5k = p2k = p1k = 0;

		//If the user wants to withdraw more money than present at the ATM -> not possible
		if (money > bn20k*20000 + bn10k*10000 + bn5k*5000 + bn2k*2000 + bn1k*1000) {
			return false;
		}

		//Fill up payout board values with possible combination of banknotes
		p20k = min((money - money % 20000) / 20000, bn20k); money -= p20k * 20000;
		p10k = min((money - money % 10000) / 10000, bn10k); money -= p10k * 10000;
		 p5k = min((money - money %  5000) /  5000, bn5k);  money -=  p5k *  5000;
		 p2k = min((money - money %  2000) /  2000, bn2k);  money -=  p2k *  2000;
		 p1k = min((money - money %  1000) /  1000, bn1k);  money -=  p1k *  1000;

		//If the combination was complete:
		return (money == 0 ? true : false);
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
					 cout << "\tATM balance: " << (bn20k*20 + bn10k*10 + bn5k*5 + bn2k*2 + bn1k) * 1000 << "Ft." << endl;
					 cout << "\t20.000Ft (" << bn20k << "), 10.000Ft (" << bn10k << "), 5.000Ft (" << bn5k << "), 2.000Ft (" << bn2k << "), 1000Ft (" << bn1k << ")" << endl;
					 cout << "\t------------" << endl;
					 break;
			case 2 : bn20k = bn10k = bn5k = bn2k = bn1k  = 10;
					 cout << "\t--------------------------------" << endl;
					 cout << "\tATM money filled with 380.000 Ft" << endl;
					 cout << "\t--------------------------------" << endl;
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
		} else if (checkBanknotesForPayout(money) == false) {
			cout << "\t------------------------------------------------------------" << endl;
            cout << "\tWe're sorry, but the asked money is not payable by this ATM." << endl;
			cout << "\t------------------------------------------------------------" << endl;
		} else {
			UserList.at(userLogged).withdrawMoney(money);
			bn20k -= p20k;
			bn10k -= p10k;
			bn5k -= p5k;
			bn2k -= p2k;
			bn1k -= p1k;
			cout << "\t--------------------------------" << endl;
			cout << "\t-----------Z-Bank-Recept--------" << endl;
			cout << "\t--------------------------------" << endl;
			cout << "\tTransaction: success" << endl;
			cout << "\t     ATM cash: " << money << " Ft" << endl;
			cout << endl;
			cout << "\tBanknotes received:" << endl;
			cout << "\t     20.000Ft - " << p20k << "pc" << endl;
			cout << "\t     10.000Ft - " << p10k << "pc" << endl;
			cout << "\t      5.000Ft - " << p5k << "pc" << endl;
			cout << "\t      2.000Ft - " << p2k << "pc" << endl;
			cout << "\t      1.000Ft - " << p1k << "pc" << endl;
			cout << endl;
			time_t t = time(NULL);
			tm* timePtr = localtime(&t);
			cout << "\t" << timePtr->tm_year + 1900 << "." << timePtr->tm_mon << "." << timePtr->tm_mday << " " << timePtr->tm_hour << ":" << timePtr->tm_min << ":" << timePtr->tm_sec << endl;
			cout << "\t--------------------------------" << endl;
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

	//Create ATM object with starting amount of money (10pc's of each banknotes)
	ATM ATM_Machine(10, 10, 10, 10, 10);

	//Fill users data
    ATM_Machine.addUser("Zoli", 1234, 173500, false);
    ATM_Machine.addUser("Adam", 4321, 100500.5, false);
    ATM_Machine.addUser("Gergo", 3455, 234566.1, false);
	ATM_Machine.addUser("ATM Money Ltd.", 12345678, 0, true);

	ATM_Machine.ATMMenu();
    return 0;
}
