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


    while (true)
    {
        clsLang();

        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }

    }
    

    return 0;
}
















