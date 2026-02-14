#pragma once
#include "clsScreen.h"

class clsManageUsersScreen : protected clsScreen
{



private :
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};
    static short ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << clsLang::ToLang("Choose16",LangChosen) << " ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, clsLang::ToLang("Enter16", LangChosen) + " ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\n" << clsLang::ToLang("GoBackManageMenue",LangChosen) << "...";
        system("pause>0");
        ShowManageUsersMenue();
    }


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption) {

    }

public:
	static void ShowManageUsersMenue() {

		system("cls");
		_DrawScreenHeader("\t" + clsLang::ToLang("UsersSCR",LangChosen));


        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());


	}
};

