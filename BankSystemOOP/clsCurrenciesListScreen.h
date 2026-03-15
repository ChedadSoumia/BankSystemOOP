#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"


class clsCurrenciesListScreen : protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency Currency) {

        cout << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(19) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();

    }


public:
    static void ShowCurrenciesListScreen() {
        vector <clsCurrency> _vCurrencies = clsCurrency::GetCurrenciesList();

        string Title = "\t " + clsLang::ToLang("CurrenciesListScreen", LangChosen);
        string SubTitle = "\t  (" + to_string(_vCurrencies.size()) + ") " +
            clsLang::ToLang("Currencies", LangChosen);
        _DrawScreenHeader(Title, SubTitle);

        cout << "| " << left << setw(30) << clsLang::ToLang("Country", LangChosen);
        cout << "| " << left << setw(19) << clsLang::ToLang("CurrencyCode", LangChosen);
        cout << "| " << left << setw(40) << clsLang::ToLang("CurrencyName", LangChosen);
        cout << "| " << left << setw(12) << clsLang::ToLang("Rate", LangChosen);
        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

       
            for (clsCurrency& Currency : _vCurrencies)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;


    }

};