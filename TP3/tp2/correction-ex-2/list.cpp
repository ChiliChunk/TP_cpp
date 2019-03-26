#include "list.h"

using namespace std;

CNoeud::CNoeud() {
       this->pers = nullptr;
       this->pred = nullptr;
       this->suiv = nullptr; 
}

CNoeud::CNoeud(CPersonne* pers, CNoeud* pred, CNoeud* suiv) {
       this->pers = pers;
       this->pred = pred;
       this->suiv = suiv; 
}

CNoeud* CNoeud::get_pred() const {
        return this->pred;
}

CNoeud* CNoeud::get_suiv() const {
        return this->suiv;
}

CPersonne* CNoeud::get_pers() const {
        return this->pers;
}

CNoeud::~CNoeud() {
        delete this->pers;
}

CListe::CListe() {
       this->tete = nullptr;
       this->queue = nullptr;
}

CListe::CListe(CNoeud* tete, CNoeud* queue) {
       this->tete = tete;
       this->queue = queue;
}

bool CListe::ajoute(CPersonne* p) {
          CNoeud* n = new CNoeud (p,nullptr,nullptr);
          // first element
          if (this->tete == nullptr) {
              this->tete = n;
              this->queue = n;
          } else {
            // ajoute noued à la fin de la liste 
            if (recherche((n->pers->get_id())) != nullptr) {
                return false;
            }
            else {
                this->queue->suiv = n;
                n->pred = this->queue; 
                this->queue = n;
            } 
           }
           return true; 
}

CPersonne* CListe::recherche(string id) const {
      if (vide()) {
         cout << "Liste vide !" << endl;
      } else {
         CNoeud* n = this->tete;   
         while (n != nullptr) {    
                if (id == (n->pers->get_id())) 
                   return n->pers;
                else  
                   n = n->suiv; 
         }
     } 
     return nullptr;
}

CPersonne* CListe::supprime(string id) {
       if (vide()) {
          cout << "Liste vide !" << endl;
       } else {
             CNoeud* n = (this->tete);
             // delete the first node of the list 
             if ((n->pers->get_id()) == id) {
                 this->tete=n->suiv;
                 return n->pers; // ATTENTION : il faut supprimer n->pers quelque part sinon fuite memoire
            } else {
                // TODO ;-)
         }
     }
     return nullptr; 
}

bool CListe::vide() const {
     return (this->tete == nullptr && this->queue == nullptr); 
}

void CListe::affiche() const {
     if (vide()) {
         cout << "Liste vide !" << endl;
     } else {
         CNoeud* n = this->tete;
         while (n != nullptr) {    
                //cout << *(n->pers); // => pour exercice 2
                n->pers->affiche(); // => pour exercice 3
                n = n->suiv; 
         }
     }
     cout << endl;
}

CNoeud* CListe::get_tete() const {
       this->tete;
}

CNoeud* CListe::get_queue() const {
       this->queue;
}

CListe::~CListe() {
         // nettoyage des elements de la liste
         CNoeud* temp = this->tete;
         CNoeud* suiv;
         while (temp != nullptr) {
               suiv = temp->suiv; 
               delete temp; // personne est supprime dans le destructeur de CNoued
               temp = suiv;  
         } 
         this->tete = nullptr;
}


