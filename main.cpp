#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <regex>
#include <cstdlib>
#include <random>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <time.h>

using namespace std;

//Array in case I need it
double ListOfAccounts[100][5];

//The main class
class Account
{
private:

    //Unique number for each account
    int account_number;
    //Name for the account
    string account_name;
    //Personal Identification Number for the account
    int pin;
    //Email for the main account
    string email;
    //Opening date which is used to calculate interest in savings accounts
    string opening_date;

    //Date in which the interest was last calculated
    string updated_date;

    public:

        //Holder of the account
        string holder_first_name;
        string holder_second_name;
        //Savings or Current account type
        int type;
        //How much the account has
        double balance;
        //Whether the account is open or suspended
        bool status;
        //Original Date
        //Date last updated

    //Generation of the new account number and pin
    void account_number_and_pin_generation()
  {
      /* initialize random seed: */
      srand (time(NULL));

      //Random pin generator
      pin = rand() % 9999;

      cout << "Generated PIN is: " << pin << "." << endl ;

      //Users are allowed to overwrite the randomly generated pin
      printf("Would you like to set a new PIN?\n");
      printf("1. Yes\n");
      printf("2. No\n");
      int selection = 0;
      scanf("%i", &selection);

      //Loop that prevents invalid numbers from being put in
      while ((selection > 2) || (selection < 1)) {
            printf("\nInvalid input. Please try again.\n");
            printf("Would you like to set a new PIN?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%i", &selection);
      }

      //Overwrites generated pin
      if (selection == 1){
      printf("Enter PIN: ");
      cin >> pin;
      }

      //Feature that we might add.... eventually
      /*  printf("Renter PIN: ");
    string re;
    cin >> re; */

      //Randomly generated account_number
      account_number = rand() % 99999999;
      printf("\nAccount number is: %i", account_number);

      //Allows user to input an account name
      printf("\nPlease give this account a name (using underscores instead of spaces): ");
      cin >> account_name;
  }

    //Code to print a txt file with all the necessary details
    void account_print(){
        //Insert code
    }

  /*  Account( string, int, float, bool ) ;
    ~Account() ;  */

    //Method to select an account. Being used in the beginning atm.
    void account_selection(){
        printf("\nPlease type in account number: ");
        int selected_account_number;
        cin >> selected_account_number;

        const int max_length = 100;
        string tab[max_length];
        int j;

        ifstream reader("Accounts.txt");
        for (int i=0; !reader.eof(); i++)
        {
            getline(reader, tab[i]);
            if ((stoi(tab[i])) == selected_account_number){
                printf("\nAccount selected");
                j = i + 1;
                account_number = selected_account_number;
                break;
            }
        }

        printf("\nPlease type in PIN: ");
        int PIN;
        cin >> PIN;
        getline(reader, tab[j]);
        if ((stoi(tab[j])) == PIN){
            printf("\nPIN Correct");
            pin = PIN;
        }

        reader.close();

    string file_path = to_string(account_number) + ".txt";
    ifstream scanner(file_path);
        for (int i=0; !scanner.eof(); i++)
        {
            getline(scanner, tab[i]);
            account_name = tab[i];

            getline(scanner, tab[i]);
            holder_first_name = tab[i];

            getline(scanner, tab[i]);
            holder_second_name = tab[i];

            getline(scanner, tab[i]);
            if (stoi(tab[i]) == 1){
            status = true;
            } else {
            status = false;
            printf("Sorry, this account has been terminated.\nHave a nice day!");
            abort();
            }

            getline(scanner, tab[i]);
            type = stoi(tab[i]);

            getline(scanner, tab[i]);
            balance = stod(tab[i]);

            getline(scanner, tab[i]);
            opening_date = tab[i];

            getline(scanner, tab[i]);
            updated_date = tab[i];

            cout << account_number;

            break;

        }
    reader.close();
}

    void deposit(int statement){
        printf("\nDEPOSIT SELECTED.\n");

        printf("\nHow much do you want to deposit?\n");
        double deposit;
        cin >> deposit;

        balance = balance + deposit;

        cout << "\nNew balance is: " << balance << "\n" << endl;
        cout << account_number;
    }

    void withdrawal(int statement){
        printf("\nWITHDRAWAL SELECTED.\n");
        printf("\nHow much do you want to withdraw\n");
        double money;
        cin >> money;
        balance = balance - money;
        cout << "New balance is: " << balance << endl;
    }

    void TerminationOfAccount(int statement){
        printf("\nTERMINATION OF ACCOUNT SELECTED.\n");
        status = 0;
        printf("\nAccount terminated.");

        // TODO: replace pin with termination sentence

        printf("\nHave a nice day.");


    }

    void CheckBalance(){
        cout << "\nYour current balance is: " << balance;
        cout << account_number;
    }

    void creation_of_account(){
    printf("\nCREATION OF ACCOUNT SELECTED.\n");

    printf("What is your first name?\n");;
    cin >> holder_first_name;

    printf("What is your second name?\n");
    cin >> holder_second_name;


    printf("\nWhich type of account do you want?");
    printf("\n1. Savings");
    printf("\n2. Current\n");

    int selection = 0;
    scanf("%i", &selection);

    while ((selection > 2) || (selection < 1)) {
            printf("Invalid input. Please try again.\n");
            printf("\nWhich type of account do you want?");
            printf("\n1. Savings");
            printf("\n2. Current\n");
            scanf("%i", &selection);
        }
    type = selection;
    balance = 0.00;
    status = true;

    // date = current date



    printf("ACCOUNT CREATED.\n");

    return;
    }

