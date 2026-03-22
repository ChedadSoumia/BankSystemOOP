#pragma once
#include "clsScreen.h"
#include "clsString.h"



class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = clsLang::ToLang("CurrencyCard"))
	{
		SetColor(3);
		cout << "\n" << Title << " :";
		cout << "\n___________________";
		cout << "\n" << clsLang::ToLang("Country") << " : " << Currency.Country();
		cout << "\n" << clsLang::ToLang("CurrencyCode") << " : " << Currency.CurrencyCode();
		cout << "\n" << clsLang::ToLang("Rate") << " : " << Currency.CurrencyName();
		cout << "\n" << clsLang::ToLang("CurrencyName") << " : " << Currency.Rate();
		cout << "\n___________________\n";
		SetColor(7);

	}

	static clsCurrency _ReadCurrency(string Message) {
		
		string CurrencyCode;

		cout << "\n" << clsLang::ToLang(Message) << ": ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			SetColor(14);
			cout << "\n" << clsLang::ToLang(Message) << ": ";
			SetColor(7);
			CurrencyCode = clsInputValidate::ReadString();
		}

		return clsCurrency::FindByCode(CurrencyCode);
	}

	static double _ReadAmount() {

		double Amount;

		cout << "\n" << clsLang::ToLang("EnterAmountToExchange") << " : ";
		Amount = clsInputValidate::ReadNumber<double>();
		
		return Amount;
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, clsLang::ToLang("ConvertFrom"));
		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		SetColor(2);
		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";
		SetColor(7);
		if (Currency2.CurrencyCode() == "USD") {
			return;
		}


		_PrintCurrencyCard(Currency2, clsLang::ToLang("ConvertTo"));
		float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(AmountInUSD,Currency2);
		SetColor(2);
		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();
		SetColor(7);
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		

		char Continue = 'y';

		do {
			system("cls");

			_DrawScreenHeader("\t " + clsLang::ToLang("CalculatorScreen"));

			clsCurrency Currency1 = _ReadCurrency("EnterCurrency1Code");
			clsCurrency Currency2 = _ReadCurrency("EnterCurrency2Code");

			double Amount = _ReadAmount();

			_PrintCalculationsResults(Amount,Currency1,Currency2);

			
			cout << "\n" << clsLang::ToLang("AnotherCalculation") << " [y/n]: ";
			cin >> Continue;
		} while (Continue == 'y' || Continue == 'Y');

	}
};

