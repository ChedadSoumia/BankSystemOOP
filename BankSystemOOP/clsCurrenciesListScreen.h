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

        string Title = "\t " + clsLang::ToLang("CurrenciesListScreen");
        string SubTitle = "\t  (" + to_string(_vCurrencies.size()) + ") " +
            clsLang::ToLang("Currencies");
        _DrawScreenHeader(Title, SubTitle);
        
        SetColor(3);
        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;
        SetColor(7);

        cout << "| " << left << setw(30) << clsLang::ToLang("Country");
        cout << "| " << left << setw(19) << clsLang::ToLang("CurrencyCode");
        cout << "| " << left << setw(40) << clsLang::ToLang("CurrencyName");
        cout << "| " << left << setw(12) << clsLang::ToLang("Rate");
        SetColor(3);
        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;
        SetColor(7);
       
            for (clsCurrency& Currency : _vCurrencies)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        SetColor(3);
        cout << "\n___________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;
        SetColor(7);

    }

};