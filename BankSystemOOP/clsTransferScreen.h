#pragma once
#include "clsScreen.h"




class clsTransferScreen : protected clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        cout << "\n" << clsLang::ToLang("ClientCard", LangChosen) << " :";
        cout << "\n___________________";
        cout << "\n" << clsLang::ToLang("FullName", LangChosen) << " : " << Client.FirstName << " "<< Client.LastName;
        cout << "\n" << clsLang::ToLang("AccountNumber", LangChosen) << " : " << Client.GetAccountNumber();
        cout << "\n" << clsLang::ToLang("balance", LangChosen) << " : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber() {
        string AccountNumber = "";
        
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\n" << clsLang::ToLang("ClientNotFound", LangChosen) << " : ";
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
        cout << "\n" << clsLang::ToLang("EnterTransferAmount", LangChosen) << " : ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\n" << clsLang::ToLang("AmountExceedsBalance", LangChosen) << " ?  ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }




public:
	static void ShowTransferScreen() {
		system("cls");
		_DrawScreenHeader("\t " + clsLang::ToLang("TransferScreen", LangChosen));
	
        cout << "\n" << clsLang::ToLang("EnterAccountToTransferFrom", LangChosen) << ": ";
        clsBankClient SourceClient = _ReadClient();
        _Print(SourceClient);

        cout << "\n" << clsLang::ToLang("EnterAccountToTransferTo", LangChosen) << ": ";
        clsBankClient DestinationClient = _ReadClient();
        _Print(DestinationClient);


        double TransferAmount = _ReadAmount(SourceClient);
       


        char Answer = 'n';
        cout << "\n" << clsLang::ToLang("ConfirmOperation", LangChosen) << "[y/n] ?  ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y') {
            

            if (SourceClient.Transfer(TransferAmount, DestinationClient,CurrentUser.UserName)) {
                cout << "\n" << clsLang::ToLang("TransferSuccess", LangChosen) << ".";
                _Print(SourceClient);
                _Print(DestinationClient);
            }
            else {
                cout << "\n" << clsLang::ToLang("TransferFailed", LangChosen) << ".";
            }

        }
    
    }
};

