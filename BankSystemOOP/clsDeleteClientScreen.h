#pragma once

#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsDeleteClientScreen : protected  clsScreen
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

public:
    static void ShowDeleteClientScreen() {
        _DrawScreenHeader(clsLang::ToLang("DLTclientScreen",LangChosen));
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient", LangChosen) << ": ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\n" << clsLang::ToLang("ChooseAnother", LangChosen) << " : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);
        cout << "\n" << clsLang::ToLang("AreDLTCl",LangChosen) << " y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (Client.Delete())
            {
                cout << "\n" << clsLang::ToLang("DLTSucc",LangChosen) << ":-)\n";

                _Print(Client);
            }
            else
            {
                cout << "\n" << clsLang::ToLang("ErrorDLT",LangChosen) << "\n";
            }
        }


    }

};

