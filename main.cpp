#include <iostream>
#include <vector>

struct Account
{
  std::string name;
  int account_id;
  double chequings_account;
  double savings_account;
};

struct Account add_record(std::string,  double, double);
void display_data(std::vector<struct Account>);
void search_record(std::vector<struct Account>, int);
void create_account(std::vector<struct Account>&);
void edit_record(std::vector<struct Account>&, int);
void delete_record(std::vector<struct Account>&, int);

int main()
{
  // Store created accounts
  std::vector<struct Account> account_users;

  while (program) {
    std::cout << "\n\n---------------------------------------------------------\n";
    std::cout << "|\t\tACCOUNT INFORMATION SYSTEM \t\t|\n";
    std::cout << "---------------------------------------------------------\n";
    std::cout << "|\t -> 1. Show all records\t\t\t\t|\n";
    std::cout << "|\t -> 2. Search record from file\t\t\t|\n";
    std::cout << "|\t -> 3. Add record to a file\t\t\t|\n";
    std::cout << "|\t -> 4. Update record\t\t\t\t|\n";
    std::cout << "|\t -> 5. Delete record\t\t\t\t|\n";
    std::cout << "|\t -> 6. Quit\t\t\t\t\t|\n";
    std::cout << "---------------------------------------------------------\n\n";

    int choice;
    std::cout << "Select an option: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        display_data(account_users);
        continue;
      case 2:
        std::cout << "Enter user ID: ";
        int search_acc_id;
        std::cin >> search_acc_id;
        search_record(account_users, search_acc_id);
        continue;
      case 3:
        create_account(account_users);
        continue;
      case 4:
        std::cout << "Enter user ID: ";
        int edit_acc_id;
        std::cin >> edit_acc_id;
        edit_record(account_users, edit_acc_id);
        continue;
      case 5:
        // Check if there are accounts in the database first
        if (account_users.size() == 0) {
          std::cout << "The database is not populated" << std::endl;
          break;
        }
        // Delete User
        std::cout << "Enter user ID: ";
        int delete_acc_id;
        std::cin >> delete_acc_id;
        delete_record(account_users, delete_acc_id);
        continue;
      case 6:
        break;
    }
  }

  std::cout << "Until next time!!" << std::endl;

  return 0;
}

void display_data(std::vector<struct Account> accnt_users)
{
  int count = 0;
  std::cout<< "-----------------------------------------------------------------------------------------\n";
  std::cout << "|\tID\t|\tName\t\t|\tChequings\t|\tSavings\t\t|\n";
  std::cout<< "-----------------------------------------------------------------------------------------\n";
  for (int i=0; i<accnt_users.size(); ++i) {
    std::cout << "|     " << accnt_users[i].account_id << "\t|\t" << accnt_users[i].name << "\t\t|\t " << accnt_users[i].chequings_account << "\t\t|\t" << accnt_users[i].savings_account << "\t\t|\n";
    std::cout<< "-----------------------------------------------------------------------------------------\n";
    ++count;
  }

  if (count == 0)
    std::cout << "No existing users";
}

void search_record(std::vector<struct Account> accnt_users, int accnt_id)
{
  /* std::cout << id.name << std::endl; */
  bool user_found = false;
  for (int i=0; i<accnt_users.size(); ++i) {
    auto existing_user = accnt_users[i].account_id == accnt_id;
    if (existing_user) {
      user_found = true;
      std::cout << "Name: " << accnt_users[i].name << std::endl;
      std::cout << "User ID: " << accnt_users[i].account_id << std::endl;
      std::cout << "Chequings: " << '$' << accnt_users[i].chequings_account << std::endl;
      std::cout << "Savings: " << '$' << accnt_users[i].savings_account << std::endl;
    }
  }
  if (!user_found)
    std::cout << "User does not exist";
}

