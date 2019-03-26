#include "deriv.h"

using namespace std;

// Developpeur ---------------------------------------------------------------------------------------------------------------
CDeveloppeur::CDeveloppeur() {
}

CDeveloppeur::CDeveloppeur(string id, string nom, string prenom, string mail, string projet, short niveau) : CPersonne(id,nom,prenom,mail) {
    this->projet_en_cours = projet;
    this->niveau = niveau;
}

string CDeveloppeur::get_projet() const {
       return this->projet_en_cours; 
}

short CDeveloppeur::get_niveau() const {
      return this->niveau;
}

void CDeveloppeur::set_projet(string projet) {
     this->projet_en_cours = projet;
}

void CDeveloppeur::set_niveau(short niveau) {
     this->niveau = niveau;
}

CDeveloppeur::~CDeveloppeur() {
    // ATTENTION : destructeur super classe appelé
}

CManager::CManager(string id, string nom, string prenom, string mail, vector<CPersonne*> developpeurs) : CPersonne(id,nom,prenom,mail) {
    this->list_developpeurs = developpeurs;
}

void CDeveloppeur::affiche() {
      CPersonne::affiche();
      cout << "Developpeur : " << (this->projet_en_cours) << " " << (this->niveau) << endl; // or surcharger << for this classe
      cout << endl;
}

// Manager ---------------------------------------------------------------------------------------------------------------
CManager::CManager() {
       // pas de ressource à allouer
}

vector<CPersonne*> CManager::get_developpeurs() const {
                 return this-> list_developpeurs; 
}

void CManager::set_developpeurs(vector<CPersonne*> developpeurs) {
     this-> list_developpeurs = developpeurs; 
}
 
void CManager::affiche() {
      CPersonne::affiche();
      cout << "Manager : List de developpeurs " << endl; 
      for (int i=0;i<this->list_developpeurs.size();i++) 
           list_developpeurs.at(i)->affiche();
      cout << endl;
}

CManager::~CManager() {
     // ATTENTION : destructeur super classe appelé
     
     /* Pour eviter toute fuite memoire !!! 
        => MAIS ATTENTION => supprimer un manager ne implique pas forcement supprimer ces develps 
        => Develops deja supprimes dans le cadre de la liste, mais delete nullptr sans effet !
     */
     for (int i = 0; i <= list_developpeurs.size(); i++) {
          delete list_developpeurs.at(i);
          list_developpeurs.at(i) = nullptr;    
     }  
}
