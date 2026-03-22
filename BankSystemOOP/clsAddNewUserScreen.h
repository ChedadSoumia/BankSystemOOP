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
        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("FirstName") << " : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("LastName") << " : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("Email") << " : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("Phone") << " : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("Password") << " : ";
        User.Password = clsInputValidate::ReadString();

        cout << "\n" << clsLang::ToLang("EnterWord") <<
            " " << clsLang::ToLang("Permissions") << " : ";
        User.Permissions = _ReadPermissionsToSet();;

    }

    static void _PrintUser(clsUser User)
    {
        SetColor(3);
        cout << "\n" << clsLang::ToLang("UserCard") << ":";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("FirstName") << ":" << User.FirstName;
        cout << "\n" << clsLang::ToLang("LastName") << ": " << User.LastName;
        cout << "\n" << clsLang::ToLang("FullName") << " : " << User.FullName();
        cout << "\n" << clsLang::ToLang("Email") << " : " << User.Email;
        cout << "\n" << clsLang::ToLang("Phone") << " : " << User.Phone;
        cout << "\n" << clsLang::ToLang("UserName") << " : " << User.UserName;
        cout << "\n" << clsLang::ToLang("Password") << " : " << User.Password;
        cout << "\n" << clsLang::ToLang("Permissions") << " : " << User.Permissions;
        cout << "\n___________________\n";
        SetColor(7);

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\n" << clsLang::ToLang("FullAccessQST") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\n" << clsLang::ToLang("AccessQST") << "? y/n? ";

        cout << "\n" << clsLang::ToLang("ShowList") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\n" << clsLang::ToLang("AddClient") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\n" << clsLang::ToLang("DeleteClient") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\n" << clsLang::ToLang("UpdateClient") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\n" << clsLang::ToLang("FindClient") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\n" << clsLang::ToLang("Transactions") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\n" << clsLang::ToLang("ManageUsers") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\n" << clsLang::ToLang("LoginLogoutRegister") << "? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pRegisterScreen;
        }

        return Permissions;

    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t " + clsLang::ToLang("NewUserScreen"));

        string UserName = "";

        cout << "\n" << clsLang::ToLang("EnterUsername") << "!\n";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("UsernameUsed") << "!\n";
            SetColor(7);
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
            SetColor(2);
            cout << "\n" << clsLang::ToLang("UserAdded") << " :-)\n";
            SetColor(7);
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            SetColor(12);
            cout << "\n" << clsLang::ToLang("ErrorUserEmpty") << "!\n";
            SetColor(7);
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            SetColor(12);
            cout << "\n" << clsLang::ToLang("ErrorUserUsed") << "!\n";
            SetColor(7);
            
            
            break;

        }
        }
    }



};

