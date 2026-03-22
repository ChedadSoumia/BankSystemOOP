#pragma once
#include <map>
#include <string>

using namespace std;

static map<string, string> EN = {

    // ================= GENERAL =================
    {"Login", "Login"},
    {"Logout", "Logout"},
    {"Exit", "Exit"},
    {"Welcome", "Welcome to the Bank System"},
    {"PressAnyKey", "Press any key to go back"},
    {"ChooseOption", "Choose what you want to do"},
    {"InvalidInput", "Invalid input, please try again"},
    {"EnterWord", "Enter"},

    // ================= MAIN MENU =================
    {"MainMenu", "Main Menu"},
    {"ShowClients", "Show Client List"},
    {"AddClient", "Add New Client"},
    {"DeleteClient", "Delete Client"},
    {"UpdateClient", "Update Client Info"},
    {"FindClient", "Find Client"},
    {"Transactions", "Transactions"},
    {"ManageUsers", "Manage Users"},
    {"LoginLogoutRegister","Login Logout Register"},
    {"LoginLogoutRegisterScreen","Login Logout Register Screen"},
    {"DateTime","Date & Time"},
    {"CurrencyExchange", "Currency Exchange"},

    // ================= CLIENT =================
    {"ClientListScreen", "Client List Screen"},
    {"AddNewClientScreen", "Add New Client Screen"},
    {"DeleteClientScreen","Delete Client Screen"},

    {"NoClients", "No Clients Available"},
    {"ClientCard", "Client Card"},
    {"ClientName", "Client Name"},
    {"FirstName", "First Name"},
    {"LastName", "Last Name"},
    {"Email", "Email"},
    {"Phone", "Phone"},
    {"AccountNumber", "Account Number"},
    { "PinCode", "Pin Code" },

    { "EnterNumClient", "Enter Account Number" },
    { "AccountExists", "Account already exists, choose another" },
    {"AccountNotFound","Account number is not found, choose another one "},
    { "AccountAdded", "Account added successfully" },
    { "AccountDeleted", "Client deleted successfully" },
    { "AccountUpdated", "Account updated successfully" },
    { "ClientNotFound", "Client not found" },
    {"ClientFound", "Client found"},

    {"ConfirmDeleteClient", "Are you sure you want to delete this client?"},
    
    {"FindClientScreen", "Find Client Screen"},
    {"UpdateClientScreen", "Update Client Screen"},

    // ================= USERS =================
    {"ManageUsersScreen", "Manage Users Screen"},
    {"GoBackManageMenue","Press any key to go back to Manage Users Menue"},
    { "UsersMenu", "Manage Users Menu" },
    { "UserList", "User List Screen" },
    { "NewUserScreen","Add New User Screen" },
    {"DeleteUserScreen", "Delete user screen"},
    {"UpdateUserScreen", "Update user screen"},
    {"FindUserScreen", "Find user screen"},
    {"User-s","User(s)"},
    { "NoUsers", "No Users Available" },
    { "UserCard", "User Card" },
    { "UserName", "Username" },
    { "FullName", "Full Name" },
    { "Password", "Password" },
    { "Permissions", "Permissions" },

    { "AddUser", "Add New User" },
    { "DeleteUser", "Delete User" },
    { "UpdateUser", "Update User" },
    {"UpdateUserInfo","Update User Info"},
    { "FindUser", "Find User" },

    { "UserAdded", "User added successfully" },
    { "UserDeleted", "User deleted successfully" },
    { "UserUpdated", "User updated successfully" },
    { "UserNotFound", "User not found" },
    { "UserExists", "Username already exists" },

    { "AccessDenied", "Access Denied! Contact your Admin." },

    // ================= ADD USER SCREEN =================
    { "FullAccessQST","Do you want to give full access?" },
    { "AccessQST","Do you want to give access to : " },
    { "ShowList","Show Client List?" },

    // ================= LOGIN =================
    { "LoginScreen", "Login Screen" },
    { "EnterUsername", "Enter Username" },
    { "EnterPassword", "Enter Password" },
    { "InvalidLogin", "Invalid Username/Password" },
    { "LoginTrials", "Trial(s) to login" },
    { "AccountLocked", "You are locked after 3 failed trials" },

    // ================= TRANSACTIONS =================
    {"TransactionsScreen", "Transactions Screen"},
    { "TransactionMenu", "Transaction Menu" },
    { "Deposit", "Deposit" },
    { "DepositScreen","Deposit Screen" },
    { "Withdraw", "Withdraw" },
    { "WithdrawScreen","Withdraw Screen" },
    { "Balance", "Account Balance" },
    { "Transfer", "Transfer" },
    {"TransferLog","Transfer Log" },
    { "TotalBalances", "Total Balances" },
    { "TotalBalancesScreen","Total Balances Screen" },
    { "EnterDepositAmount", "Enter deposit amount" },
    { "EnterWithdrawAmount", "Enter withdraw amount" },
    { "DepositSuccess", "Amount deposited successfully" },
    { "WithdrawSuccess", "Amount withdrawn successfully" },
    { "InsufficientBalance", "Insufficient balance" },
    { "NewBalance", "New balance is" },
    { "YourBalance", "Your balance is" },
    { "BackToTransactionMenu","Press any key to go back to Transaction Menu..." },
   
    // ================= TRANSFER =================
    {"TransferScreen", "Transfer Screen" },
    {"EnterFromAccount", "Enter source account number" },
    {"EnterToAccount", "Enter destination account number" },
    {"EnterAmount", "Enter amount" },
    {"SourceAccount","Source Account" },
    {"DestinationAccount","Destination Account" },
    {"Amount","Amount" },
    {"SourceBalance","Source Balance" }, 
    {"DestinationBalance","Destination Balance" }, 
    {"User","User" },
    {"AmountToWithdraw","Amount to withdraw is" },
    {"AmountExceeds", "Amount exceeds available balance,Enter another amount" },
    {"ConfirmOperation", "Are you sure you want to continue?" },
    {"OperationCancelled","Operation was cancelled." },
    {"ConfirmTransaction","Are you sure you want to perform this transaction?" },
    {"TransferSuccess", "Transfer completed successfully" },
    {"TransferFailed", "Transfer failed" },

    // ================= CURRENCY =================
    { "CurrenciesListScreen","Currencies List Screen" },
    { "Currencies","Currency(s)" },
    { "CurrencyMenu", "Currency Exchange Menu" },
    { "ListCurrencies", "List Currencies" },
    { "FindCurrency", "Find Currency" },
    { "UpdateRate", "Update Rate" },
    { "CurrencyCalculator", "Currency Calculator" },

    { "CurrencyCard","Currency Card" },
    { "CurrencyCode", "Currency Code" },
    { "CurrencyName", "Currency Name" },
    { "Country", "Country" },
    { "Rate", "Rate" },

    { "FindCurrencyScreen","Find Currency Screen" },
    { "FindBy","Find by: [1] Code or [2] Country?" },

    { "UpdateCurrencyRateScreen","Update Currency Rate Screen" },

    { "EnterCurrencyCode", "Enter currency code" },
    { "EnterCurrency1Code","Please enter Currency1 code" }, 
    { "EnterCurrency2Code","Please enter Currency2 code" },
    { "EnterCountry", "Enter country name" },
    { "CurrencyFound", "Currency found" },
    { "CurrencyNotFound", "Currency not found" },

    { "EnterNewRate", "Enter new rate" },
    { "RateUpdated", "Rate updated successfully" },
    { "ConfirmUpdateRate","Are you sure you want to update the rate of this Currency y/n?" },
    { "BackToCurrenciesMenu","Press any key to go back to Currencies Menu" },

    // ================= CALCULATOR =================
    { "CalculatorScreen", "Currency Calculator Screen" },
    { "AnotherCalculation", "Do you want another calculation?" },
    { "ConvertFrom", "Convert from" },
    { "ConvertTo", "Convert to" },
    { "EnterAmountToExchange", "Enter amount to exchange" },

    // 
    { "UsernameUsed", "Username already exists" },
    { "UserAdded", "User added successfully" },
    { "ErrorUserEmpty", "User was not saved because it is empty" },
    { "ErrorUserUsed", "User was not saved because username is already used" },
    { "ConfirmUpdateUser", "Are you sure you want to update this user?" },
    { "UserUpdated", "User updated successfully" },
    { "ConfirmDeleteUser", "Are you sure you want to delete this user?" },
    { "UserDeleted", "User deleted successfully" },
    { "ErrorDeleteUser", "Error: user was not deleted" },
    { "UserFound", "User found" },
    { "UserNotFound", "User not found" },

    // ================= Errors =================
    {"ErrorDeleteClient", "Error: client was not deleted" },
    {"ErrorEmptyClient","Error account was not saved because it's Empty" },
    {"ErrorAccountUsed","Error account was not saved because account number is used!" },




};