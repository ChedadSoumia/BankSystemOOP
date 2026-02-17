#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  void _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\n" << clsLang::ToLang("InvalisUP", LangChosen) <<"\n\n";
            }

            cout << clsLang::ToLang("EUser",LangChosen);
            cin >> Username;

            cout << clsLang::ToLang("EPass", LangChosen);
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        clsMainScreen::ShowMainMenue();

    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t " + clsLang::ToLang("LoginScreen",LangChosen));
        _Login();

    }

};

