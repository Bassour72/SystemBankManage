#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
private:

	string _First_Name;
	string _Last_Name;
	string _Email;
	string _Phone_Number;

public:

	clsPerson(string First_name, string Last_Name, string Email ,string Phone_Number)
	{
		 _First_Name = First_name;
		 _Last_Name = Last_Name;
		 _Email =Email;
		 _Phone_Number = Phone_Number;
	}

	void SetFirstName(string  First_name)
	{
		_First_Name = First_name;
	}

	string GetFirstName()
	{
		return _First_Name;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string First_Name;

	void SetLastName(string  Last_Name)
	{
		_Last_Name = Last_Name;
	}

	string GetLastName()
	{
		return _Last_Name;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string Last_Name;

	void SetPhoneNumber(string  Phone_Number)
	{
		_Phone_Number = Phone_Number;
	}

	string GetPhoneNumber()
	{
		return _Phone_Number;
	}

	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string Phone_Number;

	void SetEmail(string  Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	string FullName()
	{
		return _First_Name + " " + _Last_Name;
	}

	
};

