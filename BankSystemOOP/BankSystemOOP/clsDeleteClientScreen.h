#pragma once

#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsDeleteClientScreen : protected  clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteClientScreen() {
        _DrawScreenHeader("Delete Client Screen");
        string AccountNumber = "";
        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);
        cout << "\nAre you sure you want to delete this client y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _Print(Client);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }


    }

};

