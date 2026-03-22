#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
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

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\t  "+ clsLang::ToLang("FindUserScreen"));

        string UserName;
        cout << "\n" << clsLang::ToLang("EnterUsername") << "? ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("UserNotFound") << "? ";
            SetColor(7);
            UserName = clsInputValidate::ReadString();
        }


        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
        {
            SetColor(2);
            cout << "\n" << clsLang::ToLang("UserFound") << " :-)\n";
            SetColor(7);
            _PrintUser(User1);
        }
        else
        {
            SetColor(12);
            cout << "\n" << clsLang::ToLang("UserNotFound") << ":-(\n";
            SetColor(7);
        }

        

    }

};

