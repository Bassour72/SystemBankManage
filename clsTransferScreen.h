#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtility.h"
#include "clsScreen.h"

using namespace std;

class clsTransferScreen :protected clsScreen
{

private:

	static void _PrintClient(clsBankClient clsClient)
	{
		cout << "\n";
		cout << "|-----------------------|\n";
		cout << "|Client Card:           |\n";
		cout << "|_______________________|_________________________|\n";
		cout << "|The Full Name          |" << clsClient.FullName()<<"|\n";
		cout << "|The Account Number     |" << clsClient.AccountNumber()<<"|\n";
		cout << "|The current Balance    |" << clsClient.Account_Balance<<"|\n";
		cout << "|_______________________|_________________________|\n";
	}

    static string _ReadAccountNumber(string  Message)
    {
        string AccountNumber;
        cout << Message;
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > SourceClient.Account_Balance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer From: "));

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer To: "));

        _PrintClient(DestinationClient);

        float Amount = _ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.Username))
            {
                cout << "\nTransfer done successfully\n";
                
            }
            else
            {
                cout << "\nTransfer Failed \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }
};

