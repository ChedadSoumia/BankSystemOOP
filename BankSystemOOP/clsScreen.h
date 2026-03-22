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
        SetColor(11);
        cout << "\t\t\t\t------------------------------------------------------------------";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\n\t\t\t\t\------------------------------------------------------------------\n\n";

        SetColor(7);
        cout << "\n\n\t\t\t\t\t " << clsLang::ToLang("UserName") << " : " << CurrentUser.UserName;
        cout << "\n\n\t\t\t\t\t Date : " << clsDate::DateToString(clsDate());
        cout << "\n\n\n\n";
    }


    static bool CheckAccessRights(clsUser::enPermissions permission) {
                                                                      
        if (!CurrentUser.CheckAccessPermission(permission))
        {
            cout << "\t\t\t\t\t------------------------------------------------------------------";
            cout << "\n\n\t\t\t\t\t " + clsLang::ToLang("AccessDenied");
            cout << "\n\t\t\t\t\t------------------------------------------------------------------\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }

};

