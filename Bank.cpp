#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h> // Windows??????????
#include <sstream>
#include <ctime>
using namespace std;

void Log_in_panel();
void Bank_page();
void Commands_panel();
void Account_info();
void Deposit();
void Withdrawl();
void Balance();
void History();

string choice, username, password, check_username, check_password, lastname,lastline,line,true_deposit,true_withdrawl;

int bank_card_id, date, month, year, bank_choice, money, true_balance;

int main() {
  cout << "\033[2J\033[H"; // Windows???????
  usleep(1000000);  // 1?????
  Log_in_panel();
  return 0;
}

void Log_in_panel() {
  cout << "\tWelcome to the Central-Bank\n" << endl;
  cout << "Enter <<Log>> to log in to your account " << endl;
  cout << "Enter <<Reg>> For registration \n" << endl;
  cout << "Enter your choice -> ";
  cin >> choice;
  if (choice == "Log" || choice == "log") {
    cout << "\nPlease enter your username\n>>>";
    cin >> username;
    cout << "\nPlease enter your password\n>>>";
    cin >> password;
    
    ifstream read(username + ".txt");
    getline(read, check_username);
    getline(read, check_password);
    ifstream rod(username + "bk.txt");
    while(getline(rod,line)){
      lastline =line;
    }
    stringstream ss(lastline);
    ss>>true_balance;
    rod.close(); // Close the file stream

    if (username == check_username && password == check_password) {
      usleep(1000000);         // 1?????
      cout << "\033[2J\033[H"; // Windows???????
      Bank_page();
    } else {
      cout << "\nUser is not found\n" << endl;
      usleep(1000000); // 1?????
      cout << "Please check your username/password" << endl;
      usleep(2000000);             // 2?????
      cout << "\033[2J\033[H"; // Windows???????
      Log_in_panel();
    }
 }
  else if (choice == "Reg" || choice == "reg") {
    cout << "\nPlease enter your familyname\n>>>";
    cin >> username;
    cout << "\nPlease enter your lastname\n>>>";
    cin >> lastname;
    cout << "\nPlease enter your password\n>>>";
    cin >> password;
    cout << "Enter your date ->";
    cin >> date;
    cout << "Enter your month ->";
    cin >> month;
    cout << "Enter your year ->";
    cin >> year;

    ofstream personal_users_info;

    personal_users_info.open(username + "pr.txt",
                             ofstream::out | ofstream::app);
    personal_users_info << "Name: " << username << " " << lastname << endl
                        << "Password: " << password << endl
                        << "Date: " << date << "/" << month << "/" << year
                        << endl;
    personal_users_info.close();

    ofstream user_file;
    user_file.open(username + ".txt", ofstream::out | ofstream::app);
    user_file << username << endl << password;
    user_file.close();

    cout << "\nYou finished your registration" << endl;
    usleep(1000000);         // 1?????
    cout << "\033[2J\033[H"; // Windows???????
    Bank_page();
  } else {
    cout << "\nCommand is not found\n" << endl;
    usleep(1000000); // 1?????
    cout << "Please try again!\n" << endl;
    usleep(1000000);         // 2?????
    cout << "\033[2J\033[H"; // Windows???????
    Log_in_panel();
  }
}

void Bank_page() {
  cout << "\tWelcome to the Bank page, " << username << endl << endl;
  cout << "===================================================" << endl;
  cout << "| "
       << "[1] ---> Account info"
       << "                         |" << endl;
  cout << "| "
       << "[2] ---> Deposit"
       << "                              |" << endl;
  cout << "| "
       << "[3] ---> Check balance"
       << "                        |" << endl;
  cout << "| "
       << "[4] ---> Withdrawl"
       << "                            |" << endl;
  cout << "| "
       << "[5] ---> History"
       << "                              |" << endl;
  cout << "| "
       << "[6] ---> Exit"
       << "                                 |" << endl;
  cout << "===================================================" << endl;
  cout << endl;
  while (bank_choice != 6) {
    cout << "Enter the command -> ";
    cin >> bank_choice;
    Commands_panel();
  }
}

void Commands_panel() {
  switch (bank_choice) {
  case 0:
    cout << "\033[2J\033[H";
    Bank_page();
    break;
  case 1:
    cout << "\033[2J\033[H";
    Account_info();
    break;
  case 2:
    cout << "\033[2J\033[H";
    Deposit();
    break;
  case 3:
    cout << "\033[2J\033[H";
    Balance();
    break;
  case 4:
    cout << "\033[2J\033[H";
    Withdrawl();
    break;
  case 5:
    cout << "\033[2J\033[H";
    History();
    break;
  case 6:
    cout << "\nYou left the Bank app\n" << endl;
    usleep(1000000); // 1?????
    break;
  default:
    cout << "\nCommand is not found" << endl;
    cout << "\033[2J\033[H";
    Bank_page();
  }
}

void Account_info() {
  cout << "Your personal information\n" << endl;
  usleep(1000000); // 1?????
  ifstream tiop(username + "pr.txt");
  char ch;
  while (tiop.get(ch)) {
    cout << ch;
  }
  usleep(1000000); // 1?????
  cout << "Enter [0] to go back\n " << endl;
  usleep(1000000); // 1?????
}

