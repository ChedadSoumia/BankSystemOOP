#pragma once
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

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
    static void _ShowListUsersScreen() {
        clsListUsersScreen::ShowUsersList();
    }
    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }


    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();

    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();

    }


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption) {
        switch (ManageUsersMenueOption) {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eMainMenue:
        {
        }
        }
    }

public:
	static void ShowManageUsersMenue() {

		system("cls");
		_DrawScreenHeader("\t" + clsLang::ToLang("ManageUSersMenue",LangChosen));


        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  " << clsLang::ToLang("UsersMenue", LangChosen) << "\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] " << clsLang::ToLang("ListUsers", LangChosen) << ".\n";
        cout << setw(37) << left << "" << "\t[2] " << clsLang::ToLang("NewUser", LangChosen) << ".\n";
        cout << setw(37) << left << "" << "\t[3] " << clsLang::ToLang("DLTUser", LangChosen) << ".\n";
        cout << setw(37) << left << "" << "\t[4] " << clsLang::ToLang("UPUser", LangChosen) << ".\n";
        cout << setw(37) << left << "" << "\t[5] " << clsLang::ToLang("FIndUser", LangChosen) << ".\n";
        cout << setw(37) << left << "" << "\t[6] "<< clsLang::ToLang("MainMenue",LangChosen) << ".\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());


	}
};

