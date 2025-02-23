#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransfersLogScreen.h"


using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:

    enum enTransactionsMenuOptions {
        enDeposit = 1, enWithdraw = 2,
        enShowTotalBalance = 3, enTransfer = 4 ,enShowTransfersLog =5,enShowMainMenu = 6
    };

    static short ReadTransactionsMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
       // cout << "\n Balances Screen will be here.\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        //cout << "\n The transfer screen will be here\n";
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransfersLogScreen()
    {
      //  cout << "\n Transfers Log Screen will be here...soon \n";
        clsTransfersLogScreen::ShowTransfersLogScreen();
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        system("pause>0");
        ShowTransactionsMenu();

    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
    {
        switch (TransactionsMenuOption)
        {
        case enTransactionsMenuOptions::enDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::enWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::enShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::enTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::enShowTransfersLog:
        {
            system("cls");
            _ShowTransfersLogScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::enShowMainMenu:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }



public:


    static void ShowTransactionsMenu()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");
      

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfers Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
       
        _PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
    }

};

