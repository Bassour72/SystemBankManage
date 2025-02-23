#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsTransfersLogScreen :protected clsScreen
{

private:

	static void _PrintTransferLog(clsBankClient::stTransferLog Transferlog)
	{
		cout << "\n|" << setw(22) << left << Transferlog.DateAndTime;
		cout << "|" << setw(12) << left << Transferlog.DestinationClientAccountNumber;
		cout << "|" << setw(12) << left << Transferlog.SourcesClientAccountNumber;
		cout << "|" << setw(12) << left << Transferlog.Amount;
		cout << "|" << setw(12) << left << Transferlog.DestinationBalance;
		cout << "|" << setw(12) << left << Transferlog.SourcesBalance;
		cout << "|" << setw(12) << left << Transferlog.User<<"|";
		
		
	}
public:

	static void ShowTransfersLogScreen()
	{
		short Count = 0;
		vector <clsBankClient::stTransferLog> vTransferlog = clsBankClient::GetLogTransferList();
		_DrawScreenHeader("Transfer Log List Screen");
	
		cout << "\n|----------------------|------------|------------|------------|------------|------------|------------|";
		cout << "\n|   The Date /Time     | D.Account  | S.Account  |   Amount   | D.Balance  | S.Balance  |      User  |";
		cout << "\n|______________________|____________|____________|____________|____________|____________|____________|";
		
		if (vTransferlog.size() == 0)
		{
			cout << "\n|______________________|____________|____________|____________|____________|____________|____________|";
			return;

		}
		for(clsBankClient::stTransferLog &LogTransfer: vTransferlog)
		{
			_PrintTransferLog(LogTransfer);
			cout << "\n|______________________|____________|____________|____________|____________|____________|____________|";
		}
		
	}
};

