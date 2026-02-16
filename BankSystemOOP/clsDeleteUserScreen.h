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
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\t" + clsLang::ToLang("DUSCREEN", LangChosen));

        string UserName = "";

        cout << "\n" << clsLang::ToLang("EnterUser", LangChosen) << "!\n";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n" << clsLang::ToLang("UserNOTF", LangChosen) << "\n";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\n" << clsLang::ToLang("DleteThisUserQST", LangChosen) << " y/n?\n";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\n" << clsLang::ToLang("UDSucces", LangChosen) << " :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\n" << clsLang::ToLang("ErrorDU",LangChosen) << "!\n";
                cout << "\n" << clsLang::ToLang("DleteThisUserQST",LangChosen) << "\n";
                
            }
        }
    }

};

