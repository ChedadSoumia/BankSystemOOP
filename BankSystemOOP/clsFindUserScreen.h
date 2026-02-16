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
        cout << "\n" << clsLang::ToLang("UserCard", LangChosen) << ":";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("FirstName", LangChosen) << ":" << User.FirstName;
        cout << "\n" << clsLang::ToLang("LastName", LangChosen) << ": " << User.LastName;
        cout << "\n" << clsLang::ToLang("FullName", LangChosen) << " : " << User.FullName();
        cout << "\n" << clsLang::ToLang("Email", LangChosen) << " : " << User.Email;
        cout << "\n" << clsLang::ToLang("Phone", LangChosen) << " : " << User.Phone;
        cout << "\n" << clsLang::ToLang("UserName", LangChosen) << " : " << User.UserName;
        cout << "\n" << clsLang::ToLang("Password", LangChosen) << " : " << User.Password;
        cout << "\n" << clsLang::ToLang("Permissions", LangChosen) << " : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\t  "+ clsLang::ToLang("FUScreen", LangChosen));

        string UserName;
        cout << "\n" << clsLang::ToLang("EnterUser", LangChosen) << "!\n";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n" << clsLang::ToLang("UsernameUsed", LangChosen) << "!\n";
            UserName = clsInputValidate::ReadString();
        }


        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\n" << clsLang::ToLang("UserF",LangChosen) << " :-)\n";
        }
        else
        {
            cout << "\n" << clsLang::ToLang("UserNotF", LangChosen) << ":-(\n";
        }

        _PrintUser(User1);

    }

};

