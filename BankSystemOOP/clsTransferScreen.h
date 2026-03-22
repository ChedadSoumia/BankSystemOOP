#pragma once
#include "clsScreen.h"




class clsTransferScreen : protected clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        SetColor(3);
        cout << "\n" << clsLang::ToLang("ClientCard") << " :";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("FullName") << " : " << Client.FirstName << " "<< Client.LastName;
        cout << "\n" << clsLang::ToLang("AccountNumber") << " : " << Client.GetAccountNumber();
        cout << "\n" << clsLang::ToLang("Balance") << " : " << Client.AccountBalance;
        cout << "\n___________________\n";
        SetColor(7);

    }

    static string _ReadAccountNumber() {
        string AccountNumber = "";
        
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("ClientNotFound") << " : ";
            SetColor(7);
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }
    static clsBankClient _ReadClient() {

        string AccountNumber = _ReadAccountNumber();

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return Client;

     }

    static double _ReadAmount(clsBankClient &SourceClient) {
        double Amount;
        cout << "\n" << clsLang::ToLang("EnterAmount") << " : ";
        Amount = clsInputValidate::ReadNumber<double>();

        while (Amount > SourceClient.AccountBalance)
        {
            SetColor(14);
            cout << "\n" << clsLang::ToLang("AmountExceeds") << " ?  ";
            SetColor(7);
            Amount = clsInputValidate::ReadNumber<double>();
        }
        return Amount;
    }




public:
	static void ShowTransferScreen() {
		system("cls");
		_DrawScreenHeader("\t " + clsLang::ToLang("TransferScreen"));
	
        cout << "\n" << clsLang::ToLang("EnterFromAccount") << ": ";
        clsBankClient SourceClient = _ReadClient();
        _Print(SourceClient);

        cout << "\n" << clsLang::ToLang("EnterToAccount") << ": ";
        clsBankClient DestinationClient = _ReadClient();
        _Print(DestinationClient);


        double TransferAmount = _ReadAmount(SourceClient);
       


        char Answer = 'n';
        cout << "\n" << clsLang::ToLang("ConfirmOperation") << "[y/n] ?  ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y') {
            

            if (SourceClient.Transfer(TransferAmount, DestinationClient,CurrentUser.UserName)) {
                cout << "\n" << clsLang::ToLang("TransferSuccess") << ".";
                _Print(SourceClient);
                _Print(DestinationClient);
            }
            else {
                cout << "\n" << clsLang::ToLang("TransferFailed") << ".";
            }

        }
    
    }
};

