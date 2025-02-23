#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsCurrencyMainScreen :protected clsScreen
{
private:

	enum enCurrencyMenuOptions
	{
		enListCurrencies=1,
		enFindCurrency=2,
		enUpdateRate=3,
		enCurrencyCalculator=4,
		enGoBackMianMenu=5

	};

	static short _ReadOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GotBackCurrencyMainScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back Currency Main Screen...\n";

		system("pause>0");
		
		ShowMainScreenCurrency();
	}

	static void _ShowCurrencyListScreen()
	{
		//cout << "\nThe show currency list will be here soon...";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nThe show find currency  will be here soon...";
		clsFindCurrency::ShowFindCurrencyOnScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nThe show update rate will be here soon...";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nThe show currency Calculator will be here soon...";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
		
		
	}

	static void PerformOptions(enCurrencyMenuOptions CurrencyMenuOptions)
	{
		switch (CurrencyMenuOptions)
		{
		case clsCurrencyMainScreen::enListCurrencies:
		{
			system("cls");
			_ShowCurrencyListScreen();
			_GotBackCurrencyMainScreen();
			break;
		}

		case clsCurrencyMainScreen::enFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GotBackCurrencyMainScreen();
			break;
		}

		case clsCurrencyMainScreen::enUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GotBackCurrencyMainScreen();
			break;
		}

		case clsCurrencyMainScreen::enCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GotBackCurrencyMainScreen();
			break;
		}

		case clsCurrencyMainScreen::enGoBackMianMenu:
		{
			system("cls");
			break;
		}

		}
	}

public:

	static void ShowMainScreenCurrency()
	{
		system("cls");

		if (!_CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawScreenHeader("Currency Exchange Main Screen ");
	
		cout << setw(37) << left << "" << "======================================\n";
		cout << setw(37) << left << "" << "\t  Currency Exchange Main \n";
		cout << setw(37) << left << "" << "======================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currency.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "======================================\n";
		PerformOptions((enCurrencyMenuOptions)_ReadOptions());
	}
};

