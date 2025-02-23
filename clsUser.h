#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "MyOwnLibraryString.h"
#include "clsPerson.h"
#include "clsDate.h"
#include "clsUtility.h"


using namespace std;

const string string_File_Info_Of_User = "UserFile.txt";
const string LogFileRegister = "LoginRegister.txt";

class clsUser:public clsPerson
{
private:

	enum enMode { enEmptyMode = 0, enUpdateMode = 1, enAddedNewMode = 2 };
	enMode _Mode;
	string _Username;
	string _Password;
	int _Permissions = 0;
	bool _MarkedForDelete = false;
    string _Time_And_Date;

    string _PrepareLogInRecord(string Separator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Separator;
        LoginRecord += Username + Separator;
        LoginRecord += Password + Separator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }

    struct stLoginRegisterRecord;

    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Separator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;


        vector <string> LoginRegisterDataLine = MyOwnLibraryString::Split(Line, Separator);
        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = LoginRegisterDataLine[2];
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

        return LoginRegisterRecord;

    }

    static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector<string> vUserData;
        vUserData = MyOwnLibraryString::Split(Line, Separator);

        return clsUser(enMode::enUpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtility::Decryption(vUserData[5]), stoi(vUserData[6]));
            
       // 
    }

    static string _ConvertUserObjectToLine(clsUser User, string Separator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.First_Name + Separator;
        UserRecord += User.Last_Name + Separator;
        UserRecord += User.Email + Separator;
        UserRecord += User.Phone_Number + Separator;
        UserRecord += User.Username + Separator;
       // UserRecord += User.Password + Separator;
        UserRecord += clsUtility::Encryption(User.Password) + Separator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open(string_File_Info_Of_User, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLineToUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open(string_File_Info_Of_User, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConvertUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.Username == Username)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(string_File_Info_Of_User, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::enEmptyMode, "", "", "", "", "", "", 0);
    }

public:

    enum enPermissions
    {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pLoginRegister = 128, pCurrencyExchange = 256
    };

    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions=0;

    };

	clsUser(enMode Mode,string FirstName, string LastName,string Email,
			string PhoneNumber,string Username,string Password,int Permissions, string Time_And_Date="")
			:clsPerson(FirstName, LastName, Email, PhoneNumber)
	{	
		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}
	
     bool MarkedForDeleted()
     {
         return _MarkedForDelete;
     }

    string GetUsername()
    {
        return _Username;
    }

    void SetUsername(string UserName)
    {
        _Username = UserName;
    }

    __declspec(property(get = GetUsername, put = SetUsername)) string Username;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    void SetTime_And_Date(string Time_And_Date)
    {
        _Time_And_Date = Time_And_Date;
    }

    string GetTime_And_Date()
    {
        return _Time_And_Date;
    }

    __declspec(property(get = GetTime_And_Date, put = SetTime_And_Date)) string Time_And_Date;


    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open(string_File_Info_Of_User, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.Username == UserName)
                {
                    
                    MyFile.close();
                    return User;
                   
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("UserFile.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.Username == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { saveFaildEmptyObject = 0, saveSucceeded = 1, saveFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::enEmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::saveFaildEmptyObject;
            }
        }

        case enMode::enUpdateMode:
        {
            _Update();
            return enSaveResults::saveSucceeded;

            break;
        }

        case enMode::enAddedNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_Username))
            {
                return enSaveResults::saveFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::enUpdateMode;
                return enSaveResults::saveSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.Username == _Username)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::enAddedNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;

    }

    void RegisterLogIn()
    {

        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open(LogFileRegister, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static  vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open(LogFileRegister, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {

                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);

            }

            MyFile.close();

        }

        return vLoginRegisterRecord;
    }

     void Print()
    {
        cout << "\nUsername : " << Username;
        cout << "\n Password : " << this->Password;

    }
};

