#pragma once

#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsDeleteClientScreen : protected  clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        SetColor(13);
        cout << "\n" << clsLang::ToLang("ClientCard") << " :";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("FullName") << " : " << Client.FirstName;
        cout << "\n" << clsLang::ToLang("LastName") << " : " << Client.LastName;
        cout << "\n" << clsLang::ToLang("Email") << " : " << Client.Email;
        cout << "\n" << clsLang::ToLang("Phone") << " : " << Client.Phone;
        cout << "\n" << clsLang::ToLang("AccountNumber") << " : " << Client.GetAccountNumber();
        cout << "\n" << clsLang::ToLang("PinCode") << " : " << Client.PinCode;
        cout << "\n" << clsLang::ToLang("Balance") << " : " << Client.AccountBalance;
        cout << "\n___________________\n";
        SetColor(7);
    }

public:
    static void ShowDeleteClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
            {
                return;
            }
        }

        _DrawScreenHeader(clsLang::ToLang("DeleteClientScreen"));
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient") << ": ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("AccountExists") << " : ";
            SetColor(7);
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);
        SetColor(12);
        cout << "\n" << clsLang::ToLang("ConfirmDeleteClient") << " y/n? ";
        char Answer = 'n';
        cin >> Answer;
        SetColor(7);


        if (Answer == 'y' || Answer == 'Y') {
            if (Client.Delete())
            {
                SetColor(2);
                cout << "\n" << clsLang::ToLang("AccountDeleted") << ":-)\n";
                SetColor(7);
                _Print(Client);
            }
            else
            {
                SetColor(12);
                cout << "\n" << clsLang::ToLang("ErrorDeleteClient") << "\n";
                SetColor(7);
            }
        }


    }

};

