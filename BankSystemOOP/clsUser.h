#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsUser : public clsPerson
{
private:
    struct stLoginLogout;

    enum enMode{ EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName , _Password;
    int _Permissions;
    bool _MarkedForDelete = false;

    

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5],2), stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += clsUtil::EncryptText(User.Password,2) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }


    string _MakeLoginLogoutLine(string Action, string Seperator = "#//#" )
    {

        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += this->UserName + Seperator;
        LoginRecord += clsUtil::EncryptText(this->Password) + Seperator;
        LoginRecord += to_string(this->Permissions) + Seperator;
        LoginRecord += Action;

        return LoginRecord;

    }

    static stLoginLogout _ConvertLinetoLoginStruct(string DataLine, string Seperator = "#//#") {
        stLoginLogout act;

        vector<string> vLogsData = clsString::Split(DataLine, Seperator);
        
        act.Date = vLogsData[0];
        act.username = vLogsData[1];
        act.password = clsUtil::DecryptText(vLogsData[2]);
        act.permission = stoi(vLogsData[3]);
        act.action = vLogsData[4];
        
        return act;
    }
    static vector<stLoginLogout> _LoadRegisterDataFromFileToStruct() {
        vector<stLoginLogout> vLoginLogout;

        fstream MyFile;
        MyFile.open("LoginHistory.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;
            stLoginLogout Action;

            while (getline(MyFile, Line))
            {

                Action = _ConvertLinetoLoginStruct(Line);

                vLoginLogout.push_back(Action);
            }

            MyFile.close();
        }
        return vLoginLogout;
    }
    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }




public:
    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pRegisterScreen = 128
    };

    struct stLoginLogout {
        string Date;
        string username;
        string password;
        int permission;
        string action;
    };


    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName() {
        return _UserName;
    }
    void SetUserName(string Username) {
        _UserName = Username;
    }
    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    string Getpassword() {
        return _Password;
    }
    void SetPassword(string password) {
        _Password = password;
    }
    __declspec(property(get = Getpassword, put = SetPassword)) string Password;

    int GetPermissions() {
        return _Permissions;
    }
    void SetPermissions(int Permissions) {
        _Permissions = Permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }


    bool CheckAccessPermission(enPermissions Permission) {

        if (this->Permissions == enPermissions::eAll)
            return true;
        
        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;


    }


    void SaveLoginLog(string Action) {
        string DataLine = _MakeLoginLogoutLine(Action);

        fstream MyFile;
        MyFile.open("LoginHistory.txt", ios::out | ios::app);



        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();

        }
    }

    static vector<stLoginLogout> GetLoginLogoutRegisterList() {
        return _LoadRegisterDataFromFileToStruct();
    }


};

