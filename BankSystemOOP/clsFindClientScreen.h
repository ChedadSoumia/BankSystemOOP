#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
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

public:

    static void ShowFindClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
            {
                return;
            }
        }

        _DrawScreenHeader(clsLang::ToLang("FindClientScreen"));
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient") << ": ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("ClientNotFound") << " : ";
            SetColor(7);
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty()) {
            SetColor(2);
            cout << "\n" << clsLang::ToLang("ClientFound") << " :-)\n";
            SetColor(7);
            _Print(Client);
        }
        

    }

};

