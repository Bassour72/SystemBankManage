#pragma once
#include <iostream>
#include "clsDate.h"
#include "MyOwnLibraryString.h"
#include "clsUtility.h"

using namespace std;
class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
		{
			return true;

		}
		else
		{
			return false;
		}

	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
		{
			return true;
			

		}
		else
		{
			return false;
		}
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
		{
			return true;

		}
		else
		{
			return false;
		}
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
		{
			return true;

		}
		else
		{
			return false;
		}
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{

		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumber(string ErrorMessage="Invalid number please enter correct  value \n")
	{
		int Int_Number = 0;
		
		while (!(cin >> Int_Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Int_Number;

	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static  int ReadIntNumberBetween( int From, int To,string  ErrorMessage= "Number is not within range\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
		

	}

	static  double ReadDblNumber(string ErrorMessage="Invalid number please enter correct  value \n")
	{
		double Dbl_Number = 0;

		while (!(cin >> Dbl_Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Dbl_Number;


	}

	static  float ReadFloatNumber(string ErrorMessage = "Invalid number please enter correct  value \n")
	{
		float Dbl_Number = 0;

		while (!(cin >> Dbl_Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Dbl_Number;


	}

	static double ReadDblNumberBetween(double From, double To, string  ErrorMessage= "Number is not within range\n")
	{
		double Dbl_Number = 0;
		Dbl_Number = ReadIntNumber();
		while (!IsNumberBetween(Dbl_Number , From ,  To))
		{
			cout << ErrorMessage;
			Dbl_Number = ReadDblNumber();

		}
		return Dbl_Number;

	}

	static bool IsValidData(clsDate Date1)
	{
		return clsDate::IsValidDate(Date1);
	}

	static string ReadString(string Message ="")
	{
		string  S1 = "";
		// Usage of std::ws will extract all the whitespace character
		cout << Message;
		getline(cin >> ws, S1);
		return S1;
	}
	
};
