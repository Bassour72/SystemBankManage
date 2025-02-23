#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientListScreen :protected clsScreen
{

private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(15) << left << Client.First_Name;
        cout << "| " << setw(15) << left << Client.Last_Name;
        cout << "| " << setw(12) << left << Client.Phone_Number;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.Account_Balance;
    }

public:

    static void ShowClientsList()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }
        
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";
        system("cls");
        _DrawScreenHeader(Title, SubTitle);
        

        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "___________________________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(15) << "Client FName";
        cout << "| " << left << setw(15) << "Client LName";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance\t |";
        cout << "\n_______________________________________________________";
        cout << "___________________________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << "|";
                cout << endl;
                cout << "_______________________________________________________";
                cout << "__________________________________________________________\n" << endl;
            }

        
    }

};


