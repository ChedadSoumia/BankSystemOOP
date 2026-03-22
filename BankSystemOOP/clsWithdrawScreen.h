#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsWithdrawScreen : clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        SetColor(13);
        cout << "\n" << clsLang::ToLang("ClientCard") << " :";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("FirstName") << " : " << Client.FirstName;
        cout << "\n" << clsLang::ToLang("LastName") << " : " << Client.LastName;
        cout << "\n" << clsLang::ToLang("Email") << " : " << Client.Email;
        cout << "\n" << clsLang::ToLang("Phone") << " : " << Client.Phone;
        cout << "\n" << clsLang::ToLang("AccountNumber") << " : " << Client.GetAccountNumber();
        cout << "\n" << clsLang::ToLang("PinCode") << " : " << Client.PinCode;
        cout << "\n" << clsLang::ToLang("Balance") << " : " << Client.AccountBalance;
        cout << "\n___________________\n";
        SetColor(7);

    }
    static string _ReadAccountNumber() {
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient") << ": ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public : 
    static void ShowWithdrawScreen() {
        _DrawScreenHeader("\t  "+ clsLang::ToLang("WithdrawScreen"));

        string AccountNumber = "";
        AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("ClientNotFound") << " : ";
            SetColor(7);
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);

        double Amount = 0;
        cout << "\n" << clsLang::ToLang("EnterWithdrawAmount") << " : ";
        Amount = clsInputValidate::ReadNumber<double>();

        SetColor(12);
        cout << "\n" << clsLang::ToLang("ConfirmTransaction") << " [Y/N]: ";
        SetColor(7);

        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            if(Client.Withdraw(Amount))
            {
                SetColor(2);
                cout << "\n" << clsLang::ToLang("WithdrawSuccess");
                cout << "\n" << clsLang::ToLang("NewBalance") << " : " << Client.AccountBalance;
                SetColor(7);
                cout << "\n\n";
            }
            else {
                SetColor(14);
                cout << "\n" << clsLang::ToLang("InsufficientBalance");
                cout << "\n" << clsLang::ToLang("AmountToWithdraw") << " : " << Amount;
                cout << "\n" << clsLang::ToLang("YourBalance") << " : " << Client.AccountBalance;
                SetColor(7);
                cout << "\n\n";
            }

        }
        else {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("OperationCancelled");
            SetColor(7);
        }




    }
};

