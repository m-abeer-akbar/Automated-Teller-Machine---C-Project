#include <iostream>
#include <fstream>
using namespace std;

class Bank //Creating a class Bank
{
private: //Access specified as Private
	string Name;
	int AccountNumber = 0;
	string AccountType [2] = {"Current", "Savings" }; // Creating an array AccountType with size of two elements
  string inputType;
	int Cash = 0;
	int Total = 0;
  
public: //Access specified as Public
	void UserLogin(){
{
    string Name;
    int Pin;
    int Attempts = 0;

    while (Attempts < 3) //Creating a loop for user login until true
      
    {
        cout << "Please enter your user name: ";
        cin >> Name;
        cout << "Please enter your PIN: ";
        cin >> Pin;

        if (Name == "Akbar" && Pin == 1234)
        {
            cout << "Welcome Akbar!" <<endl;
            break;
        }
        else if (Name == "Kelly" && Pin == 4321)
        {
            cout << "Welcome Kelly!" <<endl;
            break;
        }
          else if (Name == "Muhammad" && Pin == 2002)
        {
            cout << "Welcome Muhammad!" <<endl;
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again" 
        <<endl; 
            Attempts++;
        }
    }
    if (Attempts == 3)
    {
            cout << "Your account has been blocked. Please contact the bank to follow the unlock procedure" <<endl;
            
    }
  else {
 cout << "Logged In"<<endl;
} 
 }
    }
  void UserData() //Creating a function for user to input their information
	{
		cout << "Enter Account Holder's Name: " << endl;
		cin.ignore();
		getline(cin , Name);

		cout << "Enter account number:" << endl;
		cin >> AccountNumber;
		cout << "Enter Account type (Current/Savings): " << endl;
		
    cin >> inputType;
    
    for( int i = 0; i < 2; ++i )  //Printing elements in array
	{
		if( inputType == AccountType [ i ] ) 
			cout << " Thank you! " << endl;
		else
			cout << " Invalid Option! " <<endl;
  	}
 
    cout << "Enter opening balance: " << endl;
	  cout << "£ "; cin >> Total;
    
	}


	void PrintInfo() //Function to show account details to the user
	{
		cout << " Name: " << Name << endl;
		cout << " Account Number: " << AccountNumber << endl;
		cout << " Account type: " << AccountType << endl;
	}
	void DepositCash() //Function to input amount user would like to deposit
	{
    int Balance, Amount;
		cout << "   Enter amount to be deposited: £ ";
		cin >> Cash;
	}
	void CheckBalance() //Function for the user to check account balance
	{
		Total = Total + Cash;
		cout << " Balance: £ " << Total << endl;
	}
	void WithdrawCash() //Function for the user to withdraw cash from their account
	{
			int Amount, Balance;
		cout << "  Please enter the withdrawal amount: £";
		cin >> Amount;

		Balance = Total - Amount;
		cout << "  Updated Balance: £ " << Balance << endl;
    }
  
void PrintData() //Creating a file 
	{
		  fstream f; //Stream class created that can read and write from or to the file
    
		f.open("AccountInfo.txt", ios::out | ios::app); // Opening a text file
	  f << "Username: ";
    f<< Name << endl;
    f << "Account Number: ";
		f << AccountNumber << endl;
    f << "Account Type (Current/Savings): ";
		f << AccountType << endl;
    f <<"Total Balance: ";
		f << Total << endl;
		f.close(); //Closing the file
    cout << "Information Saved Successfully!" << endl;
	}

};


int main()
{
	Bank ATM; //Creating an object ATM
	int options;

	while (true)
    // Using loop here so that it keeps displaying the menu till user choice entered.
    {
		cout << "  | ======================== WELCOME! ========================  |" << endl;
		cout <<"  | Please choose from the options below                        |" << endl;;
    cout << "  | 1. User Login                                               |" << endl;
		cout << "  | 2. Enter your Name, Account Number, Account Type            |" << endl;
		cout << "  | 3. Account Info                                             |" << endl;
		cout << "  | 4. Deposit Cash                                             |" << endl;
		cout << "  | 5. Cash Withdrawal                                          |" << endl;
		cout << "  | 6. Balance Enquiry                                          |" << endl;
    cout << "  | 7. Generate Statement                                       |" << endl;
		cout << "  | 8. Exit                                                     |" << endl;
        cout << "  | =========================================================== |" << endl;

		cin >> options;

		// Using switch here to select from the given options.
		switch (options) {
    case 1:
    cout<<"="<<endl;  ATM.UserLogin();
      break;
    case 2:
		cout<<"="<<endl;	ATM.UserData();
			break;
		case 3:
		cout<<"="<<endl;	ATM.PrintInfo();
			break;
		case 4:
		cout<<"="<<endl;	ATM.DepositCash();
			break;
		case 5:
		cout<<"="<<endl;	ATM.WithdrawCash();
			break;
		case 6:
		cout<<"="<<endl;	ATM.CheckBalance();
			break;
	  case 7:
    cout<<"="<<endl;  ATM.PrintData();
      break;
    case 8:
		cout<<"="<<endl;	exit(true);
			break;
		default:
			cout << endl << "  Invalid Choice  " << endl;
		}
	 }
  }
