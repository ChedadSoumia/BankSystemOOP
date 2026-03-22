#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <iomanip>
class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

public : 
    static void ShowTotalBalancesScreen()
    {
        _DrawScreenHeader("\t " + clsLang::ToLang("TotalBalancesScreen"));

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
        SetColor(3);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        SetColor(7);
        cout << "| " << left << setw(15) << clsLang::ToLang("AccountNumber");
        cout << "| " << left << setw(40) << clsLang::ToLang("FullName");
        cout << "| " << left << setw(12) << clsLang::ToLang("Balance");
        SetColor(3);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        SetColor(7);
        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\t" << clsLang::ToLang("NoClients");
        else

            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
        SetColor(3);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        SetColor(2);
        cout << "\t\t\t\t\t   " << clsLang::ToLang("TotalBalances") << " = " << TotalBalances << endl;
        if(LangChosen == enLang::enEN) {
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
        }
        SetColor(7);
    }


};

