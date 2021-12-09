#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <regex>

using namespace std;

class Account
{
public:

    double account_number;
    string account_name;
    string holder_name;
    int type;
    float pin;
    string email;
    string opening_date;
    double balance;
    bool status;

    void account_number_and_pin_generation()
  {
      /* initialize random seed: */
      srand (time(NULL));

      pin = rand() % 8;

      cout << "Generated pin is: " << pin << "." << endl ;

      printf("Would you like to set a new pin?\n");
      printf("1. Yes\n");
      printf("2. No\n");
      int selection = 0;
      scanf("%i", &selection);

      while ((selection > 2) || (selection < 1)) {
            printf("\nInvalid input. Please try again.\n");
            printf("Would you like to set a new pin?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%i", &selection);
        }

      printf("Enter pin: ");
      cin >> pin;

      /*  printf("Renter pin: ");
    string re;
    cin >> re; */

      account_number = 0;
      printf("\nAccount number is: %f", account_number);

      printf("Please give this account a name: ");
      cin >> account_name;
  }

  /*  Account( string, int, float, bool ) ;
    ~Account() ;  */


};

class Savings : public Account
{
    public:
        Savings( string name, int type, double balance, bool status ) // Constructor.
    {
      holder_name = name;
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
        Current( string name, int type, double balance, bool status ) // Constructor.
    {
      holder_name = name;
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

void CreationOfAccount(){
    printf("\nCREATION OF ACCOUNT SELECTED.\n");

    printf("What is your name?\n");
    string name;
    //scanf("%s", &name);
    cin >> name;

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

    if (selection == 1){
        Account* NewSavings = new Savings(name, 1, 0.00, true);
        NewSavings -> account_number_and_pin_generation();
    } else if (selection == 2){
        Account* NewCurrent = new Current(name, 2, 0.00, true);
        NewCurrent -> account_number_and_pin_generation();
    }

    printf("ACCOUNT CREATED.");


}

void Deposit(){
    printf("\nDEPOSIT SELECTED.\n");
}

void Withdrawal(){
    printf("\WITHDRAWAL SELECTED.\n");
}

void TerminationOfAccount(){
    printf("\nTERMINATION OF ACCOUNT SELECTED.\n");
}

void Login(){
    string email;
    string password;

    printf("Welcome to RailBank!\n");
    printf("We'll make sure your finances are staying on track!\n\n");

    printf("Enter email: ");
    cin >> email;

    //Open document, scan email, if not there, bring up error. If there, pre-load holder password.
    printf("Enter password: ");
    cin >> password;

    //Scan with pre-loaded password, if correct let through, if not correct show error.

    //If correct, add use special number in the login document to load up correct account document

}

int main()
{
    //cout << "Hello world!" << endl;

    // login();

    printf("What could we do for you today?\n\n");
    printf("1. Creation of account\n");
    printf("2. Deposit\n");
    printf("3. Withdrawal\n");
    printf("4. Terminating of Account.\n");

    int selection = 0;
    scanf("%i", &selection);

    while ((selection > 4) || (selection < 1)) {
            printf("Invalid input. Please try again.\n");
            printf("What could we do for you today?\n\n");
            printf("1. Creation of account\n");
            printf("2. Deposit\n");
            printf("3. Withdrawal\n");
            printf("4. Terminating of Account.\n");
            scanf("%i", &selection);
        }

    if (selection == 1){
        CreationOfAccount();
    } else if (selection == 2){
        Deposit();
    } else if (selection == 3){
        Withdrawal();
    } else if (selection == 4){
        TerminationOfAccount();
    }

    printf("Is that all the services you would be requiring?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int loop = 0;
    scanf("%i", &loop);

    while ((selection > 2) || (selection < 1)) {
        printf("Invalid input. Please try again.\n")
        printf("Is that all the services you would be requiring?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%i", &loop);
    }

    while (loop == 1){
        printf("What could we do for you today?\n\n");
        printf("1. Creation of account\n");
        printf("2. Deposit\n");
        printf("3. Withdrawal\n");
        printf("4. Terminating of Account.\n");
        selection = 0;
        scanf("%i", &selection);

        while ((selection > 4) || (selection < 1)) {
            printf("Invalid input. Please try again.\n");
            printf("What could we do for you today?\n\n");
            printf("1. Creation of account\n");
            printf("2. Deposit\n");
            printf("3. Withdrawal\n");
            printf("4. Terminating of Account.\n");
            scanf("%i", &selection);
        }

        if (selection == 1){
        CreationOfAccount();
        } else if (selection == 2){
        Deposit();
        } else if (selection == 3){
        Withdrawal();
        } else if (selection == 4){
        TerminationOfAccount();
        }

        printf("Is that all the services you would be requiring?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        loop = 0;
        scanf("%i", &loop);
    }

    return 0;
}
