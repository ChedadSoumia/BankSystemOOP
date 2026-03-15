#pragma once
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginLogoutScreen.h"
#include "clsCurrencyMainScreen.h"
#include  "Global.h"



class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7,eLoginLogoutRegister = 8 ,eCurrency = 9,eExit = 10
	};

	static short _ReadMainMenueOption() {
		short Number;

		cout << setw(37) << left << "" << clsLang::ToLang("ChooseOption",LangChosen) + " [1-10] : ";
		Number = clsInputValidate::ReadShortNumberBetween(1, 10, clsLang::ToLang("ChooseOption", LangChosen) + " [1-10] : ");

		return Number;
	}

	static void _GoBackToMainMenue() {


		SetColor(2);
		cout << setw(37) << left << "" << "\n\t" << clsLang::ToLang("PressAnyKey", LangChosen) << " " << 
			clsLang::ToLang("MainMenu", LangChosen) << "...\n\n";
		SetColor(7);
		system("pause>0");
		ShowMainMenue();
	}
	static void Logout()
	{
		CurrentUser = clsUser::Find("", "");
		CurrentUser.SaveLoginLog("Logout");
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

	static void _ShowLoginLogoutScreen() {
		clsLoginLogoutScreen::ShowLoginLogoutScreen();
	}
	static void _ShowCurrencyMainScreen() {
		clsCurrencyMainScreen::ShowCurrencyMainScreen();
	}



	static void _Logout()
	{
		Logout();
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
		case enMainMenueOptions::eLoginLogoutRegister:
		{
			system("cls");
			_ShowLoginLogoutScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrency:
		{
			system("cls");
			_ShowCurrencyMainScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			system("cls");
			_Logout();
			break;
		}

		}

	}



public:
	static void ShowMainMenue() {
		system("cls");
		_DrawScreenHeader("\t "+ clsLang::ToLang("welcome", LangChosen));
		SetColor(3);
		cout << setw(37) << left << "" << "==========================================================\n";
		cout << setw(37) << left << "" << "\t\t\t" << clsLang::ToLang("MainMenue", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "==============================================================\n";
		cout << setw(37) << left << "" << "\t[1] " << clsLang::ToLang("ShowClients", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[2] " << clsLang::ToLang("AddClient", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[3] " << clsLang::ToLang("DeleteClient", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[4] " << clsLang::ToLang("UpdateClient", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[5] " << clsLang::ToLang("FindClient", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[6] " << clsLang::ToLang("Transactions", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[7] " << clsLang::ToLang("ManageUsers", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[8] " << clsLang::ToLang("LoginLogoutRegister", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[9] " << clsLang::ToLang("CurrencyExchangeMenu", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[10] " << clsLang::ToLang("Logout", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "============================================================\n";
		SetColor(7);
		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};

