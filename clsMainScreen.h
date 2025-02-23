#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyMainScreen.h"

class clsMainScreen:protected clsScreen
{

private:

    enum enMainMenueOptions {
        enListClients = 1, enAddNewClient = 2, enDeleteClient = 3,
        enUpdateClient = 4, enFindClient = 5, enShowTransactionsMenue= 6,
        enManageUsers = 7, enLoginRegister=8, enCurrencyExchange=9, enExit = 10
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
       // cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
      //  cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
       // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        //cout << "\nTransactions Menu Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenu()
    {
       // cout << "\nUsers Menu Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenu();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyMainScreen::ShowMainScreenCurrency();
    }

    static void _ShowAllLoginRegisterScreen()
    {
      //  cout << "\n Login Register Screen Will be here...\n";
        clsLoginRegisterScreen::ShowLoginRegisterScreen();

    }

    static void _Logout()
    {
        //cout << "\n logout Will be here...\n";

        CurrentUser = clsUser::Find("", "");
       

    }

    static void _PerformMainMenuOption(enMainMenueOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
            case enMainMenueOptions::enListClients:
            {
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::enAddNewClient:
            {
                system("cls");
                _ShowAddNewClientsScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::enDeleteClient:
            {
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::enUpdateClient:
            {
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::enFindClient:
            {
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::enShowTransactionsMenue:
            {
                system("cls");
                _ShowTransactionsMenu();
                _GoBackToMainMenu();
                break;

            }

            case enMainMenueOptions::enManageUsers:
            {
                system("cls");
                _ShowManageUsersMenu();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::enLoginRegister:
            {
                system("cls");
                _ShowAllLoginRegisterScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::enCurrencyExchange:
            {
                system("cls");
               _ShowCurrencyExchangeScreen();
                _GoBackToMainMenu();
                break;
            }

            case enMainMenueOptions::enExit:
            {
                system("cls");
                _Logout();
                //_ShowEndScreen();
                break;
            }
        }

    }



public:


    static void ShowMainMenu()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency  Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenueOptions)_ReadMainMenuOption());
    }

};

