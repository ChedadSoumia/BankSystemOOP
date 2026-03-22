#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen: protected clsScreen
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
    static string ReadAccountNumber() {
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient") << ": ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:
	static void ShowDepositScreen() {
        _DrawScreenHeader("\t  " + clsLang::ToLang("DepositScreen"));

        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient") << ": ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("ClientNotFound") << " : ";
            AccountNumber = clsInputValidate::ReadString();
            SetColor(7);
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);

        double Amount = 0;
        cout << "\n" << clsLang::ToLang("EnterDepositAmount");
        
        Amount = clsInputValidate::ReadNumber<double>();

        cout << "\n" << clsLang::ToLang("ConfirmTransaction");
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            Client.Deposite(Amount);
            SetColor(2);
            cout << "\n" << clsLang::ToLang("DepositSuccess");
            cout << "\n"<< clsLang::ToLang("NewBalance") << " : " << Client.AccountBalance;
            SetColor(7);
        }
        else {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("OperationCancelled");
            SetColor(7);
        }




	}
};

