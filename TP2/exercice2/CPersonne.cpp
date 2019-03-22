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

CPersonne::CPersonne(const CPersonne& p){
    cout << "constructeur " << endl;
    this->id = new string(*(p.id));
    this->prenom = new string(*(p.prenom));
    this->nom = new string(*(p.nom));
    this->mail = new string(*(p.mail));
}

void CPersonne::setNom(string pnom){
    *(this->nom) = pnom;
    // (*this)->nom = pnom;
}

void CPersonne::setPrenom(string pprenom){
    *(this->prenom) = pprenom;
}

void CPersonne::setMail(string pmail){
    *(this->mail) = pmail;
}

void CPersonne::setId(string pid){
    *(this->id) = pid;
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

CPersonne::~CPersonne(){
    delete nom;
    delete prenom;
    delete mail;
    delete id;

}

bool CPersonne::operator==(const CPersonne p2){
    bool result = *this->nom == *p2.nom && *this->prenom == *p2.prenom && *this->mail == *p2.mail && *this->id == *p2.id;
    return result;

}
ostream& operator<<(ostream& out , CPersonne& p){
    return out << *(p.nom);
}

CPersonne& CPersonne::operator=(CPersonne& p){
    cout << "operator " << endl;
    if(this != &p){
        delete this->id;
        delete this->nom;
        delete this->prenom;
        delete this->mail;

        this->id = new string (*(p.id));
        this->nom = new string (*(p.nom));
        this->mail = new string (*(p.mail));
        this->prenom = new string (*(p.prenom));

    }
    return *(this);
}

int main(){
    // CPersonne *p = new CPersonne("jean" , "pierre" , "test@fez.fr" , "idze");
    // // cout << p << "\n";
    // // cout << p->getMail() << "\n";
    // // p->setMail("test2@ez.fr");
    // // cout << p->getMail() << "\n";
    // // delete p;
    // // p=nullptr;
    // // cout << p << "\n";
    // // cout << p->getMail() << "\n";

    // CPersonne *p2 = new CPersonne("jean" , "pierre" , "test@fez.fr" , "idze");
    // CPersonne *p3 = new CPersonne("jeann" , "pierre" , "test@fez.fr" , "idze");
    
    // bool test = (*p) == (*p2);
    // cout << test; // true (1)
    // test = (*p) == (*p3);
    // cout << test; //false (0)
    // cout << p3->getNom();
    // cout << *p3;

    CPersonne  p1 {"1","Trojahn","Cassia","cassia.trojahn@irit.fr"};
    CPersonne  p2 = p1;
    CPersonne  p3;
    p3 = p1;
    CPersonne p4;
    // p4 = CPersonne("2","Clemente","Gilles","gilles@cc.fr");
}

