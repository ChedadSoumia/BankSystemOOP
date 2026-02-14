#pragma once
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
//#include  "clsLang.h"



class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8
	};

	static short _ReadMainMenueOption() {
		short Number;

		cout << setw(37) << left << "" << clsLang::ToLang("ChooseOption",LangChosen);
		Number = clsInputValidate::ReadShortNumberBetween(1, 8, clsLang::ToLang("ChooseOption", LangChosen));

		return Number;
	}

	static void _GoBackToMainMenue() {

		cout << setw(37) << left << "" << "\n\t" << clsLang::ToLang("PressAnyKey", LangChosen) << "...\n\n";
		system("pause>0");

		ShowMainMenue();
	}

	static void _ShowAllClientScreen() {
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen() {
		clsAddNewClientScreen::ShowAddClientScreen();
		
	}

	static void _ShowDeleteClientScreen() {
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen() {
		clsFindClientScreen::ShowFindClientScreen();
	}
	
	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionsMenue();

	}

	static void _ShowManageUsersMenue()
	{
		clsManageUsersScreen::ShowManageUsersMenue();

	}

	static void _ShowEndScreen()
	{
		

	}

	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOptions) {

		switch (MainMenueOptions) {
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			system("cls");
			_ShowEndScreen();
			//Login();

			break;
		}

		}

	}



public:
	static void ShowMainMenue() {
		system("cls");
		_DrawScreenHeader("\t "+ clsLang::ToLang("welcome", LangChosen));

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\t" << clsLang::ToLang("MainMenue", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] " << clsLang::ToLang("ShowClients", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[2] " << clsLang::ToLang("AddClient", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[3] " << clsLang::ToLang("DeleteClient", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[4] " << clsLang::ToLang("UpdateClient", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[5] " << clsLang::ToLang("FindClient", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[6] " << clsLang::ToLang("Transactions", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[7] " << clsLang::ToLang("ManageUsers", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[8] " << clsLang::ToLang("Logout", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};

