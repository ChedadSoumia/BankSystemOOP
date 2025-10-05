#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode {EmptyMode = 0 , UpdateMode = 1, AddNewMode=2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;
	


	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode,"","","","","","",0);
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance) ;

		return stClientRecord;
	}

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);
		
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static vector <clsBankClient> _LoadClientsDataFromFile() {

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}


		}

		return vClients;

	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient &C : vClients)
			{
				if(C.MarkForDelete == false)
				{
					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}
	}

	void _Update() {
	
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient &Client : _vClients) {
			if (Client.GetAccountNumber() == GetAccountNumber()) {
				Client = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);

	}

	void _AddNew() {

		_AddDataLineToFile(_ConverClientObjectToLine(*this));

	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}



public :

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber , string PinCode , float AccountBalance)
		: clsPerson(FirstName , LastName,Email,Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string GetAccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec (property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec (property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void SetMarkForDelete(bool MarkForDelete) {
		_MarkForDelete = MarkForDelete;
	}
	bool GetMarkForDelete() {
		return _MarkForDelete;
	}
	__declspec (property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;



	static clsBankClient Find(string AccountNumber) {
		
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber,string PinCode) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == PinCode) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	enSaveResults Save() {

		switch (_Mode) {
		case enMode::EmptyMode:

			return enSaveResults::svFaildEmptyObject;

		case enMode::UpdateMode:

			_Update();
			return enSaveResults::svSucceeded;
			break;
		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return enSaveResults::svFaildAccountNumberExists;
			}
			else {


				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

		}

	}

	bool Delete() {

		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients) {
			if (C.GetAccountNumber() == GetAccountNumber()) {
				C.MarkForDelete = true;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}


	static float GetTotalBalances() {
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient& C : vClients) {
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;

	}

	void Deposite(double Amount) {
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount) {
		if(Amount > _AccountBalance){
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}
	
};

