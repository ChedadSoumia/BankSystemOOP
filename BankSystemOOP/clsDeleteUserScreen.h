#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
{

private:
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

public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\t" + clsLang::ToLang("DeleteUserScreen"));

        string UserName = "";

        cout << "\n" << clsLang::ToLang("EnterUsername") << "! ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n" << clsLang::ToLang("UserNotFound") << " ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);
        SetColor(12);
        cout << "\n" << clsLang::ToLang("ConfirmDeleteUser") << " y/n? ";
        SetColor(7);
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                SetColor(2);
                cout << "\n" << clsLang::ToLang("ConfirmDeleteUser") << " :-)\n";
                _PrintUser(User1);
                SetColor(7);
            }
            else
            {
                SetColor(12);
                cout << "\n" << clsLang::ToLang("ErrorDeleteUser") << "!\n";
                SetColor(7);
            }
        }
    }

};

