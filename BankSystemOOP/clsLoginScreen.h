#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include <conio.h> 

class clsLoginScreen :protected clsScreen
{
    //Hide password input on terminal
    static string _GetPassword()
    {
        string password;
        char ch;
        while ((ch = _getch()) != '\r') // eNTER
        {
            if (ch == '\b') // Backspace
            {
                if (!password.empty())
                {
                    password.pop_back();
                    cout << "\b \b"; // REMOVE *
                }
            }
            else
            {
                password.push_back(ch);
                cout << '*';
            }
        }
        cout << endl;
        return password;
    }
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
                SetColor(12);
                cout << "\n[!] " << clsLang::ToLang("InvalisUP", LangChosen) << "\n";
                cout << "[*] " << Trials << " " << clsLang::ToLang("TrialsLogin", LangChosen) << " \n\n";
                SetColor(7);
            }

            if (Trials == 0)
            {
                SetColor(12);
                cout << "\n" << clsLang::ToLang("FailedTrials", LangChosen) << " \n\n";
                SetColor(7);
                return false;
            }


            cout << left << setw(12) << clsLang::ToLang("EUser",LangChosen);
            cin >> Username;

            cout << left << setw(12) << clsLang::ToLang("EPass", LangChosen);
            Password = _GetPassword();

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
        
        _DrawScreenHeader("\t " + clsLang::ToLang("LoginScreen", LangChosen));
        
        
        return _Login();

    }

};