void create_account(std::vector<struct Account> &vect)
{
  bool add_account = true;
  while (add_account) {
      char new_account;
      std::string name;
      double chequings = 0;
      double savings = 0;

      std::cout << "\nPlease enter your name: ";
      std::cin >> name;

      std::cout << "Enter chequing balance: ";
      std::cin >> chequings;

      std::cout << "Enter savings balance: ";
      std::cin >> savings;

      // Generate a random account number
      srand(time(NULL));
      int account_id =  rand() % ((199999 - 100000) + 1) + 100000;

      // Create and return account
      struct Account new_accnt = {name, account_id, chequings, savings};
      std::cout << "\nAccount created successfully " << std::endl;

      // Store account
      vect.push_back(new_accnt);

      search_record(vect, new_accnt.account_id);

      // Ask if user wants to create another account
      std::cout << "\nAdd another account? (y/n): ";
      std::cin >> new_account;

      switch (new_account) {
        case 'y':
          continue;
        case 'n':
          add_account = false;
          break;
        default:
          std::cout << "Enter either y or n." << std::endl;
      }
  }
}

void edit_record(std::vector<struct Account> &accnt_users, int accnt_id)
{
  // Print User info
  for (int i=0; i<accnt_users.size(); ++i) {
    bool existing_user = accnt_users[i].account_id == accnt_id;
    if (existing_user) {
      std::cout << "Name: " << accnt_users[i].name << std::endl;
      std::cout << "User ID: " << accnt_users[i].account_id << std::endl;
      std::cout << "Chequings: " << '$' << accnt_users[i].chequings_account << std::endl;
      std::cout << "Savings: " << '$' << accnt_users[i].savings_account << std::endl;
    }
  } 

  std::string new_name;
  double new_cheque_balance, new_savings_balance;

  std::cout << "\nEnter name: ";
  std::cin >> new_name;
  std::cout << "Enter chequing balance: ";
  std::cin >> new_cheque_balance;
  std::cout << "Enter savings balance: ";
  std::cin >> new_savings_balance;

  // Display account with new info
  std::cout << "Name: " << new_name << std::endl;
  std::cout << "Chequings: $" << new_cheque_balance<< std::endl;
  std::cout << "Savings: $" << new_savings_balance << std::endl;

  // Confirm user change
  char user_change;
  std::cout << "Confirm change? (y/n): ";
  std::cin >> user_change;
  if (user_change == 'y') {
    for (int i=0; i<accnt_users.size(); ++i) {
      bool existing_user = accnt_users[i].account_id == accnt_id;
      if (existing_user) {
        accnt_users[i].name = new_name;
        accnt_users[i].chequings_account = new_cheque_balance;
        accnt_users[i].savings_account = new_savings_balance;
        std::cout << "\nSuccessfully Updated profile\n";
      }
    }
  } else {
    std::cout << "No changes made" << std::endl;
  }
}

void delete_record(std::vector<struct Account> &accnt_users, int accnt_id)
{
  // Print User info
  int user_index;
  bool user_found = false;
  for (int i=0; i<accnt_users.size(); ++i) {
    bool existing_user = accnt_users[i].account_id == accnt_id;
    if (existing_user) {
      user_index = i;
      user_found = true;
      std::cout << "Name: " << accnt_users[i].name << std::endl;
      std::cout << "User ID: " << accnt_users[i].account_id << std::endl;
      std::cout << "Chequings: " << '$' << accnt_users[i].chequings_account << std::endl;
      std::cout << "Savings: " << '$' << accnt_users[i].savings_account << std::endl;
    } 
    // If there are no users in the database or user is not in database
    if (i == accnt_users.size() && user_found == false) {
      std::cout << "\nAccount does not exist in database\n";
      break;
    }
  }

  char delete_user;
  std::cout << "\nAre you sure you want to delete user " << accnt_users[user_index].account_id << "? (y/n): ";
  std::cin >> delete_user;
  if (delete_user == 'y') {
    accnt_users.erase(accnt_users.begin()+user_index);
    std::cout << "\nAccount successfully deleted";
  }
}
