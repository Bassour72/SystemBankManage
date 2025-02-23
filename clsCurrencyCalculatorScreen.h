#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen
{

private:


    static clsCurrency _GetCurreny(string Message)
    {
        
        string CurrencyCode = "";

        cout << Message;
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;

    }

    static int _ReadAmount()
    {
        cout << "\nEnter The Amount To Exchange: ";
        int Amount = clsInputValidate::ReadShortNumber();
        return Amount;
    }

    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
    {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.GetCountry();
        cout << "\nCode          : " << Currency.GetCurrencyCode();
        cout << "\nName          : " << Currency.GetCurrencyName();
        cout << "\nRate(1$) =    : " << Currency.GetRate();
        cout << "\n_____________________________\n\n";

    }

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.GetCurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.GetCurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.GetCurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.GetCurrencyCode();

    }


public:

	static void ShowCurrencyCalculatorScreen()
	{
        
        char Answer = 'Y';

        do
        {
          system("cls");

            _DrawScreenHeader("\tCurrency Calculator Screen");

            clsCurrency Currency1 = _GetCurreny("\nPlease Enter Currency1 Code: ");
            clsCurrency Currency2 = _GetCurreny("\nPlease Enter Currency2 Code: ");
            float Amount = _ReadAmount();
            _PrintCalculationsResults(Amount, Currency1, Currency2);

            cout << "\nDo want to perform another calculation y/n? ";
            cin >> Answer;
     
        } while (Answer == 'y' || Answer == 'Y');

	}
};

