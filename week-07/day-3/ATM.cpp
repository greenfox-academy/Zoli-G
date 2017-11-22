#include <iostream>
#include <vector>
using namespace std;

class user_data {
public:
    user_data(string name, unsigned int pincode, float money) : name(name), pincode(pincode), money(money) {}
    float getMoney() {
        return money;
    }
    string getName() {
        return name;
    }
    unsigned int getPincode() {
        return pincode;
    }
private:
    string name;
    unsigned int pincode;
    float money;
};
//------------------------------
class Users {
private:
    vector<user_data> UserList;
    //ATM password
    unsigned int admin_password = 12345678;
public:
    void addUser(user_data ud) {
        UserList.push_back(ud);
    }
    unsigned int getUserPin(unsigned int index) {
        return UserList.at(index).getPincode();
    }
    unsigned int getUserCount() {
        return UserList.size();
    }
    //Check if it is a user password
    int ValidatePassInput(unsigned int input_pass) {
        for (int i = 0; i < UserList.size(); ++i) {
            if (input_pass == UserList.at(i).getPincode()) {
                cout << "User " << UserList.at(i).getName() << " logged in." << endl;
                return i;    //User logged in, return user index in vector
            }
        }
        if (input_pass == admin_password) {
            cout << "Admin logged in." << endl;
            return 9999;
        }
        cout << "Login failed." << endl;
        return -1;          //False password
    }
    //Print richest customer
    void printRichestCostumer() {
        float max_money = 0;
        unsigned int max_index = 0;
        for (int i = 0; i < UserList.size(); ++i) {
            if (UserList.at(i).getMoney() > max_money) {
                max_money = UserList.at(i).getMoney();
                max_index = i;
            }
        }
        cout << "Our Banks richest costumer is: " << UserList.at(max_index).getName();
    }
};

//Function prototypes
unsigned int MainScreen();
unsigned int UserMenu();
unsigned int AdminMenu();

int main() {

    user_data u1("Zoli", 1234, 73500);
    user_data u2("Adam", 4321, 10500.5);
    user_data u3("Gergo", 3455, 234566.1);

    Users BankUsers;
    BankUsers.addUser(u1);
    BankUsers.addUser(u2);
    BankUsers.addUser(u3);

    //BankUsers.printRichestCostumer();
    unsigned int input;
    while (input = MainScreen(), input != 0) {

    }
    cout << "--------" << endl;
    cout << "Goodbye!" << endl;

    //BankUsers.ValidatePassInput(input_pin);

    return 0;
}

unsigned int MainScreen() {
    unsigned int input_pin;

    cout << "Welcome to the Z-Bank" << endl;
    cout << "---------------------" << endl;
    cout << "Please enter your PIN code or [0] to exit: ";
    cin >> input_pin;
    return input_pin;
}

unsigned int UserMenu() {
    unsigned int money;

    cout << "Enter money to withdraw: ";
    cin >> money;

    return money;
}

unsigned int AdminMenu() {
    unsigned int money;

    cout << "Enter money to deposit in ATM: ";
    cin >> money;

    return money;
}
