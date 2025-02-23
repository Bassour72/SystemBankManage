#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "MyOwnLibraryString.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsFindCurrency :protected clsScreen
{

private:

	enum enFindCurrencyByCodeOrCountry
	{
		enFindByCode = 1, enFindByCountry = 2
	};

	 static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nThe Currency card              : ";
		cout << "\n\n_________________________________________________________\n";
		cout << "\nThe Name of Country is        : " << Currency.GetCountry();
		cout << "\nThe Currency Code is           : " << Currency.GetCurrencyCode();
		cout << "\nThe Name of Currency  is      : " << Currency.GetCurrencyName();
		cout << "\nThe Rate of Currency vs ($/1) : " << Currency.GetRate();
		cout << "\n_________________________________________________________\n";

		
	}

	static enFindCurrencyByCodeOrCountry _ReadChoice()
	{
		cout << "Find By: [1] Code or Find By: [2] Country ?  ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2 );
		return (enFindCurrencyByCodeOrCountry) Choice;
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public:


	static void ShowFindCurrencyOnScreen()
	{
		_DrawScreenHeader("Find Currency Screen ");

		enFindCurrencyByCodeOrCountry FindCurrency = _ReadChoice();

		switch (FindCurrency)
		{

		case enFindCurrencyByCodeOrCountry::enFindByCode:
		{
			clsCurrency Currrency = clsCurrency::FindByCode(clsInputValidate::ReadString("Please enter code of currency ? "));

			_ShowResults(Currrency);

			break;
		}

		case enFindCurrencyByCodeOrCountry::enFindByCountry:
		{
			clsCurrency Currrency = clsCurrency::FindByCountry(clsInputValidate::ReadString("Please enter Country name ? "));

			_ShowResults(Currrency);

			break;
		}

		default:
			break;
		}
	}


};

