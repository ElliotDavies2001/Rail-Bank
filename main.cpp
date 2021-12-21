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

        string holder_first_name;
        string holder_second_name;
        int type;
        double balance;
        bool status;
        //Original Date
        //Date last updated

    void account_number_and_pin_generation()
  {
      /* initialize random seed: */
      srand (time(NULL));

      pin = rand() % 9999;

      cout << "Generated PIN is: " << pin << "." << endl ;

      printf("Would you like to set a new PIN?\n");
      printf("1. Yes\n");
      printf("2. No\n");
      int selection = 0;
      scanf("%i", &selection);

      while ((selection > 2) || (selection < 1)) {
            printf("\nInvalid input. Please try again.\n");
            printf("Would you like to set a new PIN?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%i", &selection);
      }

      if (selection == 1){
      printf("Enter PIN: ");
      cin >> pin;
      }

      /*  printf("Renter PIN: ");
    string re;
    cin >> re; */

      account_number = rand() % 99999999;
      printf("\nAccount number is: %i", account_number);

      printf("\nPlease give this account a name (using underscores instead of spaces): ");
      cin >> account_name;
  }

    void account_confirmation(){
        //Insert code
    }

  /*  Account( string, int, float, bool ) ;
    ~Account() ;  */

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
                break;
            }
        }

        printf("\nPlease type in PIN: ");
        int PIN;
        cin >> PIN;
        getline(reader, tab[j]);
        if ((stoi(tab[j])) == PIN){
            printf("\nPIN Correct");
        }

        j++;
        getline(reader, tab[j]);
        string selected_first_name = (tab[j]);

        j++;
        getline(reader, tab[j]);
        string selected_second_name = (tab[j]);

        j++;
        getline(reader, tab[j]);
        if (stoi(tab[j]) == 1){
            bool selected_status = true;
        } else {
            bool selected_status = false;
        }

        j++;
        getline(reader, tab[j]);
        int selected_status = stoi(tab[j]);

        j++;
        getline(reader, tab[j]);
        double account_balance = stoi((tab[j]));

    /*
        j++;
        getline(reader,tab[j]);
        string selected_first_name = (tab[j]);

        j++;
        getline(reader,tab[j]);
        string selected_first_name = (tab[j]);

        We'll sort out dates afterwards. It is too complex to sort out rn.*/



        reader.close();
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

};

class Savings : public Account
{
    public:
        Savings( string first_name, string second_name, int type, double balance, bool status ) // Constructor.
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
        Current( string first_name, string second_name, int type, double balance, bool status ) // Constructor.
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

void PrintStatement(){

    }

void creation_of_account(){
    printf("\nCREATION OF ACCOUNT SELECTED.\n");

    printf("What is your first name?\n");
    string first_name;
    //scanf("%s", &name);
    cin >> first_name;

    printf("What is your second name?\n");
    string second_name;
    cin >> second_name;


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
        Account* NewAccount = new Savings(first_name, second_name, 1, 0.00, true);
        NewAccount -> account_number_and_pin_generation();
    } else if (selection == 2){
        Account* NewAccount = new Current(first_name, second_name, 2, 0.00, true);
        NewAccount -> account_number_and_pin_generation();
    }

    printf("ACCOUNT CREATED.\n");

    return;
}

void Login(){
    string email;
    string password;

    const int max_length = 100;
    string tab[max_length];
    int j;
    int attempts;

    printf("\nEnter email (no spaces): ");
    cin >> email;

    ifstream reader("EP.txt");
    for (int i=0; !reader.eof(); i++)
    {
        getline(reader, tab[i], '\n');
        if (tab[i] == email){
            printf("\nEmail Successful!");
            j = i + 1;
            attempts = 1;
            break;
        }
    }

//  printf("Test");

    // Open document, scan email, if not there, bring up error. If there, pre-load holder password.
    printf("\nEnter password (no spaces): ");
    cin >> password;

        getline(reader, tab[j], '\n');
        if (tab[j] == password){
            printf("\nPassword Successful!");
        }
    reader.close();
}

    void creation_of_EP(){
    //lol
}

void MainMenu(){

    Account SelectedAccount;

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

    if ((selection != 1) && (selection != 6)){
        SelectedAccount.account_selection();
    }

    if (selection == 1){
        creation_of_account();
    } else if (selection == 2){
        SelectedAccount.deposit();
    } else if (selection == 3){
        SelectedAccount.withdrawal();
    } else if (selection == 4){
        SelectedAccount.TerminationOfAccount();
    } else if (selection == 5){
        SelectedAccount.CheckBalance();
    } else if (selection == 6){
        PrintStatement();
    }

    return;
}

void loop(){

    Account SelectedAccount;

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
            SelectedAccount.deposit();
        } else if (selection == 3){
            SelectedAccount.withdrawal();
        } else if (selection == 4){
            SelectedAccount.TerminationOfAccount();
        } else if (selection == 5){
            SelectedAccount.CheckBalance();
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

void start(){
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
            Login();
    } else if (selection == 2){
            creation_of_EP();
    }

}

int main()
{
    //cout << "Hello world!" << endl;

//    In txt: '<xbcbancikanc>'
 //   User input: 'password123' -> hash -> '<xbcbancikanc>'

    start();

    MainMenu();

    loop();

    return 0;
}
