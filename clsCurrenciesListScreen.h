#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrenciesListScreen:protected clsScreen
{

private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "|";
		cout << setw(35) << left << Currency.GetCountry()<<"|";
		
		cout << setw(12) << left << Currency.GetCurrencyCode() << "|";
		
		cout << setw(45) << left << Currency.GetCurrencyName() << "|";
		
		cout << setw(12) << left << Currency.GetRate() << "|\n";
	}

public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		short CountOfCurrencies = vCurrencies.size();
		_DrawScreenHeader("Currencies List Screen", to_string(CountOfCurrencies));
		
		if ( CountOfCurrencies == 0 )
		{
			cout << "\t\t\t\tNo Currencies Available In the System!";
			
			return;
		}
		
		else
		{
			cout << "____________________________________________________________________________________________________________\n";
			cout << "|                                   |            |                                             |            |\n";
			cout << "| Country                           | Code       | Name                                        | Rate/(1$)  |\n";
			cout << "|___________________________________|____________|_____________________________________________|____________|\n";
			for (clsCurrency& Currency : vCurrencies)
			{
				_PrintCurrency(Currency);
				cout << "|___________________________________|____________|_____________________________________________|____________|\n";
			}
			
		}
	}
	
};

