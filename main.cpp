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
    string holder_name;
    int type;
    string password;
    string opening_date;
    double balance;
    bool status;

    void account_number_and_password_generation()
  {
      /* initialize random seed: */
      srand (time(NULL));

      password = rand();

      cout << "Generated password is: " << password << "." << endl ;

      account_number = 0;
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
        NewSavings -> account_number_and_password_generation();
    } else if (selection == 2){
        Account* NewCurrent = new Current(name, 2, 0.00, true);
        NewCurrent -> account_number_and_password_generation();
    }

    printf("Would you like to set a new password?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%i", &selection);

    printf("Enter Password: ");
    string password;
    cin >> password;
  /*  printf("Renter Password: ");
    string re;
    cin >> re; */



    //Insert accessor


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

int main()
{
    //cout << "Hello world!" << endl;


    printf("Welcome to RailBank!\n");
    printf("We'll make sure your finances are staying on track!\n\n");
    printf("What could we do for you today?\n\n");
    printf("1. Creation of account\n");
    printf("2. Deposit\n");
    printf("3. Withdrawal\n");
    printf("4. Terminating of Account.\n");

    int selection;
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


    return 0;
}
