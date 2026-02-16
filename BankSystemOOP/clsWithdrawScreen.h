#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsWithdrawScreen : clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        cout << "\n" << clsLang::ToLang("ClientCard", LangChosen) << " :";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("ClientName", LangChosen) << " : " << Client.FirstName;
        cout << "\n" << clsLang::ToLang("LastName", LangChosen) << " : " << Client.LastName;
        cout << "\n" << clsLang::ToLang("Email", LangChosen) << " : " << Client.Email;
        cout << "\n" << clsLang::ToLang("Phone", LangChosen) << " : " << Client.Phone;
        cout << "\n" << clsLang::ToLang("AccountNumber", LangChosen) << " : " << Client.GetAccountNumber();
        cout << "\n" << clsLang::ToLang("PinCode", LangChosen) << " : " << Client.PinCode;
        cout << "\n" << clsLang::ToLang("Balance", LangChosen) << " : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static string ReadAccountNumber() {
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient", LangChosen) << ": ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public : 
    static void ShowWithdrawScreen() {
        _DrawScreenHeader("\t  Withdraw Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);

        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            if(Client.Withdraw(Amount))
            {
                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance Is: " << Client.AccountBalance;
                cout << "\n\n";
            }
            else {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client.AccountBalance;
                cout << "\n\n";
            }

        }
        else {
            cout << "\nOperation was cancelled.\n";
        }




    }
};

