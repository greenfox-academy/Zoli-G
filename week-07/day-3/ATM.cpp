#include <iostream>
#include <vector>
using namespace std;

class ATM {
private:
    string admin_password = "admin123";
public:
    string getATMAdminPass() {
        return admin_password;
    }
    //bool validATMPassword(string inputPass) {
    //    return (inputPass == admin_password ? true : false);
    //}
};

class user_data {
public:
    user_data(string name, unsigned int pincode, float money) : name(name), pincode(pincode), money(money) {}
    float getMoney() {
        return money;
    }
    string getName() {
        return name;
    }
private:
    string name;
    unsigned int pincode;
    float money;
};

class Users {
private:
    vector<user_data> UserList;
public:
    void addUser(user_data ud) {
        UserList.push_back(ud);
    }
    unsigned int getUserPin(unsigned int index) {
        return UserList.at(index).pincode;
    }
    unsigned int getUserCount() {
        return UserList.size();
    }
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

class Customer : public Users {

};

class Administrator : public Users {

};

int main() {

    user_data u1("Zoli", 1234, 73500);
    user_data u2("Adam", 4321, 10500.5);
    user_data u3("Gergo", 3455, 234566.1);

    Users BankUsers;
    BankUsers.addUser(u1);
    BankUsers.addUser(u2);
    BankUsers.addUser(u3);

    ATM BankATM;

    BankUsers.printRichestCostumer();

    return 0;
}

void MainScreen() {
    unsigned int input_pin = 0;

    cout << "Welcome to the Z-Bank" << endl;
    cout << "---------------------" << endl;
    cout << "Please enter your PIN code: " << endl;
    cin >> input_pin;

    if () {
        cout << ""
    }
}

//Check if  it is an ATM admin password
int ValidateInput(string input_pass) {
    if (input_pass == BankATM.getATMAdminPass()) {
        return 9999;    //Admin logged in
    }
    return -1;          //False password
}

//Check if it is a user password
int ValidateInput(unsigned int input_pass) {
    for (int i = 0; i < BankUsers.getUserCount(); ++i) {
        if (input_pass == BankUsers.getUserPin(i)) {
            return i;    //User logged in, return user index in vector
        }
    }
    return -1;          //False password
}
