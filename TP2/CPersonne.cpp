#include "CPersonne.hpp"

using namespace std;       
CPersonne::CPersonne(){
    nom = nullptr;
    prenom = nullptr;
    mail = nullptr;
    id = nullptr;
}

CPersonne::CPersonne(string nom ,string prenom ,string mail ,string id){
    this->nom = new string(nom);
    this->prenom = new string(prenom);
    this->mail = new string(mail);
    this->id = new string(id);
}

void CPersonne::setNom(string pnom){
    *(this->nom) = pnom;
    // (*this)->nom = pnom;
}

void CPersonne::setPrenom(string pprenom){
    *(this->prenom) = pprenom;
}

void CPersonne::setMail(string pmail){
    *(this->prenom) = pmail;
}

void CPersonne::setId(string pid){
    *(this->prenom) = pid;
}

string CPersonne::getNom() const{
    return *nom;
}

string CPersonne::getPrenom() const{
    return *prenom;
}

string CPersonne::getMail() const{
    return *mail;
}

string CPersonne::getId() const {
    return *id;
}
int main(){
    cout << "test";
}