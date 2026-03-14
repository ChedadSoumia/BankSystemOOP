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

    static  bool _Login()
    {
        bool LoginFaild = false;

        short Trials = 3;

        string Username, Password;
        do
        {
            if (LoginFaild)
            {
                Trials--;

                cout << "\n" << clsLang::ToLang("InvalisUP", LangChosen) << "";
                cout << "\n " << clsLang::ToLang("YH", LangChosen)<< " " << Trials
                    << " " << clsLang::ToLang("TrialsLogin", LangChosen) << ".\n\n";
            }

            if (Trials == 0)
            {
                cout << "\n" << clsLang::ToLang("FailedTrials", LangChosen) << " \n\n";
                return false;
            }


            cout << clsLang::ToLang("EUser",LangChosen);
            cin >> Username;

            cout << clsLang::ToLang("EPass", LangChosen);
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
       
        CurrentUser.SaveLoginLog("Login");
        clsMainScreen::ShowMainMenue();
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t " + clsLang::ToLang("LoginScreen",LangChosen));
        return _Login();

    }

};

