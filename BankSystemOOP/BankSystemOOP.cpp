#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsLang.h"
#include "clsLoginScreen.h"




int main()
{

    SetConsoleCtrlHandler(ConsoleHandler, TRUE);

    setlocale(LC_ALL, "");
    string TheGlobalLang ;

    cout << "The language? EN/FR - ";
    //clsMainScreen::ShowMainMenue();
    cin >> TheGlobalLang;
    if (clsString::LowerAllString(TheGlobalLang) == "en") {
        LangChosen = enLang::enEN;
    }
    else {
        LangChosen = enLang::enFR;
    }


    
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }

    }
    

    return 0;
}
















