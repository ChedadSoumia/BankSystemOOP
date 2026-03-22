#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsTransferLogScreen : protected clsScreen
{
    static void _PrintTransferLogLine(clsBankClient::stTransferLog TransferLog) {

        cout << "| " << setw(40) << left << TransferLog.Date;
        cout << "| " << setw(20) << left << TransferLog.SourceClientAccountNumber;
        cout << "| " << setw(20) << left << TransferLog.DestinationClientAccountNumber;
        cout << "| " << setw(10) << left << TransferLog.Amount;
        cout << "| " << setw(20) << left << TransferLog.SourceClientAccountBalance;
        cout << "| " << setw(20) << left << TransferLog.DestinationClientAccountBalance;
        cout << "| " << setw(12) << left << TransferLog.User;

    }



public:
	static void ShowTransferLogScreen() {
		system("cls");
		_DrawScreenHeader("\t " + clsLang::ToLang("TransferLog"));

        cout << "| " << left << setw(40) << clsLang::ToLang("DateTime");
        cout << "| " << left << setw(20) << clsLang::ToLang("SourceAccount");
        cout << "| " << left << setw(20) << clsLang::ToLang("DestinationAccount");
        cout << "| " << left << setw(12) << clsLang::ToLang("Amount");
        cout << "| " << left << setw(10) << clsLang::ToLang("SourceBalance");
        cout << "| " << left << setw(20) << clsLang::ToLang("DestinationBalance");
        cout << "| " << left << setw(20) << clsLang::ToLang("User");
        cout << "| " << left << setw(12) << "Action";
        cout << "\n_________________________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

        vector<clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferList();



        for (clsBankClient::stTransferLog& TransferLog : vTransferLog)
        {

            _PrintTransferLogLine(TransferLog);
            cout << endl;
        }

        cout << "\n_________________________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

	}
};

