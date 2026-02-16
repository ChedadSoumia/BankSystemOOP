#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsListUsersScreen :protected clsScreen
{

private:
    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }

public:

    static void ShowUsersList()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t" + clsLang::ToLang("UserList",LangChosen) + "";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") " + clsLang::ToLang("User-s", LangChosen)+ ".";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << clsLang::ToLang("UserName", LangChosen);
        cout << "| " << left << setw(25) << clsLang::ToLang("FullName", LangChosen);
        cout << "| " << left << setw(12) << clsLang::ToLang("Phone", LangChosen);
        cout << "| " << left << setw(20) << clsLang::ToLang("Email", LangChosen);
        cout << "| " << left << setw(10) << clsLang::ToLang("Password", LangChosen);
        cout << "| " << left << setw(12) << clsLang::ToLang("Permissions", LangChosen);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\t" << clsLang::ToLang("NoUsers", LangChosen) ;
        else

            for (clsUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }


};

