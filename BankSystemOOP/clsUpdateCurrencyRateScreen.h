#pragma once
#include "clsScreen.h"



class clsUpdateCurrencyRateScreen : protected clsScreen
{

    static float _ReadRate()
    {
        cout << "\n" << clsLang::ToLang("EnterNewRate", LangChosen) << " ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

    static void _PrintCurrencyCard(clsCurrency& Currency)
    {
        cout << "\n" << clsLang::ToLang("CurrencyCard", LangChosen) << " :";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("Country", LangChosen) << " : " << Currency.Country();
        cout << "\n" << clsLang::ToLang("CurrencyCode", LangChosen) << " : " << Currency.CurrencyCode();
        cout << "\n" << clsLang::ToLang("Rate", LangChosen) << " : " << Currency.CurrencyName();
        cout << "\n" << clsLang::ToLang("CurrencyName", LangChosen) << " : " << Currency.Rate();

        cout << "\n___________________\n";

    }

public :
	static void ShowUpdateCurrencyRateScreen() {
		system("cls");
		_DrawScreenHeader("\t " + clsLang::ToLang("UpdateCurrencyRateScreen", LangChosen));

        cout << "\n" << clsLang::ToLang("EnterCurrencyCode", LangChosen) << " ";
		string CurrencyCode = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrencyCard(Currency);

        char Answer = 'n';
        cout << "\n" << clsLang::ToLang("ConfirmUpdateRate", LangChosen) << " ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            
            float NewRate = _ReadRate();
            Currency.UpdateRate(NewRate);
            cout << "\n" << clsLang::ToLang("RateUpdateSuccess", LangChosen) << " :-)";
            _PrintCurrencyCard(Currency);
        }

	}
};

