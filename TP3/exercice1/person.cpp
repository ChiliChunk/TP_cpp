#include "person.h"

using namespace std;

/* Constructeur par defaut */
CPersonne::CPersonne() {
         this->prenom = nullptr;
         this->nom    = nullptr;
         this->mail   = nullptr;
         this->id     = nullptr;
}

CPersonne::CPersonne(string id,string nom,string prenom,string mail) {
           this->id = new string;
           *(this->id) = id;
            
           this->nom = new string;
           (*this->nom) = nom;

           this->prenom = new string;
           *(this->prenom) = prenom;

           this->mail = new string;
           *(this->mail) = mail;  
}

/* Constructeur de copie */ 
CPersonne::CPersonne(const CPersonne& p) {
        //cout << "Constructeur par copie. " << endl;
        this->id = new string;
        *(this->id) = *(p.id);
            
        this->nom = new string;
        *(this->nom) = *(p.nom);

        this->prenom = new string;
        *(this->prenom) = *(p.prenom);

        this->mail = new string;
        *(this->mail) = *(p.mail);   
}

/* Affectation par copie */
CPersonne& CPersonne::operator=(const CPersonne& p) {
     //cout << "Affectation par copie. " << endl;
     if (this != &p) { // protection contre l'auto-affectation (t1=t1)

         delete this->id;
         delete this->nom;
         delete this->prenom;
         delete this->mail;

         this->id = new string;
         this->nom = new string;
         this->prenom = new string;
         this->mail = new string;

         *(this->prenom) = *(p.prenom);
         *(this->nom) = *(p.nom);
         *(this->mail) = *(p.mail);
         *(this->id) = *(p.id);
     }
     return (*this); 
}

/* Constructeur par move */
CPersonne::CPersonne(CPersonne&& p) {
          //cout << "Constructeur par move. " << endl;
          this->prenom = p.prenom;
          this->nom = p.nom;
          this->mail = p.mail;
          this->id = p.id;

          p.prenom = nullptr;
          p.nom    = nullptr;
          p.mail   = nullptr;
          p.id     = nullptr; 
}

/* affectation par 'move' */
CPersonne& CPersonne::operator=(CPersonne&& p) {
            //cout << "Affectation par move. " << endl; 
            // il faut les supprimer par ce que'on est pas sur que le constructor par default a ete appele

            delete (this->prenom);
            delete (this->nom);
            delete (this->mail);
            delete (this->id);

            this->prenom = p.prenom;
            this->nom = p.nom;
            this->mail = p.mail;
            this->id = p.id;
            p.prenom = nullptr;
            p.nom    = nullptr;
            p.mail   = nullptr;
            p.id     = nullptr;
            return (*this);  
} 

string CPersonne::get_id() const {
    return *(this->id); 
} 

string CPersonne::get_nom() const {
    return *(this->nom); 
} 

string CPersonne::get_prenom() const {
    return *(this->prenom); 
} 

string CPersonne::get_mail() const {
    return *(this->mail); 
} 

void CPersonne::set_id(string id) {
     *(this->id) = id; 
} 

void CPersonne::set_nom(string nom) {
     *(this->nom) = nom; 
} 

void CPersonne::set_prenom(string prenom) {
     *(this->prenom) = prenom; 
} 

void CPersonne::set_mail(string mail) {
     *(this->mail) = mail; 
}
 
void CPersonne::affiche() {
     cout << "CPersonne : " << *this << endl; 
}

/* Destructeur */
CPersonne::~CPersonne() {
         delete (this->prenom);
         delete (this->nom);
         delete (this->mail);
         delete (this->id);
}

/* Operateur friend */
bool operator<(CPersonne a,CPersonne b) {
     if (*(a.nom) < *(b.nom))
         return true;
     else
         return false;  
}

/* Operateur friend */
bool operator>(CPersonne a,CPersonne b) {
     if (*(a.nom) > *(b.nom))
         return true;
     else
         return false;  
}


/* Operateur friend */
bool operator==(CPersonne a,CPersonne b) {
     if (*(a.id) == *(b.id))
         return true;
     else
         return false;  
}

/* Operateur friend */
ostream& operator<<(ostream& out,CPersonne a) {
       return out << *(a.id) << " " << *(a.nom) << " " << *(a.prenom) <<  " " << *(a.mail); 
}

