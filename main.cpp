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

    //How much the account has
    double balance;

    public:

    //Holder of the account
    string holder_first_name;
    string holder_second_name;
    //Savings or Current account type
    int type;
    //Whether the account is open or suspended
    int status;
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

      //Randomly generated account_number
      account_number = rand() % 99999999;
      printf("\nAccount number is: %i", account_number);

      //Allows user to input an account name
      printf("\nPlease give this account a name (using underscores instead of spaces): ");
      cin >> account_name;
    }

    //Method to select an account. Being used in the beginning atm.
    void account_selection(){
        printf("\nPlease type in account number: ");
        int selected_account_number;
        cin >> selected_account_number;

        //Set up for the reader function
        const int max_length = 100;
        string tab[max_length];
        int j;

        //Reads accounts to get pin for account
        ifstream reader("Accounts.txt");
        for (int i=0; !reader.eof(); i++)
        {
            getline(reader, tab[i]);
            if ((stoi(tab[i])) == selected_account_number){
                printf("\nAccount selected");
                j = i + 1;
                account_number = selected_account_number;
               // int confirm =
                break;
            }
        }

        //Security feature to ensure that the user's account is safe
        //(by using PIN)
        printf("\nPlease type in PIN: ");
        int PIN;
        cin >> PIN;
        getline(reader, tab[j]);
        if ((stoi(tab[j])) == PIN){
            printf("\nPIN Correct");
            pin = PIN;
        }

        reader.close();

        //With the account number, it reads the file that has that exact number
        //To extract the rest of the account info
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

            //Prevents suspended accounts from being accessed.
            getline(scanner, tab[i]);
            if (stoi(tab[i]) == 0){
            printf("Sorry, this account has been terminated.\nHave a nice day!");
            abort();
            }
            status = stoi(tab[i]);

            getline(scanner, tab[i]);
            type = stoi(tab[i]);

            getline(scanner, tab[i]);
            balance = stod(tab[i]);

            getline(scanner, tab[i]);
            opening_date = tab[i];

            getline(scanner, tab[i]);
            updated_date = tab[i];

            break;
        }
        reader.close();
    }

    void deposit(int statement){
        printf("\nDEPOSIT SELECTED.\n");

        printf("\nHow much do you want to deposit?\n");
        double deposit;
        cin >> deposit;

        balance += deposit;

        cout << "\nNew balance is: " << balance << "\n" << endl;
    }

    void withdrawal(int statement){
        printf("\nWITHDRAWAL SELECTED.\n");
        printf("\nHow much do you want to withdraw\n");
        double money;
        cin >> money;
        balance = balance - money;
        cout << "New balance is: " << balance << endl;
    }

    //Sets the account as terminated so it won't be able to be accessed anymore
    void TerminationOfAccount(int statement){
        printf("\nTERMINATION OF ACCOUNT SELECTED.\n");
        status = 0;
        printf("\nAccount terminated.");


        string file_path = to_string(account_number) + ".txt";
        const int max_length = 100;
        string tab[max_length];

        //Updates the text file to reflect the suspension
        string text_status = to_string(status);
        string text_type = to_string(type);
        string text_balance = to_string(balance);

        ofstream writer(file_path,  ios::ate);
        writer << account_name << "\n";
        writer << holder_first_name << "\n";
        writer << holder_second_name << "\n";
        writer << text_status << "\n";
        writer << text_type << "\n";
        writer << text_balance << "\n";
        writer << opening_date << "\n";

        writer.close();

        printf("\nHave a nice day.");
        abort();
    }

    void CheckBalance(){
        cout << "\nYour current balance is: " << balance;
    }

    //Creates a new account for the user
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

        //Loop to ensure an invalid number can't be inputted
        while ((selection > 2) || (selection < 1)) {
            printf("Invalid input. Please try again.\n");
            printf("\nWhich type of account do you want?");
            printf("\n1. Savings");
            printf("\n2. Current\n");
            scanf("%i", &selection);
        }
        type = selection;
        balance = 0.00;
        status = 1;

     // date = current date

        printf("ACCOUNT CREATED.\n");

        return;
    }

    //Updates the relevant txt to reflect any changes to the balance
    //Or allows new accounts to be added
    void update(){
        string file_path = to_string(account_number) + ".txt";
        const int max_length = 100;
        string tab[max_length];

        //Allows for numbers to be inserted in the text file (as strings)
        string text_status = to_string(status);
        string text_type = to_string(type);
        string text_balance = to_string(balance);

        ofstream writer(file_path,  ios::ate);
        writer << account_name << "\n";
        writer << holder_first_name << "\n";
        writer << holder_second_name << "\n";
        writer << text_status << "\n";
        writer << text_type << "\n";
        writer << text_balance << "\n";
        writer << opening_date << "\n";

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

    //The main difference between the savings and current classes
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

//The initial actions done by the user.
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

    //Executes methods based on user input
    if (selection == 1){
        SelectedAccount.deposit(statement);
    } else if (selection == 2){
        SelectedAccount.withdrawal(statement);
    } else if (selection == 3){
        SelectedAccount.TerminationOfAccount(statement);
    } else if (selection == 4){
        SelectedAccount.CheckBalance();
    }

    //Allows it to be imported into the loop function
    //and into the other methods
    return SelectedAccount;
}

//Loop that ensures users that want to do multiple actions
//can do multiple actions
Account loop(Account SelectedAccount, int statement){

    printf("\nIs that all the services you would be requiring?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int loop = 0;
    scanf("%i", &loop);

    int selection;

    //Loop that ensures invalid numbers are not allowed
    while ((loop > 2) || (loop < 1)) {
        printf("\nInvalid input. Please try again.\n");
        printf("Is that all the services you would be requiring?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%i", &loop);
    }

    //The main loop that allows users to do multiple actions
    while (loop == 2){
        printf("\nWhat could we do for you today?\n\n");
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

        //Executes methods based on user input
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

    //Updates the txt it's all finished
    SelectedAccount.update();

    return SelectedAccount;
}

//Basically the start of the program.
//Which allows for users to login or create a new account
Account start(Account SelectedAccount){
    printf("Welcome to RailBank!\n");
    printf("We'll make sure your finances are staying on track!\n");

    printf("Please select an option.\n");
    printf("1. Login\n");
    printf("2. Create a new account\n");
    int selection;
    cin >> selection;

    //Ensures invalid numbers are not allowed
    while ((selection > 2) || (selection < 1)) {
        printf("Invalid input. Please try again.\n");
        printf("Please select an option.\n");
        printf("1. Login\n");
        printf("2. Create a new account\n");
        scanf("%i", &selection);
    }

    //Ensures the method selected is executed
    if (selection == 1){
        SelectedAccount.account_selection();
    } else if (selection == 2){
        SelectedAccount.creation_of_account();
        SelectedAccount.account_number_and_pin_generation();
    }

    //Returns the selected account ready for the main menu
    return SelectedAccount;
}

int main()
{
    //Account declared
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

    //INSERT INITIAL STATEMENT CODE HERE

    SelectedAccount = main_menu(SelectedAccount, statement);

    SelectedAccount = loop(SelectedAccount, statement);

    //Goodbye message
    printf("\nThank you for using RailBank.\n");
    printf("Have a great rest of the day from all of us here at RailBank!");

    return 0;
}
