#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <regex>
#include <cstdlib>
#include <random>
#include <fstream>

using namespace std;

double ListOfAccounts[100][5];

class Account
{
private:

    int account_number;
    string account_name;
    int pin;
    string email;
    string opening_date;

    public:

        string holder_name;
        int type;
        double balance;
        bool status;

    void account_number_and_pin_generation()
  {
      /* initialize random seed: */
      srand (time(NULL));

      pin = rand() % 9999;

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

      if (selection == 1){
      printf("Enter pin: ");
      cin >> pin;
      }

      /*  printf("Renter pin: ");
    string re;
    cin >> re; */

      account_number = rand() % 99999999;
      printf("\nAccount number is: %i", account_number);

      printf("\nPlease give this account a name (using underscores instead of spaces): ");
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

void creation_of_account(){
    printf("\nCREATION OF ACCOUNT SELECTED.\n");

    printf("What is your name (using underscores instead of spaces)?\n");
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

    printf("ACCOUNT CREATED.\n");

    return;


}

void deposit(){
    printf("\nDEPOSIT SELECTED.\n");

    printf("Insert account number: ");
    float input;
    scanf("%f", &input);

    while(input < 0){
        printf("\nInvalid input. Please try again.\n");
        printf("Insert account number: ");
        scanf("%f", &input);
    }

    //Insert account selection


}

void withdrawal(){
    printf("\WITHDRAWAL SELECTED.\n");
}

void TerminationOfAccount(){
    printf("\nTERMINATION OF ACCOUNT SELECTED.\n");
}

void CheckBalance(){

}

void PrintStatement(){

}

void Login(){
    string email;
    string password;

    const int max_length = 100;
    string tab[max_length];
   // int j;
    int attempts;

    printf("\nEnter email (no spaces): ");
    cin >> email;

    ifstream reader("EP.txt");
    for (int i=0; !reader.eof(); i++)
    {
        getline(reader, tab[i], '\n');
        if (tab[i] == email){
            printf("\nEmail Successful!");
           // j = i + 1;
            attempts = 1;
        }
    }

//  printf("Test");

    // Open document, scan email, if not there, bring up error. If there, pre-load holder password.
    printf("\nEnter password (no spaces): ");
    cin >> password;

    for (int i=0; !reader.eof(); i++)
    {
        getline(reader, tab[i], '\n');
        if (tab[i] == password){
            printf("\nPassword Successful!");
        }
    }
    reader.close();
}


void SelectAccount(){
    printf("\nInsert account number: ");
    int input;
    scanf("%i", input);

    //open ("Accounts.txt", ios::ate);
}


void MainMenu(){

    printf("\nWhat could we do for you today?\n\n");
    printf("1. Creation of account\n");
    printf("2. Deposit\n");
    printf("3. Withdrawal\n");
    printf("4. Terminating of Account.\n");
    printf("5. Check Balance.\n");
    printf("6. Print Statement.\n");

    int selection = 0;
    scanf("%i", &selection);

    while ((selection > 6) || (selection < 1)) {
            printf("Invalid input. Please try again.\n");
            printf("What could we do for you today?\n\n");
            printf("1. Creation of account\n");
            printf("2. Deposit\n");
            printf("3. Withdrawal\n");
            printf("4. Terminating of Account.\n");
            printf("5. Check Balance.\n");
            printf("6. Print Statement.\n");
            scanf("%i", &selection);
        }

    if (selection != 1){
        SelectAccount();
    }

    if (selection == 1){
        creation_of_account();
    } else if (selection == 2){
        deposit();
    } else if (selection == 3){
        withdrawal();
    } else if (selection == 4){
        TerminationOfAccount();
    } else if (selection == 5){
        CheckBalance();
    } else if (selection == 6){
        PrintStatement();
    }

    return;
}

void loop(){
    printf("Is that all the services you would be requiring?\n");
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

    while (loop == 1){
        printf("What could we do for you today?\n\n");
        printf("1. Creation of account\n");
        printf("2. Deposit\n");
        printf("3. Withdrawal\n");
        printf("4. Terminating of Account.\n");
        printf("5. Viewing of Balance.\n");
        printf("6. Print Statement.\n");
        selection = 0;
        scanf("%i", &selection);

        while ((selection > 6) || (selection < 1)) {
            printf("Invalid input. Please try again.\n");
            printf("What could we do for you today?\n\n");
            printf("1. Creation of account\n");
            printf("2. Deposit\n");
            printf("3. Withdrawal\n");
            printf("4. Terminating of Account.\n");
            scanf("%i", &selection);
        }

        if (selection == 1){
            creation_of_account();
        } else if (selection == 2){
            deposit();
        } else if (selection == 3){
            withdrawal();
        } else if (selection == 4){
            TerminationOfAccount();
        } else if (selection == 5){
            CheckBalance();
        } else if (selection == 6){
            PrintStatement();
        }

        printf("Is that all the services you would be requiring?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        loop = 0;
        scanf("%i", &loop);
    }

    return;
}

int main()
{
    //cout << "Hello world!" << endl;

//    In txt: '<xbcbancikanc>'
 //   User input: 'password123' -> hash -> '<xbcbancikanc>'

    printf("Welcome to RailBank!\n");
    printf("We'll make sure your finances are staying on track!\n");

    printf("Please select an option.\n");
    printf("1. Login");
    printf("2. Create a new account");

    Login();

    MainMenu();

    loop();

    return 0;
}
