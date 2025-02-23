#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsUtility.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFailed = false;
        short CountFailedLogin = 3;

        string Username, Password;
        do
        {
           
            if (LoginFailed)
            {
                cout << "\n\nInvalid Username/Password!\n";
                cout << "You have " << CountFailedLogin << " trials to login \n\n";
            }
            if (CountFailedLogin == 0)
            {
                cout << "\n You are locked after three failed trials :-(\n";
                return false;
            }
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;
            CountFailedLogin--;

            CurrentUser = clsUser::Find(Username , Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenu();
        return true;
    }

    void _Log()
    {

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        
        return _Login();
        
       

    }

};

