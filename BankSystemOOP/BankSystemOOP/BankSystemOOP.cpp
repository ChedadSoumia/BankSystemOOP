#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"




void DeleteClient() {
    string AccountNumber = "";
    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();
    cout << "\nAre you sure you want to delete this client y/n? "; 
    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        if (Client.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";

            Client.Print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }


}



void PrintClientRecordBalanceLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.GetAccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.AccountBalance;

}


void ShowTotalBalances()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
    cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
}



int main()
{
    
    
    clsMainScreen::ShowMainMenue();

    return 0;
}
















//void UpdateClient() {
//
//    string AccountNumber = "";
//    cout << "\nPlease Enter client Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//
//    while (!clsBankClient::IsClientExist(AccountNumber)) {
//        cout << "\nAccount number is not found, choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient Client = clsBankClient::Find(AccountNumber);
//    Client.Print();
//
//    cout << "\n\nUpdate Client Info:";
//    cout << "\n____________________\n";
//
//    _ReadClientInfo(Client);
//
//    clsBankClient::enSaveResults SaveResult;
//    SaveResult = Client.Save();
//
//    switch (SaveResult) {
//    case clsBankClient::enSaveResults::svSucceeded:
//        cout << "\nAccount Updated Successfully :-)\n";
//        Client.Print();
//        break;
//    case clsBankClient::enSaveResults::svFaildEmptyObject:
//        cout << "\nError account was not saved because it's Empty";
//        break;
//    };
//
//}