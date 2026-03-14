#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsLang.h"


class clsLoginLogoutScreen : protected clsScreen
{
private:
    static void _PrintActionRecordLine(clsUser::stLoginLogout Actions) {

        cout << "| " << setw(40) << left << Actions.Date;
        cout << "| " << setw(20) << left << Actions.username;
        cout << "| " << setw(12) << left << Actions.password;
        cout << "| " << setw(10) << left << to_string(Actions.permission);
        cout << "| " << setw(12) << left << Actions.action;

    }
public:
	static void ShowLoginLogoutScreen(){

        if (!CheckAccessRights(clsUser::enPermissions::pRegisterScreen)) {
            {
                return;
            }
        }
        system("cls");
		_DrawScreenHeader(clsLang::ToLang("LoginLogoutRegisterS",LangChosen));

        cout << "| " << left << setw(40) << clsLang::ToLang("DateTime", LangChosen);
        cout << "| " << left << setw(20) << clsLang::ToLang("UserName", LangChosen);
        cout << "| " << left << setw(12) << clsLang::ToLang("Password", LangChosen);
        cout << "| " << left << setw(10) << clsLang::ToLang("Permissions", LangChosen);
        cout << "| " << left << setw(12) << "Action";
        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

        vector<clsUser::stLoginLogout> vActions = clsUser::GetLoginLogoutRegisterList();
	    


            for (clsUser::stLoginLogout& vAction : vActions)
            {

                _PrintActionRecordLine(vAction);
                cout << endl;
            }

        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;


	}

};

