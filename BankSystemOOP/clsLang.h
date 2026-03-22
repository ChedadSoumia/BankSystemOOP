#pragma once
#include <map>
#include <iostream>
#include "clsEngWords.h"
#include "clsFrWords.h"

using namespace std;
static enum enLang { enEN = 1, enFR = 2 };
static enLang LangChosen;

class clsLang
{
private:

    static enLang _ReadLang() {

        cout << "The language? EN/FR - ";
        string TheGlobalLang = clsInputValidate::ReadString();

        if (clsString::LowerAllString(TheGlobalLang) == "fr") 
            return enLang::enFR;
        else
            return enLang::enEN;
    
    }
    
public:
    clsLang(){
        LangChosen = _ReadLang();
    }

    static string ToLang(const string& key) {
        if (LangChosen == enLang::enEN)
            
            return EN.at(key);

        if (LangChosen == enLang::enFR)
            return FR.at(key);

        return "Text not found";;
}
};

