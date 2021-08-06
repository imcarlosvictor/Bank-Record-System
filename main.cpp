#include <iostream>

struct Account
{
  std::string name;
  int account_id;
  double chequings_account;
  double savings_account;
};

struct Account add_record(std::string,  double, double);
void display_data();
void search_record();
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
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        program = false;
    }
  } while (program);


  return 0;
}

void create_account()
{
  bool add_account = true;
  do {
      char add_account;
      std::string name;
      double chequings = 0;
      double savings = 0;;

      std::cout << "Hello, please enter your name: ";
      std::cin >> name;

      std::cout << "Enter chequing balance: ";
      std::cin >> chequings;

      std::cout << "Enter savings balance: ";
      std::cin >> savings;

      // Create account
      add_record(name, chequings, savings);

      std::cout << "Add another account? (y/n): ";
      std::cin >> add_account;

      // Check if user wants to add another account
      switch (add_account) {
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
 int account_number =  rand() % ((199999 - 100000) + 1) + 100000;

 // Check if account number already exists

 // Create account
 struct Account acc = {name, account_number, cheque_balance, savings_balance};

 return acc;
}

void display_data(struct Account p)
{

}

void search_record()
{

}

void edit_record()
{

}

void delete_record()
{

}
