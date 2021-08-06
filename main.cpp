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
void create_account(std::vector<struct Account>);
void display_data(struct Account);
void search_record(int);
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
        /* display_data(); */
        continue;
      case 2:
        std::cout << "Enter user account number: ";
        int acc_id;
        std::cin >> acc_id;
        search_record(acc_id);
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

void display_data(struct Account acc)
{

}

void search_record(int id)
{
  /* std::cout << id.name << std::endl; */
}

void create_account(std::vector<struct Account> vect)
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
      struct Account acc = {name, account_id, chequings, savings};
      std::cout << "User id: " << acc.account_id<< std::endl;

      // Store account
      vect.push_back(acc);

      // Ask if user wants to create another account
      std::cout << "Add another account? (y/n): ";
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
