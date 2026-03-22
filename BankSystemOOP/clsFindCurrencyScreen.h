#pragma once
#include "clsScreen.h"



class clsFindCurrencyScreen : protected clsScreen
{

private:

    enum enChoice { eCode = 1, eCountry = 2 };

    static void _PrintCurrencyCard(clsCurrency &Currency)
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

    static enChoice _ReadSearchOption() {
        cout << "\n" << clsLang::ToLang("FindBy") << " ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 2);

        return (Choice == 1) ? enChoice::eCode : enChoice::eCountry;
    }

    static void _PrintResult(clsCurrency Currency) {
        if (!Currency.IsEmpty()) {
            SetColor(2);
            cout << "\n" << clsLang::ToLang("CurrencyFound") << " :-) ";
            SetColor(7);

            _PrintCurrencyCard(Currency);
        }
        else {
            SetColor(12);
            cout << "\n" << clsLang::ToLang("CurrencyNotFound") << " :-( ";
            SetColor(7);
        }
    }

public:

    static void ShowFindCurrencyScreen() {
        system("cls");
        _DrawScreenHeader("\t " + clsLang::ToLang("FindCurrencyScreen"));

        switch (_ReadSearchOption()) {
        case enChoice::eCode:
        {
            cout << "\n" << clsLang::ToLang("EnterCurrencyCode") << " ";
            string SearchCurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(SearchCurrencyCode);
            _PrintResult(Currency);
            break;
        }
        case enChoice::eCountry:
        {
            cout << "\n" << clsLang::ToLang("EnterCountry") << " ";
            string SearchByCountry = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(SearchByCountry);
            _PrintResult(Currency);
            break;
        }
        }
    }
};