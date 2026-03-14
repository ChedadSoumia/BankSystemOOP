#pragma once
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eTransfer = 4, eShowMainMenue = 5
	};

	static short _ReadTransactionMenueOption() {
		short Number;

		cout << setw(37) << left << "" << clsLang::ToLang("ChooseOption",LangChosen) << "[1 to 5] ? ";
		Number = clsInputValidate::ReadShortNumberBetween(1, 5, clsLang::ToLang("ChooseOption", LangChosen) + ": [1 to 5]? ");

		return Number;
	}

	static void _GoBackToTransactionsMenue() {
		cout << setw(37) << left << "" << "\n\t" << clsLang::ToLang("BackToTransactionMenu", LangChosen) << "...\n\n";
		system("pause>0");

		ShowTransactionsMenue();
	}
	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTransferScreen();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption) {
		switch (TransactionsMenueOption) {
		case enTransactionsMenueOptions::eDeposit:
		{

			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eWithdraw: {
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTotalBalance: {
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransfer: {
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowMainMenue:
		{
		}
		};

	}



public:
	static void ShowTransactionsMenue() {
		
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
			{
				return;
			}
		}
		
		system("cls");
		_DrawScreenHeader("\t\t" + clsLang::ToLang("TransactionScreen",LangChosen));

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\t" <<clsLang::ToLang("TransactionMenu",LangChosen) << "\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] " << clsLang::ToLang("Deposit", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[2] " << clsLang::ToLang("Withdraw", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[3] " << clsLang::ToLang("TotalBalances", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[4] " << clsLang::ToLang("Transfer", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[5] " << clsLang::ToLang("MainMenu", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionMenueOption());
	}

};

