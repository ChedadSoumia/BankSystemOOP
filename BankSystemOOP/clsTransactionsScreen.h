#pragma once
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6
	};

	static short _ReadTransactionMenueOption() {
		short Number;

		cout << setw(37) << left << "" << clsLang::ToLang("ChooseOption") << "[1 to 6] ? ";
		Number = clsInputValidate::ReadNumberBetween<short>(1, 6, clsLang::ToLang("ChooseOption") + ": [1 to 6]? ");

		return Number;
	}

	static void _GoBackToTransactionsMenue() {
		SetColor(3);
		cout << setw(37) << left << "" << "\n\t" << clsLang::ToLang("BackToTransactionMenu") << "...\n\n";
		SetColor(7);
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
	static void _ShowTransferLogScreen() {
		clsTransferLogScreen::ShowTransferLogScreen();
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
		case enTransactionsMenueOptions::eTransferLog: {
			system("cls");
			_ShowTransferLogScreen();
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
		_DrawScreenHeader("\t\t" + clsLang::ToLang("TransactionsScreen"));
		SetColor(3);
		cout << setw(37) << left << "" << "==========================================================\n";
		cout << setw(37) << left << "" << "\t\t\t" <<clsLang::ToLang("TransactionMenu") << "\n";
		cout << setw(37) << left << "" << "==========================================================\n";
		cout << setw(37) << left << "" << "\t[1] " << clsLang::ToLang("Deposit") << ".\n";
		cout << setw(37) << left << "" << "\t[2] " << clsLang::ToLang("Withdraw") << ".\n";
		cout << setw(37) << left << "" << "\t[3] " << clsLang::ToLang("TotalBalances") << ".\n";
		cout << setw(37) << left << "" << "\t[4] " << clsLang::ToLang("Transfer") << ".\n";
		cout << setw(37) << left << "" << "\t[5] " << clsLang::ToLang("TransferLog") << ".\n";
		cout << setw(37) << left << "" << "\t[6] " << clsLang::ToLang("MainMenu") << ".\n";
		cout << setw(37) << left << "" << "==========================================================\n\n";
		SetColor(7);
		_PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionMenueOption());
	}

};