void Deposit() {
  cout << "\tDeposit page\n" << endl;
  cout << "Enter the amount of money -> ";
  cin >> money;

  if (money > 1000) {
    usleep(1000000); // 1?????
    cout << "\nLoading...\n" << endl;
    usleep(2000000); // 2?????
    cout << "\nToo big number, please try again!\n" << endl;
    usleep(2000000);             // 2?????
    cout << "\033[2J\033[H"; // Windows???????
    Deposit();
  } else if (money < 0) {
    usleep(1000000); // 1?????
    cout << "\nLoading...\n" << endl;
    usleep(2000000); // 2?????
    cout << "\nCan not enter negative number, please try again!\n" << endl;
    usleep(2000000);// 2?????
    cout << "\033[2J\033[H"; // Windows???????
    Deposit();
  } else {
    usleep(1000000); // 1?????
    cout << "\nLoading...\n" << endl;
    true_balance += money;
    true_deposit = to_string(money);
    ofstream bank_info;

    bank_info.open(username + "bk.txt",
                             ofstream::out | ofstream::app);
    bank_info <<true_balance << endl;
    bank_info.close();
    time_t now = time(0); // Get the current time
    tm* timeinfo = localtime(&now); // Convert to tm structure
    bank_info.open(username + "dep.txt",
                             ofstream::out | ofstream::app);
    bank_info << timeinfo->tm_mday << "/" 
              << timeinfo->tm_mon + 1 << "/" 
              << timeinfo->tm_year +1900<< " "
              << timeinfo->tm_hour + 7 << ":" 
              << timeinfo->tm_min << ":" 
              << timeinfo->tm_sec << endl;

    bank_info <<"+$"<<true_deposit<< endl;
    bank_info.close();
    
    usleep(2000000); // 2?????
    cout << "Deposit added successfully\n" << endl;
    usleep(2000000);             // 2?????
    cout << "\033[2J\033[H"; // Windows???????
    Bank_page();
  }
}
void Balance() {
  cout << "Your balance information\n" << endl;
  cout << "Name: " << username << " " << lastname << endl;
  usleep(2000000);// 2?????
  cout << "\nYour current balance is $" << true_balance << endl;
  char yn;
  cout << "\nDo you want to put money on your card(y/n) -> ";
  cin >> yn;

  if (yn == 'y') {
    usleep(3000000);// 3?????
    cout << "\033[2J\033[H"; // Windows???????
    Deposit();
  } else if (yn == 'n') {
    cout << "\nYour balance is still the same\n" << endl;
    usleep(2000000);             // 2?????
    cout << "\033[2J\033[H"; // Windows???????
    Bank_page();
  } else {
    cout << "\nCommand is not found, please try again!\n" << endl;
    usleep(2000000);// 2?????
    cout << "\033[2J\033[H"; // Windows???????
    Balance();
  }
}

void Withdrawl() {
  cout << "\tWithdrawl page\n" << endl;
  cout << "Enter the amount of money -> ";
  cin >> money;
  if (true_balance < money) {
    usleep(1000000); // 1?????
    cout << "\nLoading...\n" << endl;
    usleep(2000000); // 2?????
    cout << "\nYou do not have enough money on your card!\n" << endl;
    usleep(2000000);
    cout << "\033[2J\033[H"; // Windows???????
    Bank_page();
  } else if (money < 0) {
    usleep(1000000); // 1?????
    cout << "\nLoading...\n" << endl;
    usleep(2000000); // 2?????
    cout << "\nCan not enter negative number, please try again!\n" << endl;
    usleep(2000000);             // 2?????
    cout << "\033[2J\033[H"; // Windows???????
    Withdrawl();
  }
  else {
      usleep(1000000); // 1?????
      cout << "\nLoading...\n" << endl;
      usleep(2000000); // 2?????
      cout << "Withdrawal added successfully\n" << endl;
      true_balance -= money;
      true_withdrawl = to_string(money);
      ofstream bank_info;

      bank_info.open(username + "bk.txt",
                               ofstream::out | ofstream::app);
      bank_info <<true_balance << endl;
      bank_info.close();
      time_t now = time(0); // Get the current time
      tm* timeinfo = localtime(&now); // Convert to tm structure
      bank_info.open(username + "wid.txt",
                               ofstream::out | ofstream::app);
      bank_info <<  timeinfo->tm_mday << "/" 
        << timeinfo->tm_mon + 1 << "/" 
        << timeinfo->tm_year +1900<< " "
        << timeinfo->tm_hour + 7 << ":" 
        << timeinfo->tm_min << ":" 
        << timeinfo->tm_sec << endl;
      bank_info <<"-$"<<true_withdrawl<< endl;
      bank_info.close();
    
      usleep(2000000); // 2?????
      cout << "You took out $" << money << endl;
      cout << "Your balance is now $" << true_balance << endl;
      usleep(2000000);            // 2?????
      cout << "\033[2J\033[H"; // Windows???????
      Bank_page();
  }
}

void History() {
  usleep(1000000); // 1?????
  cout <<"\tHistory page\n"<<endl;
  usleep(1000000); // 1?????
  cout << "Deposit History\n" << endl;
  ifstream read(username + "dep.txt");
  char ch1;
  while (read.get(ch1)) {
    cout << ch1;
  }
  cout<<endl<<endl;
  cout << "Withdrawl History\n" << endl;
  ifstream rod(username + "wid.txt");
  char ch2;
  while (rod.get(ch2)){
    cout << ch2;
  }
  cout<<endl<<endl;
  usleep(1000000); // 1?????
  cout << "Enter [0] to go back\n " << endl;
}