    void update(){

        cout << account_number;

        string file_path = to_string(account_number) + ".txt";
        const int max_length = 100;
        string tab[max_length];

        ofstream writer(file_path,  ios::ate);
        writer << account_name;
        writer << holder_first_name;
        writer << holder_second_name;

        string text_status;
        if (status = true){
            string text_status = "1";
        } else {
            string text_status = "0";
        }

        writer << text_status;

        string text_type = to_string(type);
        writer << texttype;

        string text_balance = to_string(balance);
        writer << text_balance;


        writer.close();
    }



};

class Savings: public Account
{
    public:
        Savings(string first_name, string second_name, int type, double balance, bool status) // Constructor.
    {
      holder_first_name = first_name;
      holder_second_name = second_name;
      type = type;
      balance = balance;
      status = status;
    }

    ~Savings() ; // Destructor.

    float rate_of_interest = 0.02;

    void interest_calculation(){
        //INSERT CALCULATION HERE
    }

};

class Current : public Account
{
    public:
        Current(string first_name, string second_name, int type, double balance, bool status) // Constructor.
    {
      holder_first_name = first_name;
      holder_second_name = second_name;
      type = type;
      balance = balance;
      status = status;
    }

    ~Current() ; // Destructor.

};

/* Account::Account( string name, int type, float balance, bool status )
{
  this -> holder_name = name;
  this -> type = type;
  this -> balance = balance;
  this -> status = status;
} */

Account main_menu(Account SelectedAccount, int statement){


    printf("\nWhat could we do for you today?\n\n");
    printf("1. Deposit\n");
    printf("2. Withdrawal\n");
    printf("3. Terminating of Account.\n");
    printf("4. Check Balance.\n");

    int selection = 0;
    scanf("%i", &selection);

    while ((selection > 4) || (selection < 1)) {
            printf("Invalid input. Please try again.\n");
            printf("What could we do for you today?\n\n");
            printf("1. Deposit\n");
            printf("2. Withdrawal\n");
            printf("3. Terminating of Account.\n");
            printf("4. Check Balance.\n");
            scanf("%i", &selection);
        }

    if (selection == 1){
        SelectedAccount.deposit(statement);
    } else if (selection == 2){
        SelectedAccount.withdrawal(statement);
    } else if (selection == 3){
        SelectedAccount.TerminationOfAccount(statement);
    } else if (selection == 4){
        SelectedAccount.CheckBalance();
    }

    return SelectedAccount;
}

Account loop(Account SelectedAccount, int statement){

    printf("\nIs that all the services you would be requiring?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int loop = 0;
    scanf("%i", &loop);

    int selection;

    while ((loop > 2) || (loop < 1)) {
        printf("Invalid input. Please try again.\n");
        printf("Is that all the services you would be requiring?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%i", &loop);
    }

    while (loop == 2){
        printf("What could we do for you today?\n\n");
        printf("1. Deposit\n");
        printf("2. Withdrawal\n");
        printf("3. Terminating of Account.\n");
        printf("4. Check Balance.\n");
        selection = 0;
        scanf("%i", &selection);

       while ((selection > 4) || (selection < 1)) {
            printf("Invalid input. Please try again.\n");
            printf("What could we do for you today?\n\n");
            printf("1. Deposit\n");
            printf("2. Withdrawal\n");
            printf("3. Terminating of Account.\n");
            printf("4. Check Balance.\n");
            scanf("%i", &selection);
        }

        if (selection == 1){
        SelectedAccount.deposit(statement);
        } else if (selection == 2){
        SelectedAccount.withdrawal(statement);
        } else if (selection == 3){
        SelectedAccount.TerminationOfAccount(statement);
        } else if (selection == 4){
        SelectedAccount.CheckBalance();
        }

        printf("Is that all the services you would be requiring?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        loop = 0;
        scanf("%i", &loop);
    }

    SelectedAccount.update();

    return SelectedAccount;
}

Account start(Account SelectedAccount){
    printf("Welcome to RailBank!\n");
    printf("We'll make sure your finances are staying on track!\n");

    printf("Please select an option.\n");
    printf("1. Login\n");
    printf("2. Create a new account\n");
    int selection;
    cin >> selection;

    while ((selection > 2) || (selection < 1)) {
        printf("Invalid input. Please try again.\n");
        printf("Please select an option.\n");
        printf("1. Login\n");
        printf("2. Create a new account\n");
        scanf("%i", &selection);
    }

    if (selection == 1){
        // Login();
        SelectedAccount.account_selection();
    } else if (selection == 2){
        SelectedAccount.creation_of_account();
        SelectedAccount.account_number_and_pin_generation();
    }

    return SelectedAccount;

}

int main()
{
    //cout << "Hello world!" << endl;

//    In txt: '<xbcbancikanc>'
 //   User input: 'password123' -> hash -> '<xbcbancikanc>'

    Account SelectedAccount;

    SelectedAccount = start(SelectedAccount);

    printf("\nWould you like a printed statement at the end of the session?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int statement = 0;
    scanf("%i", &statement);

    while ((statement > 2) || (statement < 1)) {
        printf("Invalid input. Please try again.\n");
        printf("\nWould you like a printed statement at the end of the session?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%i", &statement);
    }

    main_menu(SelectedAccount, statement);

    loop(SelectedAccount, statement);

    return 0;
}
