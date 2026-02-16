#pragma once
#include <map>
#include <iostream>

using namespace std;
static enum enLang { enEN = 1, enFR = 2 };
static enLang LangChosen;

static map<string, string> EN = {
    {"login", "Login"},
    {"MainMenue", "Main Munue"},
    {"ChooseOption", "Choose what do you want to do? [1 to 8]"},
    {"PressAnyKey", "Press any key to go back to"},
    {"MainMenu","Main Menu"},
    {"ShowClients", "Show Client List"},
    {"NoClients","No Clients Available In the System"},
    {"ClientListScreen", "Client List Screen"},
    {"AddNewClientScreen", "Add New Client Screen"},
    {"EnterNumClient", "Please Enter client Account Number"},
    {"ChooseAnother","Account Number Is Already Used, Choose another one"},
    {"AccountAddSuccess","Account Added Successfully"},
    {"ErrorEmpty","Error account was not saved because it's Empty"},
    {"ErrorAccountUsed","Error account was not saved because account number is used!"},
    {"ClientCard","Client Card"},
    {"ClientName", "Client Name"},
    {"EnterWord", "Enter"},
    {"FirstName", "Firstname"},
    {"LastName", "Last Name"},
    {"Email", "Email"},
    {"Phone", "Phone"},
    {"AccountNumber", "Account Number"},
    {"PinCode", "Pin Code"},
    {"AddClient", "Add New Client"},
    {"DeleteClient", "Delete Client"},
    {"DLTclientScreen","Delete Client Screen"},
    {"AreDLTCl","Are you sure you want to delete this client"},
    {"DLTSucc","Client Deleted Successfully"},
    {"ErrorDLT","Error Client Was not Deleted"},
    {"UpdateClient", "Update Client Info"},
    {"UpdateClientScreen","Update Client Screen"},
    {"UpdatedAccountClient","Account Updated Successfully"},
    {"FindClient", "Find Client"},
    {"FINDCSc","Find Client Screen"},
    {"ClientNotFound","Account number is not found, choose another one "},
    {"ClintFound","Client found"},
    {"Transactions", "Transactions"},
    {"ManageUsers", "Manage Users"},
    {"UsersSCR","Manage Users screen"},
    {"Choose16","Choose what do you want to do? [1 to 6]?"},
    {"Enter16","Enter Number between 1 to 6? "},
    {"GoBackManageMenue","Press any key to go back to Manage Users Menue"},
    {"ManageUSersMenue","Manage Users Menu"},
    {"ListUsers","List Users"},
    {"NewUser","Add New User"},
    {"DLTUser","Delete User"},
    {"UPUser","Update User"},
    {"FIndUser","Find User"},
    {"UsersMenue","Manage Users Menue"},
    {"MainMenue","Main Menue"},











    {"Logout", "Logout"},
    {"withdraw", "Withdraw Money"},
    {"deposit", "Deposit Money"},
    {"balance", "Account Balance"},
    {"exit", "Exit"},
    {"welcome", "Welcome to the Bank System"},
};

static map<string, string> FR = {
    {"login", "Connexion"},
    {"ChooseOption", "Veuillez choisir une option [1 à 8] :"},
    {"PressAnyKey", "Appuyez sur une touche pour revenir au "},
    {"MainMenu","Main menu principal"},
    {"ShowClients", "Afficher la liste des clients"},
    {"NoClients","Il n’y a aucun client enregistré dans le système"},
    {"ClientListScreen", "Liste des clients"},
    {"AddNewClientScreen", "Ecran de creation d'un client"},
    {"EnterNumClient", "Entrez le numero de compte du client"},
    {"ChooseAnother","Le numéro de compte est déjà utilisé, veuillez en choisir un autre"},
    {"AccountAddSuccess","Compte ajouté avec succès"},
    {"ErrorEmpty","Erreur : le compte n’a pas été enregistré car il est vide"},
    {"ErrorAccountUsed","Erreur : le compte n'a pas été enregistré car le numéro de compte est déjà utilisé !"},
    {"ClientCard","Fiche client"},
    {"ClientName", "Nom du client"},
    {"EnterWord", "Entrez"},
    {"FirstName", "le prénom"},
    {"LastName", "Nom de famille"},
    {"Email", "Email"},
    {"Phone", "Téléphone"},
    {"AccountNumber", "Numéro de compte"},
    {"PinCode", "Code PIN"},
    {"Balance", "Solde"},
    {"AddClient", "Ajouter un nouveau client"},
    {"DeleteClient", "Supprimer un client"},
    {"DLTclientScreen","Écran de suppression du client"},
    {"AreDLTCl","Êtes-vous sûr de vouloir supprimer ce client"},
    {"DLTSucc","Client supprimé avec succès"},
    {"ErrorDLT","Erreur : le client n’a pas été supprimé"},
    {"UpdateClient", "Mettre à jour les informations du client"},
    {"UpdateClientScreen", "Écran de mise à jour du client"},
    {"UpdatedAccountClient", "Compte mis à jour avec succès"},
    {"FindClient", "Rechercher un client"},
    {"FINDCSc","Écran de recherche du client"},
    {"ClientNotFound","Numéro de compte introuvable, veuillez en choisir un autre "},
    {"ClintFound","Client trouvé"},
    {"Transactions", "Transactions"},
    {"ManageUsers", "Gestion des utilisateurs"},
    {"UsersSCR","Écran de gestion des utilisateurs"},
    {"Choose16","Choisissez ce que vous voulez faire ? [1 à 6]"},
    {"Enter16","Entrez un numéro entre 1 et 6 "},
    {"GoBackManageMenue", "Appuyez sur une touche pour revenir au menu de gestion des utilisateurs"},
    {"ManageUSersMenue", "Menu de gestion des utilisateurs"},
    {"ListUsers", "Lister les utilisateurs"},
    {"NewUser", "Ajouter un nouvel utilisateur"},
    {"DLTUser", "Supprimer un utilisateur"},
    {"UPUser", "Mettre à jour un utilisateur"},
    {"FIndUser", "Rechercher un utilisateur"},
    {"UsersMenue", "Menu de gestion des utilisateurs"},
    {"MainMenue", "Menu principal"},
    {"Logout", "Déconnexion"},
    {"MainMenue", "Menu Principal"},
    {"withdraw", "Retirer de l'argent"},
    {"deposit", "Deposer de l'argent"},
    {"balance", "Solde du compte"},
    {"exit", "Quitter"},
    {"welcome", "Bienvenue dans le système bancaire"},
};

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

