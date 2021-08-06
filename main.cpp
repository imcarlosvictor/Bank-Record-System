#include <iostream>

struct Account
{
  std::string name;
  int account_id;
  double chequings_account;
  double savings_account;
};

struct Account add_record(std::string,  double, double);
void create_account();
void display_data(struct Account);
void search_record(int);
void edit_record();
void delete_record();

int main()
{
  bool program = true;
  do {
    std::cout << "########################################################\n";
    std::cout << "\t\tACCOUNT INFORMATION SYSTEM \n";
    std::cout << "Select an option below:" << std::endl;
    std::cout << "\t -> 1. Show all records\n";
    std::cout << "\t -> 2. Search record from file\n";
    std::cout << "\t -> 3. Add record to a file\n";
    std::cout << "\t -> 4. Update record\n";
    std::cout << "\t -> 5. Delete record\n";
    std::cout << "\t -> 6. Quit\n";
    std::cout << "########################################################\n\n";
    
    int choice;
    std::cout << "Your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        /* display_data(); */
      case 2:
        /* search_record(); */
      case 3:
        create_account();
      case 4:
        edit_record();
      case 5:
        delete_record();
      case 6:
        program = false;
    }
  } while (program);

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

void create_account()
{
  bool add_account = true;
  do {
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

      // Create and return account
      struct Account acc = add_record(name, chequings, savings);
      std::cout << "User id: " << acc.account_id<< std::endl;
      // Reference to id
      int &user_id = acc.account_id;
      // Create pointer for access
      struct Account *id_ptr= &user_id;

      std::cout << "Add another account? (y/n): ";
      std::cin >> new_account;

      // Check if user wants to add another account
      switch (new_account) {
        case 'y':
          continue;
        case 'n':
          add_account = false;
        default:
          std::cout << "Enter either y or n." << std::endl;
      }
  } while (add_account);
}

struct Account add_record(std::string name, double cheque_balance, double savings_balance)
{
  // Generate a random account number
  srand(time(NULL));
  int account_id =  rand() % ((199999 - 100000) + 1) + 100000;

  // Check if account number already exists

  // Create account
  Account acc= {name, account_id, cheque_balance, savings_balance};

  // Return  account id
  return acc;
}

void edit_record()
{

}

void delete_record()
{

}
