#pragma once
#include "clsScreen.h"



class clsFindCurrencyScreen : protected clsScreen
{

private:

    enum enChoice { eCode = 1, eCountry = 2 };

    static void _PrintCurrencyCard(clsCurrency &Currency)
    {
        cout << "\n" << clsLang::ToLang("CurrencyCard", LangChosen) << " :";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("Country", LangChosen) << " : " << Currency.Country();
        cout << "\n" << clsLang::ToLang("CurrencyCode", LangChosen) << " : " << Currency.CurrencyCode();
        cout << "\n" << clsLang::ToLang("Rate", LangChosen) << " : " << Currency.CurrencyName();
        cout << "\n" << clsLang::ToLang("CurrencyName", LangChosen) << " : " << Currency.Rate();

        cout << "\n___________________\n";

    }

    static enChoice _ReadSearchOption() {
        cout << "\n" << clsLang::ToLang("FindBy", LangChosen) << " ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2);

        return (Choice == 1) ? enChoice::eCode : enChoice::eCountry;
    }

    static void _PrintResult(clsCurrency Currency) {
        if (!Currency.IsEmpty()) {
            cout << "\n" << clsLang::ToLang("CurrencyFound", LangChosen) << " :-) ";

            _PrintCurrencyCard(Currency);
        }
        else {
            cout << "\n" << clsLang::ToLang("CurrencyNotFound", LangChosen) << " :-( ";
        }
    }

public:

    static void ShowFindCurrencyScreen() {
        system("cls");
        _DrawScreenHeader("\t " + clsLang::ToLang("FindCurrencyScreen", LangChosen));

        switch (_ReadSearchOption()) {
        case enChoice::eCode:
        {
            cout << "\n" << clsLang::ToLang("EnterCurrencyCode", LangChosen) << " ";
            string SearchCurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(SearchCurrencyCode);
            _PrintResult(Currency);
            break;
        }
        case enChoice::eCountry:
        {
            cout << "\n" << clsLang::ToLang("EnterCountryName", LangChosen) << " ";
            string SearchByCountry = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(SearchByCountry);
            _PrintResult(Currency);
            break;
        }
        }
    }
};