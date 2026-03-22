#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"



class clsCurrencyMainScreen : protected clsScreen
{
	enum enCurrencyMenueOptions {
		eListCurrency = 1, eFindCurrency = 2 ,eUpdatRate = 3,
		eCurrencyCalculator = 4 , eMainMenu = 5
	};

	static short _ReadCurrencyMenueOption() {
		short Number;

		cout << setw(37) << left << "" << clsLang::ToLang("ChooseOption") + " [1-5] : ";
		Number = clsInputValidate::ReadNumberBetween<short>(1, 5, clsLang::ToLang("ChooseOption") + " [1-5] : ");

		return Number;
	}

	static void _GoBackToCurrencyMenue() {
		SetColor(3);
		cout << setw(37) << left << "" << "\n\t" << clsLang::ToLang("BackToCurrenciesMenu") << " ...\n\n";
		system("pause>0");
		SetColor(7);
		ShowCurrencyMainScreen();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();

	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();

	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

	}

	static void _PerfromMainMenueOption(enCurrencyMenueOptions CurrencyOption){
		switch (CurrencyOption) {
		case enCurrencyMenueOptions::eListCurrency: {
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case enCurrencyMenueOptions::eFindCurrency: {
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case enCurrencyMenueOptions::eUpdatRate: {
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case enCurrencyMenueOptions::eCurrencyCalculator: {
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case enCurrencyMenueOptions::eMainMenu: {
			
		}
	}
	}

public:
	static void ShowCurrencyMainScreen() {
		system("cls");
		_DrawScreenHeader("\t " + clsLang::ToLang("CurrencyMenu"));

		SetColor(3);
		cout << setw(37) << left << "" << "==========================================================\n";
		cout << setw(37) << left << "" << "\t\t\t" << clsLang::ToLang("CurrencyMenu") << ".\n";
		cout << setw(37) << left << "" << "==========================================================\n";
		cout << setw(37) << left << "" << "\t[1] " << clsLang::ToLang("ListCurrencies") << ".\n";
		cout << setw(37) << left << "" << "\t[2] " << clsLang::ToLang("FindCurrency") << ".\n";
		cout << setw(37) << left << "" << "\t[3] " << clsLang::ToLang("UpdateRate") << ".\n";
		cout << setw(37) << left << "" << "\t[4] " << clsLang::ToLang("CurrencyCalculator") << ".\n";
		cout << setw(37) << left << "" << "\t[5] " << clsLang::ToLang("MainMenu") << ".\n";
		cout << setw(37) << left << "" << "==========================================================\n\n";
		SetColor(7);

		_PerfromMainMenueOption((enCurrencyMenueOptions)_ReadCurrencyMenueOption());
	}
};

