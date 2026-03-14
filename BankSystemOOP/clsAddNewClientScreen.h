#pragma once
#include <iostream>
#include <string>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "Global.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client) {

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("FirstName", LangChosen) << " : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord",LangChosen) <<
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
        cout << "\n" << clsLang::ToLang("ClientCard",LangChosen) << " :";
        cout << "\n___________________";
        cout << "\n"<< clsLang::ToLang("ClientName", LangChosen) << " : " << Client.FirstName;
        cout << "\n" << clsLang::ToLang("LastName", LangChosen) << " : " << Client.LastName;
        cout << "\n" << clsLang::ToLang("Email", LangChosen) << " : " << Client.Email;
        cout << "\n" << clsLang::ToLang("Phone", LangChosen) << " : " << Client.Phone;
        cout << "\n" << clsLang::ToLang("AccountNumber", LangChosen) << " : " << Client.GetAccountNumber();
        cout << "\n" << clsLang::ToLang("PinCode", LangChosen) << " : " << Client.PinCode;
        cout << "\n" << clsLang::ToLang("Balance", LangChosen) << " : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
	static void ShowAddClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)){
            {
                return;
            }
        }


        _DrawScreenHeader(clsLang::ToLang("AddNewClientScreen", LangChosen));
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient",LangChosen) << ": ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\n" <<clsLang::ToLang("ChooseAnother",LangChosen) << " : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\n" << clsLang::ToLang("AccountAddSuccess",LangChosen) << " :-)\n";
            _Print(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\n" << clsLang::ToLang("ErrorEmpty",LangChosen);
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\n" << clsLang::ToLang("ErrorAccountUsed",LangChosen) << "\n";
            break;

        }
        }   
	}
};

