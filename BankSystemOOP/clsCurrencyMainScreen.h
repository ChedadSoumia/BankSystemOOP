#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"



class clsCurrencyMainScreen : protected clsScreen
{
	enum enCurrencyMenueOptions {
		eListCurrency = 1, eFindCurrency = 2 ,eUpdatRate = 3,
		eCurrencyCalculator = 4 , eMainMenu = 5
	};

	static short _ReadCurrencyMenueOption() {
		short Number;

		cout << setw(37) << left << "" << clsLang::ToLang("ChooseOption", LangChosen) + " [1-9] : ";
		Number = clsInputValidate::ReadShortNumberBetween(1, 5, clsLang::ToLang("ChooseOption", LangChosen) + " [1-9] : ");

		return Number;
	}

	static void _GoBackToCurrencyMenue() {

		cout << setw(37) << left << "" << "\n\t" << clsLang::ToLang("BackToCurrenciesMenu", LangChosen) << " ...\n\n";
		system("pause>0");

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
		cout << "\nCurrency Calculator Screen Will Be Here.\n";

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
		_DrawScreenHeader("\t " + clsLang::ToLang("CurrencyExchangeMainScreen", LangChosen));

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\t" << clsLang::ToLang("CurrencyExchangeMenu", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] " << clsLang::ToLang("ListCurrencies", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[2] " << clsLang::ToLang("FindCurrency", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[3] " << clsLang::ToLang("UpdateRate", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[4] " << clsLang::ToLang("CurrencyCalculator", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "\t[5] " << clsLang::ToLang("MainMenue", LangChosen) << ".\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enCurrencyMenueOptions)_ReadCurrencyMenueOption());
	}
};

