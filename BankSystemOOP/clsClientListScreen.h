#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsClientListScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client) {

        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(25) << left << Client.Email;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }


public:
    static void ShowClientsList() {
        vector <clsBankClient> _vClient = clsBankClient::GetClientsList();

        string Title = "\t " + clsLang::ToLang("ClientListScreen",LangChosen);
        string SubTitle = "\t  (" + to_string(_vClient.size()) + ") Client(s)";
        _DrawScreenHeader(Title, SubTitle);
        
        
        cout << "| " << left << setw(40) << clsLang::ToLang("ClientName", LangChosen);
        cout << "| " << left << setw(25) << clsLang::ToLang("Email", LangChosen);
        cout << "| " << left << setw(12) << clsLang::ToLang("Phone", LangChosen);
        cout << "| " << left << setw(15) << clsLang::ToLang("AccountNumber", LangChosen);
        cout << "| " << left << setw(10) << clsLang::ToLang("PinCode", LangChosen);
        cout << "| " << left << setw(12) << clsLang::ToLang("Balance", LangChosen);
        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

        if (_vClient.size() == 0)
            cout << "\t\t\t\t" << clsLang::ToLang("NoClients",LangChosen) << "!";

        else

            for (clsBankClient& Client : _vClient)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;



    }
};

