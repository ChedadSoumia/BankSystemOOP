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
        cout << "\n"<< clsLang::ToLang("FullName") << " : " << Client.FirstName;
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
	static void ShowAddClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)){
            {
                return;
            }
        }


        _DrawScreenHeader(clsLang::ToLang("AddNewClientScreen"));
        string AccountNumber = "";
        cout << "\n" << clsLang::ToLang("EnterNumClient") << ": ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber)) {
            SetColor(14);
            cout << "\n" <<clsLang::ToLang("AccountExists") << " : ";
            SetColor(7);
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            SetColor(2);
            cout << "\n" << clsLang::ToLang("AccountAdded") << " :-)\n";
            SetColor(7);
            _Print(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            SetColor(12);
            cout << "\n" << clsLang::ToLang("ErrorEmpty");
            SetColor(7);
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            SetColor(12);
            cout << "\n" << clsLang::ToLang("ErrorAccountUsed") << "\n";
            SetColor(7);
            break;

        }
        }   
	}
};

