#pragma once
#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include "clsPeriod.h"

class clsInputValidate
{
public : 

	static bool IsNumberBetween(short Number, short From, short To) {
		if (Number > From && Number < To) {
			return true;
		}
		return false;
	}
	static bool IsNumberBetween(int Number, int From, int To) {
		if (Number > From && Number < To) {
			return true;
		}
		return false;
	}
	static bool IsNumberBetween(float Number, float From, float To) {
		if (Number > From && Number < To) {
			return true;
		}
		return false;
	}
	static bool IsNumberBetween(double Number, double From, double To) {
		if (Number > From && Number < To) {
			return true;
		}
		return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		return (Date.IsDateAfterDate2(From) && Date.IsDateBeforeDate2(To));
	}

	static int ReadNumber(string Message) {
		int Number;
		
		cin >> Number;
		while (cin.fail()) { // user didn't input a number    
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}


	static int ReadIntNumberBetween( short From, short To , string Message) {
		int Number = 0;
		do {
			cout << "Please enter a number?" << endl;
			Number = ReadNumber(Message);


		} while (Number < From || Number > To);
		return Number;
	}


	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

};

