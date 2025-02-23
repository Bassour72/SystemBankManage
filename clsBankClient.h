#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "MyOwnLibraryString.h"
#include "clsPerson.h"
#include "clsDate.h"

const string string_File_Info_Of_Client = "ClientInfo.txt";
const string LogFileTransfer = "TransferLog.txt";

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode {enEmptyMode=0, enUpdateMode=1, enAddedNewMode=2};
	enMode _Mode;
	string _Account_Number;
	string _Pin_Code;
	double _Account_Balance = 0;
	bool _MarkForDelete = false;

	 string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient ,string Username,string Separator="#//#")
	 {

		 string LogTransfer = "";
		 LogTransfer += clsDate::GetSystemDateTimeString() + Separator;
		 LogTransfer += AccountNumber() + Separator;
		 LogTransfer += DestinationClient.AccountNumber() + Separator;
		 LogTransfer += to_string(Amount) + Separator;
		 LogTransfer += to_string(Account_Balance) + Separator;
		 LogTransfer += to_string(DestinationClient.Account_Balance) +Separator;
		 LogTransfer += Username;
		 return LogTransfer;
	 }

	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector <string> vClientData;
		vClientData = MyOwnLibraryString::Split(Line, Separator);
		return clsBankClient(enMode::enUpdateMode,vClientData[0], vClientData[1], vClientData[2],vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> _vClients;
		fstream _My_File;
		_My_File.open(string_File_Info_Of_Client, ios::in);
		if (_My_File.is_open())
		{
			string _Line;
			while (getline(_My_File, _Line))
			{
				clsBankClient _Client1 = _ConvertLineToClientObject(_Line, "#//#");
				_vClients.push_back(_Client1);
			}
			_My_File.close();
		}
		return _vClients;
	}

	static string _ConvertClientObjectToLine(clsBankClient Client ,string Separator = "#//#")
	{
		string _DataLine ="";
		_DataLine += Client.First_Name + Separator;
		_DataLine += Client.Last_Name + Separator;
		_DataLine += Client.Email + Separator;
		_DataLine += Client.Phone_Number + Separator;
		_DataLine += Client.AccountNumber() + Separator;
		_DataLine += Client.PinCode + Separator;
		_DataLine += to_string(Client.Account_Balance);
		return _DataLine;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> _vClients)
	{
		fstream _My_File;
		_My_File.open(string_File_Info_Of_Client, ios::out);
		string DataLine;
		if (_My_File.is_open())
		{
			for (clsBankClient &Client : _vClients)
			{
				if (Client.MarkedForDeleted() == false)
				{
					DataLine = _ConvertClientObjectToLine(Client, "#//#");
					_My_File << DataLine << endl;
				}
				
			}
			_My_File.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient &Client : _vClients)
		{
			if(Client.AccountNumber() == AccountNumber() )
			{
				Client = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	static void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("ClientInfo.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open(LogFileTransfer, ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	struct stTransferLog;

	static stTransferLog _ConvertLineOfTransferLogToRecord(string Line, string Separator="#//#")
	{
		stTransferLog DataTransferLog;
		vector <string> vData;
		vData = MyOwnLibraryString::Split(Line, Separator);
		DataTransferLog.DateAndTime = vData[0];
		DataTransferLog.SourcesClientAccountNumber = vData[1];
		DataTransferLog.DestinationClientAccountNumber = vData[2];
		DataTransferLog.Amount = stof(vData[3]);
		DataTransferLog.SourcesBalance = stod(vData[4]);
		DataTransferLog.DestinationBalance = stod(vData[5]);
		DataTransferLog.User = vData[6];
		return DataTransferLog;
	}


public:

	struct stTransferLog
	{
		string SourcesClientAccountNumber;
		string DestinationClientAccountNumber;
		string DateAndTime;
		string User;
		double Amount = 0;
		double SourcesBalance = 0;
		double DestinationBalance = 0;



	};

	clsBankClient(enMode Mode,string First_Name, string Last_Name, string Email, string Phone_Number,
		string Account_Number, string Pin_Code, double Account_Balance):clsPerson(First_Name, Last_Name, Email, Phone_Number)
	{
		_Mode = Mode;
		 _Account_Number = Account_Number;
		 _Pin_Code = Pin_Code;
		 _Account_Balance = Account_Balance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkForDelete;
	}

	 string AccountNumber()
	{
		return _Account_Number;
	}

	void SetPinCode(string PinCode)
	{
		_Pin_Code = PinCode;
	}

	string GetPinCode()
	{
		return _Pin_Code;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_Account_Balance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _Account_Balance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double  Account_Balance;

	void Print()
	{
		cout << "\nClient Card: ";
		cout << "\n________________________________________\n";
		cout << "\nThe first name    : " << First_Name;
		cout << "\nThe last name     : " << Last_Name;
		cout << "\nThe full name     : " << FullName();
		cout << "\nThe email         : " << Email;
		cout << "\nThe phone number  : " << Phone_Number;
		cout << "\nAccount Number    : " << _Account_Number;
		cout << "\nPassword          : " << _Pin_Code;
		cout << "\nCurrent balance   : " << _Account_Balance;
		cout << "\n Mode             : " << _Mode;
		cout << "\n________________________________________\n";

	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream My_File;

		vector <clsBankClient> vClients;

		My_File.open(string_File_Info_Of_Client, ios::in);
		if (My_File.is_open())
		{
			string Line;
			while (getline(My_File, Line))
			{
				clsBankClient Client =_ConvertLineToClientObject(Line);
				if (Client.AccountNumber() ==AccountNumber)
				{
					My_File.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			My_File.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber , string PinCode)
	{
		fstream My_File;

		vector <clsBankClient> vClients;

		My_File.open(string_File_Info_Of_Client, ios::in);
		if (My_File.is_open())
		{
			string Line;
			while (getline(My_File, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					My_File.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			My_File.close();
		}
		return _GetEmptyClientObject();
	}

	enum enSaveResults{ SaveFaildEmptyObject=0, svSucceeded =1, saveFaildAccountNumberExists = 2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::enEmptyMode:
			if (IsEmpty())
			{
				return enSaveResults::SaveFaildEmptyObject;
			}
			
			break;
		case enMode::enUpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
			break;
		case enMode::enAddedNewMode:

			if (clsBankClient::IsClientExist(_Account_Number))
			{
				return enSaveResults::saveFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::enUpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		default:
			break;
		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
		//return !Find(AccountNumber).IsEmpty();
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for  (clsBankClient &Client: _vClients)
		{
			if(Client.AccountNumber() == _Account_Number)
			{
				Client._MarkForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::enAddedNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		double TotalBalance = 0;
		vector <clsBankClient> vClients;
		vClients=_LoadClientsDataFromFile();
		for (clsBankClient& Client : vClients)
		{
			TotalBalance += Client.Account_Balance;
		}
		return TotalBalance;
	}

	void Deposit(double Amount)
	{
		_Account_Balance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _Account_Balance)
		{
			return false;
		}
		else
		{
			_Account_Balance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient ,string Username)
	{
		if (Amount > Account_Balance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, Username);
		return true;
	}
	
	static  vector <stTransferLog> GetLogTransferList()
	{
		vector <stTransferLog> vLogTransferRecord;

		fstream MyFile;
		MyFile.open(LogFileTransfer, ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTransferLog LogTransferRecord;

			while (getline(MyFile, Line))
			{

				LogTransferRecord = _ConvertLineOfTransferLogToRecord(Line);

				vLogTransferRecord.push_back(LogTransferRecord);

			}

			MyFile.close();

		}

		return vLogTransferRecord;
	}
	
};

