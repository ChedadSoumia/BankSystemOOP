#pragma once
#include "clsScreen.h"



class clsUpdateCurrencyRateScreen : protected clsScreen
{

    static float _ReadRate()
    {
        cout << "\n" << clsLang::ToLang("EnterNewRate") << " ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadNumber<float>();
        return NewRate;
    }

    static void _PrintCurrencyCard(clsCurrency& Currency)
    {
        SetColor(3);
        cout << "\n" << clsLang::ToLang("CurrencyCard") << " :";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("Country") << " : " << Currency.Country();
        cout << "\n" << clsLang::ToLang("CurrencyCode") << " : " << Currency.CurrencyCode();
        cout << "\n" << clsLang::ToLang("Rate") << " : " << Currency.CurrencyName();
        cout << "\n" << clsLang::ToLang("CurrencyName") << " : " << Currency.Rate();
        cout << "\n___________________\n";
        SetColor(7);

    }

public :
	static void ShowUpdateCurrencyRateScreen() {
		system("cls");
		_DrawScreenHeader("\t " + clsLang::ToLang("UpdateCurrencyRateScreen"));

        cout << "\n" << clsLang::ToLang("EnterCurrencyCode") << " ";
		string CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            SetColor(14);
            cout << "\n " << clsLang::ToLang("CurrencyNotFound") << " : ";
            SetColor(7);
            CurrencyCode = clsInputValidate::ReadString();
        }


		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrencyCard(Currency);

        char Answer = 'n';

        SetColor(12);
        cout << "\n" << clsLang::ToLang("ConfirmUpdateRate") << " ";
        SetColor(7);
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            
            float NewRate = _ReadRate();
            Currency.UpdateRate(NewRate);
            SetColor(2);
            cout << "\n" << clsLang::ToLang("RateUpdated") << " :-)";
            SetColor(7);
            _PrintCurrencyCard(Currency);
        }

	}
};

