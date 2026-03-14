#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsLang.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;


class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\n\t\t\t\t\t " << clsLang::ToLang("UserEX1",LangChosen) << " : " << CurrentUser.UserName;
        cout << "\n\n\t\t\t\t\t " << clsLang::ToLang("DateEX1", LangChosen) << " : " << clsDate::DateToString(clsDate());
        cout << "\n\n";
    }


    static bool CheckAccessRights(clsUser::enPermissions permission) {
                                                                      
        if (!CurrentUser.CheckAccessPermission(permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t " + clsLang::ToLang("AccessDenied",LangChosen);
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }

};

