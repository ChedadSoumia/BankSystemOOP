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
    
public:
    static string ToLang(const string& key, enLang lang) {
        if (lang == enLang::enEN)
            
            return EN.at(key);

        if (lang == enLang::enFR)
            return FR.at(key);

        return "Text not found";;
}
};

