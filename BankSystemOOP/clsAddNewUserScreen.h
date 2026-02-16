#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("FirstName", LangChosen) << " : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord",LangChosen) <<
            " " << clsLang::ToLang("LastName", LangChosen) << " : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("Email", LangChosen) << " : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("Phone", LangChosen) << " : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("Password", LangChosen) << " : ";
        User.Password = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord", LangChosen) <<
            " " << clsLang::ToLang("Permissions", LangChosen) << " : ";
        User.Permissions = _ReadPermissionsToSet();;

    }

    static void _PrintUser(clsUser User)
    {
        cout << "\n" << clsLang::ToLang("UserCard",LangChosen) << ":";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("FirstName",LangChosen) << ":" << User.FirstName;
        cout << "\n" << clsLang::ToLang("LastName", LangChosen) << ": " << User.LastName;
        cout << "\n" << clsLang::ToLang("FullName", LangChosen) << " : " << User.FullName();
        cout << "\n" << clsLang::ToLang("Email", LangChosen) << " : " << User.Email;
        cout << "\n" << clsLang::ToLang("Phone", LangChosen) << " : " << User.Phone;
        cout << "\n" << clsLang::ToLang("UserName", LangChosen) << " : " << User.UserName;
        cout << "\n" << clsLang::ToLang("Password", LangChosen) << " : " << User.Password;
        cout << "\n" << clsLang::ToLang("Permissions", LangChosen) << " : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\n" << clsLang::ToLang("FullAccessQST", LangChosen) << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\n" << clsLang::ToLang("AccessQST", LangChosen) << "? y/n? ";

        cout << "\n" << clsLang::ToLang("ShowList", LangChosen) << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\n" << clsLang::ToLang("AddClient", LangChosen) << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\n" << clsLang::ToLang("DeleteClient", LangChosen) << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\n" << clsLang::ToLang("UpdateClient", LangChosen) << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\n" << clsLang::ToLang("FindClient",LangChosen) << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\n" << clsLang::ToLang("Transactions", LangChosen) << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\n" << clsLang::ToLang("ManageUsers", LangChosen) << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t " + clsLang::ToLang("NewUserScreen", LangChosen));

        string UserName = "";

        cout << "\n" << clsLang::ToLang("EnterUser", LangChosen) << "!\n";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\n" << clsLang::ToLang("UsernameUsed", LangChosen) << "!\n";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\n" << clsLang::ToLang("UserAddes", LangChosen) << " :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\n" << clsLang::ToLang("ErrorUserEmpty", LangChosen) << "!\n";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\n" << clsLang::ToLang("ErrorUserUsed",LangChosen) << "!\n";
            
            
            break;

        }
        }
    }



};

