#pragma once
#include <map>
#include <string>

using namespace std;

static map<string, string> FR = {

    // ================= GENERAL =================
    {"Login", "Connexion"},
    {"Logout", "Déconnexion"},
    {"Exit", "Quitter"},
    {"Welcome", "Bienvenue dans le système bancaire"},
    {"PressAnyKey", "Appuyez sur une touche pour revenir"},
    {"ChooseOption", "Choisissez une option"},
    {"InvalidInput", "Entrée invalide, veuillez réessayer"},
    {"EnterWord", "Entrez"},

    // ================= MAIN MENU =================
    {"MainMenu", "Menu principal"},
    {"ShowClients", "Afficher la liste des clients"},
    {"AddClient", "Ajouter un client"},
    {"DeleteClient", "Supprimer un client"},
    {"UpdateClient", "Mettre à jour le client"},
    {"FindClient", "Rechercher un client"},
    {"Transactions", "Transactions"},
    {"ManageUsers", "Gestion des utilisateurs"},
    {"LoginLogoutRegister","Journal de connexion et de déconnexion"},
    {"LoginLogoutRegisterScreen","Ecran du Journal de connexion et de déconnexion" },
    {"DateTime","Date & heure"},
    {"CurrencyExchange", "Change de devises"},

    // ================= CLIENT =================
    {"ClientListScreen", "Ecran de la liste des clients"},
    {"AddNewClientScreen", "Ecran de suppression du client"},
    {"DeleteClientScreen", "Delete Client Screen"},

    {"NoClients", "Aucun client disponible"},
    {"AccountNotFound","Numéro de compte introuvable, veuillez en choisir un autre "},
    {"ClientCard", "Fiche client"},
    {"ClientName", "Nom du client"},
    {"FirstName", "Prénom"},
    {"LastName", "Nom"},
    {"Email", "Email"},
    {"Phone", "Téléphone"},
    {"AccountNumber", "Numéro de compte"},
    {"PinCode", "Code PIN"},

    {"EnterNumClient", "Entrez le numéro de compte"},
    {"AccountExists", "Compte déjà existant, choisissez un autre"},
    {"AccountAdded", "Compte ajouté avec succès"},
    {"AccountDeleted", "Client supprimé avec succès"},
    {"AccountUpdated", "Compte mis à jour avec succès"},
    {"ClientNotFound", "Client introuvable"},
    {"ClientFound", "Client trouvé"},

   

    // ================= USERS =================
    {"UsersMenu", "Menu de gestion des utilisateurs"},
    {"GoBackManageMenue", "Appuyez sur une touche pour revenir au menu de gestion des utilisateurs"},
    {"ManageUsersScreen", "Écran de gestion des utilisateurs"},
    {"UserList", "Liste des utilisateurs"},
    {"User-s", "Utilisateur(s)"},
    {"NewUserScreen", "Ecran d'ajout d'un nouvel utilisateur"},
    {"DeleteUserScreen", "Ecran de suppression de l'utilisateur"},
    {"UpdateUserScreen","Écran de mise à jour de l'utilisateur"},
    {"NoUsers", "Aucun utilisateur disponible"},
    {"UserCard", "Fiche utilisateur"},
    {"UserName", "Nom d'utilisateur"},
    {"FullName", "Nom complet"},
    {"Password", "Mot de passe"},
    {"Permissions", "Permissions"},


    {"AddUser", "Ajouter un utilisateur"},
    {"DeleteUser", "Supprimer un utilisateur"},
    {"UpdateUser", "Mettre à jour un utilisateur"},
    {"UpdateUserInfo", "Mise à jour des informations de l'utilisateur"},
    {"FindUser", "Rechercher un utilisateur"},

    {"UserAdded", "Utilisateur ajouté avec succès"},
    {"UserDeleted", "Utilisateur supprimé avec succès"},
    {"UserUpdated", "Utilisateur mis à jour avec succès"},
    {"UserNotFound", "Utilisateur introuvable"},
    {"UserExists", "Nom d'utilisateur déjà utilisé"},


    {"AccessDenied", "Accès refusé ! Contactez votre administrateur."},

    {"ConfirmDeleteClient", "Êtes-vous sûr de vouloir supprimer ce client ?"},
    {"FindClientScreen", "Écran de recherche du client"},
    {"UpdateClientScreen", "Écran de mise à jour du client"},

    // ================= ADD USERS SCREEN =================
   {"FullAccessQST", "Voulez-vous accorder un accès complet ?"},
   {"AccessQST", "Voulez-vous accorder l'accès à : "},
   {"ShowList", "Afficher la liste des clients ?"},

    // ================= LOGIN =================
    {"LoginScreen", "Écran de connexion"},
    {"EnterUsername", "Entrez le nom d'utilisateur"},
    {"EnterPassword", "Entrez le mot de passe"},
    {"InvalidLogin", "Nom d'utilisateur ou mot de passe invalide"},
    {"LoginTrials", "Tentative(s) de connexion"},
    {"AccountLocked", "Compte bloqué après 3 tentatives échouées"},

    // ================= TRANSACTIONS =================
    {"TransactionsScreen", "Ecran des transactions"},
    {"TransactionMenu", "Menu des transactions"},
    {"Deposit", "Dépôt"},
    { "DepositScreen","ecran de dépôt" },
    {"Withdraw", "Retrait"},
    { "WithdrawScreen","Ecran de retrait" },
    {"Balance", "Solde du compte"},
    {"Transfer", "Transfert"},
    {"TransferLog","Journal des transferts" },
    {"TotalBalances", "Total des soldes"},
    { "TotalBalancesScreen","Ecran des soldes totaux" },
    {"EnterDepositAmount", "Entrez le montant du dépôt"},
    {"EnterWithdrawAmount", "Entrez le montant du retrait"},
    {"DepositSuccess", "Dépôt effectué avec succès"},
    {"WithdrawSuccess", "Retrait effectué avec succès"},
    {"InsufficientBalance", "Solde insuffisant"},
    {"NewBalance", "Nouveau solde"},
    {"YourBalance", "Votre solde"},

    { "BackToTransactionMenu","Appuyez sur une touche pour revenir au menu des transactions..." },

    // ================= TRANSFER =================
    {"TransferScreen", "Écran de transfert"},
    {"EnterFromAccount", "Entrez le compte source"},
    {"EnterToAccount", "Entrez le compte destination"},
    {"EnterAmount", "Entrez le montant"},
    {"SourceAccount","Compte source" },
    {"DestinationAccount","Compte destinataire" },
    {"Amount","Montant" },
    {"SourceBalance","Solde du compte source" },
    {"DestinationBalance","Solde du compte destinataire" }, 
    {"User","Utilisateur" },
    {"AmountToWithdraw","Le montant à retirer est" },
    {"AmountExceeds", "Le montant dépasse le solde disponible, entrez un autre montant"},
    {"ConfirmOperation", "Confirmez-vous l'opération ?"},
    {"OperationCancelled","L'opération a été annulée" },
    {"ConfirmTransaction","Etes-vous sûr de vouloir effectuer cette transaction ?" },
    {"TransferSuccess", "Transfert réussi"},
    {"TransferFailed", "Échec du transfert"},

    // ================= CURRENCY =================
    { "CurrenciesListScreen","Ecran de la liste des devises" },
    { "Currencies","Devise(s)" },
    {"CurrencyMenu", "Menu de change"},
    {"ListCurrencies", "Liste des devises"},
    {"FindCurrency", "Rechercher une devise"},
    {"UpdateRate", "Mettre à jour le taux"},
    {"CurrencyCalculator", "Calculateur de devises"},

    { "CurrencyCard","Carte de la devise" },
    {"CurrencyCode", "Code de devise"},
    {"CurrencyName", "Nom de la devise"},
    {"Country", "Pays"},
    {"Rate", "Taux"},

    { "FindCurrencyScreen","Ecran de recherche de devise" },
    { "FindBy","Rechercher par : [1] Code ou [2] Pays ?" },

    {"EnterCurrencyCode", "Entrez le code de devise"},
    { "EnterCurrency1Code","Veuillez entrer le code de la première devise" }, 
    { "EnterCurrency2Code","Veuillez entrer le code de la deuxième devise" },
    {"EnterCountry", "Entrez le pays"},
    {"CurrencyFound", "Devise trouvée"},
    {"CurrencyNotFound", "Devise introuvable"},

    { "UpdateCurrencyRateScreen","Ecran de mise à jour du taux de change" },

    {"EnterNewRate", "Entrez le nouveau taux"},
    {"RateUpdated", "Taux mis à jour avec succès"},
    { "ConfirmUpdateRate","Etes-vous sûr de vouloir mettre à jour le taux de cette devise ? y/n" },

    { "BackToCurrenciesMenu","Appuyez sur une touche pour revenir au menu des devises" },

    // ================= CALCULATOR =================
    {"CalculatorScreen", "Ecran du calculateur"},
    {"AnotherCalculation", "Voulez-vous refaire un calcul ?"},
    {"ConvertFrom", "Convertir de"},
    {"ConvertTo", "Convertir vers"},
    {"EnterAmountToExchange", "Entrez le montant"},

    // ================= EXTRA / MISSING =================
    { "UsernameUsed", "Nom d'utilisateur déjà utilisé" },
    { "UserAdded", "Utilisateur ajouté avec succès" },
    { "ErrorUserEmpty", "Utilisateur non enregistré car vide" },
    { "ErrorUserUsed", "Nom d'utilisateur déjà utilisé" },
    { "ConfirmUpdateUser", "Êtes-vous sûr de vouloir modifier cet utilisateur ?" },
    { "UserUpdated", "Utilisateur mis à jour avec succès" },
    { "ConfirmDeleteUser", "Êtes-vous sûr de vouloir supprimer cet utilisateur ?" },
    { "UserDeleted", "Utilisateur supprimé avec succès" },
    { "ErrorDeleteUser", "Erreur lors de la suppression de l'utilisateur" },
    { "UserFound", "Utilisateur trouvé" },
    { "UserNotFound", "Utilisateur introuvable" },

    // ================= Errors =================
    { "ErrorDeleteClient", "Error: client was not deleted" },
    { "ErrorEmptyClient","Erreur : le compte n'a pas été enregistré car il est vide" }, 
    { "ErrorAccountUsed","Erreur : le compte n'a pas été enregistré car le numéro de compte est déjà utilisé !" },
};