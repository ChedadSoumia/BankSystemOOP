#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client) {

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("FirstName", LangChosen) << " : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("LastName", LangChosen) << " : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("Email", LangChosen) << " : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("Phone", LangChosen) << " : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("PinCode", LangChosen) << " : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("balance", LangChosen) << " : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }
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

public:
    static void ShowUpdateClientScreen() {
        _DrawScreenHeader(clsLang::ToLang("UpdateClientScreen", LangChosen));
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient", LangChosen) << ": ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\n" << clsLang::ToLang("ChooseAnother", LangChosen) << " : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);

        cout << "\n\n" << clsLang::ToLang("UpdateClient", LangChosen) << ":";
        cout << "\n____________________\n";

        _ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save();

        switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\n" << clsLang::ToLang("ErrorEmpty", LangChosen) << ":-)\n";
            _Print(Client);
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\n"  << clsLang::ToLang("ErrorEmpty",LangChosen);
            break;
        };

    }

};

