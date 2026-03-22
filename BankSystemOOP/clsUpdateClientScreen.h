#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client) {

        SetColor(3);
        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("FirstName") << " : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("LastName") << " : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("Email") << " : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("Phone") << " : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("PinCode") << " : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("Balance") << " : ";
        Client.AccountBalance = clsInputValidate::ReadNumber<float>();
        SetColor(7);

    }
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
    static void ShowUpdateClientScreen() {


        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {
            {
                return;
            }
        }

        _DrawScreenHeader(clsLang::ToLang("UpdateClientScreen"));
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient") << ": ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("AccountNotFound") << " : ";
            SetColor(7);
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);

        cout << "\n\n" << clsLang::ToLang("UpdateClient") << ":";
        cout << "\n____________________\n";

        _ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save();

        switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded:
            SetColor(2);
            cout << "\n" << clsLang::ToLang("AccountUpdated") << ":-)\n";
            SetColor(14);
            _Print(Client);
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            SetColor(12);
            cout << "\n"  << clsLang::ToLang("ErrorEmptyClient");
            SetColor(7);
            break;
        };

    }

};

