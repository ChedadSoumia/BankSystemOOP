#pragma once
#include <iostream>
#include "clsUser.h"
#include <windows.h>


clsUser CurrentUser = clsUser::Find("", "");


BOOL WINAPI ConsoleHandler(DWORD signal)
{
    if (signal == CTRL_CLOSE_EVENT) 
    {
        if(!CurrentUser.IsEmpty()){
            CurrentUser.SaveLoginLog("Logout");
        }
        Sleep(2000); 
        return TRUE;
    }
    return FALSE;
}

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}