#pragma once
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eShowMainMenue = 4
	};

	static short _ReadTransactionMenueOption() {
		short Number;

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		Number = clsInputValidate::ReadShortNumberBetween(1, 4, "Choose what do you want to do? [1 to 4]? ");

		return Number;
	}

	static void _GoBackToTransactionsMenue() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n\n";
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
		case enTransactionsMenueOptions::eShowMainMenue:
		{
		}
		};

	}



public:
	static void ShowTransactionsMenue() {
		system("cls");
		_DrawScreenHeader("\t\tTransaction screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionMenueOption());
	}

};

