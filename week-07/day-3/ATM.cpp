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
    string admin_password = "admin123";
public:
    void addUser(user_data ud) {
        UserList.push_back(ud);
    }
    //string getATMAdminPass() {
    //    return admin_password;
    //}
    unsigned int getUserPin(unsigned int index) {
        return UserList.at(index).getPincode();
    }
    unsigned int getUserCount() {
        return UserList.size();
    }
    //Check if  it is an ATM admin password
    int ValidatePassInput(string input_pass) {
        if (input_pass == admin_password) {
            cout << "Admin logged in." << endl;
            return 9999;    //Admin logged in
        }
        cout << "Admin login failed." << endl;
        return -1;          //False password
    }
    //Check if it is a user password
    int ValidateInput(unsigned int input_pass) {
        for (int i = 0; i < UserList.size(); ++i) {
            if (input_pass == UserList.at(i).getPincode()) {
                cout << "User " << UserList.at(i).getName() << " logged in." << endl;
                return i;    //User logged in, return user index in vector
            }
        }
        cout << "User login failed." << endl;
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
void MainScreen();
int ValidateInput(string);
int ValidateInput(unsigned int);

int main() {

    user_data u1("Zoli", 1234, 73500);
    user_data u2("Adam", 4321, 10500.5);
    user_data u3("Gergo", 3455, 234566.1);

    Users BankUsers;
    BankUsers.addUser(u1);
    BankUsers.addUser(u2);
    BankUsers.addUser(u3);

    BankUsers.printRichestCostumer();

    MainScreen();
    unsigned int input_pin = 0;
    cin >> input_pin;
    BankUsers.ValidateInput(input_pin);

    return 0;
}

void MainScreen() {
    cout << "Welcome to the Z-Bank" << endl;
    cout << "---------------------" << endl;
    cout << "Please enter your PIN code: " << endl;
}
