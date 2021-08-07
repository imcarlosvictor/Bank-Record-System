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
void edit_record();
void delete_record();

int main()
{
  // Store created accounts
  std::vector<struct Account> account_users;

  bool program = true;
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
        std::cout << "Enter user account number: ";
        int acc_id;
        std::cin >> acc_id;
        search_record(account_users, acc_id);
        continue;
      case 3:
        create_account(account_users);
        continue;
      case 4:
        edit_record();
        continue;
      case 5:
        delete_record();
        continue;
      case 6:
        program = false;
        break;
    }
  }

  std::cout << "Until next time!!" << std::endl;

  return 0;
}

void display_data(std::vector<struct Account> acc_users)
{
  int count = 0;
  std::cout<< "-----------------------------------------------------------------------------------------\n";
  std::cout << "|\tID\t|\tName\t\t|\tChequings\t|\tSavings\t\t|\n";
  std::cout<< "-----------------------------------------------------------------------------------------\n";
  for (int i=0; i<acc_users.size(); ++i) {
    std::cout << "|     " << acc_users[i].account_id << "\t|\t" << acc_users[i].name << "\t\t|\t " << acc_users[i].chequings_account << "\t\t|\t" << acc_users[i].savings_account << "\t\t|\n";
    ++count;
  }

  if (count == 0)
    std::cout << "No existing users";
}

void search_record(std::vector<struct Account> acc_users, int acc_id)
{
  /* std::cout << id.name << std::endl; */
  bool user_found = false;
  for (int i=0; i<acc_users.size(); ++i) {
    auto existing_user = acc_users[i].account_id == acc_id;
    if (existing_user) {
      user_found = true;
      std::cout << "Name: " << acc_users[i].name << std::endl;
      std::cout << "User ID: " << acc_users[i].account_id << std::endl;
      std::cout << "Chequings: " << '$' << acc_users[i].chequings_account << std::endl;
      std::cout << "Savings: " << '$' << acc_users[i].savings_account << std::endl;
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
      double savings = 0;;

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
      struct Account new_acc = {name, account_id, chequings, savings};
      std::cout << "\nAccount created successfully " << std::endl;

      // Store account
      vect.push_back(new_acc);

      search_record(vect, new_acc.account_id);

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

void edit_record()
{

}

void delete_record()
{

}
