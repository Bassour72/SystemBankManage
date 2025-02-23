#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
private:
     static void _SetTheUserIsLonging()
    {
        cout << "\n\n\t\t\t\t\t User : " << CurrentUser.Username;

    }

    static void _ShowDateOnScreen()
    {
        clsDate Date1 = clsDate::GetSystemDate();
        cout << "\n\n\t\t\t\t\t Date : " << clsDate::DateToString(Date1) << endl;


    }

protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\tUser: " << CurrentUser.Username << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())
            << "\n\n";
    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

    

};
