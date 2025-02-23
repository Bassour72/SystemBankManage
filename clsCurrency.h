#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "clsDate.h"
#include "clsInputValidate.h"
#include "MyOwnLibraryString.h"
#include "clsScreen.h"
using namespace std;

const string CurrenciesFile = "Currencies.txt";

class clsCurrency :protected clsScreen
{
private:

	enum enMode { enEmptyMode = 0, enUpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate = 0;
	short _Rank = 0;

	static string _ConvertObjectOfCurrentToLineOfCurrent(clsCurrency Currency, string Separator = "#//#")
	{
		string DataCurrencies = "";
		DataCurrencies += Currency.GetCountry() + Separator;
		DataCurrencies += Currency.GetCurrencyCode() + Separator;
		DataCurrencies += Currency.GetCurrencyName() + Separator;
		DataCurrencies += to_string(Currency.GetRate());
		return DataCurrencies;
	}

	static  clsCurrency _ConvertLineOfCurrentToObjectCurrent(string Line, string Separator = "#//#")
	 {
		vector <string> vCurrencies;
		vCurrencies = MyOwnLibraryString::Split(Line, Separator);
		return clsCurrency(enMode::enUpdateMode, vCurrencies[0], vCurrencies[1], vCurrencies[2], stof(vCurrencies[3]));
	 }

	 static vector <clsCurrency> _LoadCurrenciesDataFromFile()
	 {
		 fstream My_File;
		 vector <clsCurrency> vCurrency;

		 clsCurrency Currency = GetEmptyCurrencyObject();

		 My_File.open(CurrenciesFile, ios::in);
		 
		 if (My_File.is_open())
		 {
			 string Line;
			 while (getline(My_File,Line))
			 {
				 Currency = _ConvertLineOfCurrentToObjectCurrent(Line);
				 vCurrency.push_back(Currency);
			 }
			 My_File.close();
		 }
		 return vCurrency;
	 }

	 static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency)
	 {
		 fstream My_File;
		 
		 My_File.open(CurrenciesFile, ios::out);

		 if (My_File.is_open())
		 {
			 
			 for (clsCurrency &Currency:vCurrency )
			 {
				 My_File<<_ConvertObjectOfCurrentToLineOfCurrent(Currency) <<endl;
			 }
			 My_File.close();
		 }
	 }

	 void _Update()
	 {
		 vector <clsCurrency> vCurrencies;

		 vCurrencies = _LoadCurrenciesDataFromFile();

		 for(clsCurrency &Currency : vCurrencies)
		 {
			 if (Currency.GetCurrencyCode() == GetCurrencyCode())
			 {
				 Currency = *this;
				 break;
			 }
		 }

		 _SaveCurrencyDataToFile(vCurrencies);
	 }

	 static clsCurrency GetEmptyCurrencyObject()
	 {
		 return clsCurrency(enMode::enEmptyMode, "", "", "",  0);
	 }

public:

	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate, short Rank = 0)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate  = Rate ;
		_Rank  = Rank ;
	}

	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrenciesDataFromFile();

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}

	string GetCountry()
	{
		return _Country;
	}

	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}

	string GetCurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	
	float GetRate()
	{
		return _Rate;
	}

	short GetRank()
	{
		return _Rank;
	}

	__declspec(property(get = GetRank, put = SetRank)) short Rank;

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = MyOwnLibraryString::UpperAllString(CurrencyCode);

		vector <clsCurrency> vCurrencies;
		fstream My_File;
		
		My_File.open(CurrenciesFile, ios::in);

		if (My_File.is_open())
		{
			string Line;
			while (getline(My_File, Line))
			{
				clsCurrency Currency = _ConvertLineOfCurrentToObjectCurrent(Line);
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					My_File.close();
					return Currency;

				}
			}
			
		}
		return GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	 {
		 Country = MyOwnLibraryString::UpperAllString(Country);

		 vector <clsCurrency> vCurrencies;
		 fstream My_File;

		 My_File.open(CurrenciesFile, ios::in);

		 if (My_File.is_open())
		 {
			 string Line;
			 while (getline(My_File, Line))
			 {
				 clsCurrency Currency = _ConvertLineOfCurrentToObjectCurrent(Line);
				 if (MyOwnLibraryString::UpperAllString(Currency.GetCountry()) == Country)
				 {
					 My_File.close();
					 return Currency;

				 }
			 }

		 }
		 return GetEmptyCurrencyObject();
	 }

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / GetRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.GetRate());

	}

};

