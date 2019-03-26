#ifndef LIST_H
#define LIST_H
#include "person.h"

template <class T> class CListe;

template <class T> class CNoeud {
      friend class CListe<T>; 
      private : 
        T* contenu;
        CNoeud<T>* pred;
        CNoeud<T>* suiv;
      public :
        CNoeud(); 
        CNoeud(T*,CNoeud*,CNoeud*);
        T* get_pers() const;
        CNoeud* get_pred() const;
        CNoeud* get_suiv() const;
        ~CNoeud();
};

template  <class T> class CListe {
       friend class CNoeud<T>; 
       CNoeud<T>* tete;
       CNoeud<T>* queue;
       public : 
         CListe();
         CListe(CNoeud<T>*,CNoeud<T>*);
         bool ajoute(T*);
         T* recherche(T) const;
         T* supprime(std::string);
         bool vide() const; 
         CNoeud<T>* get_tete() const;
         CNoeud<T>* get_queue() const;
         void affiche() const;
         ~CListe();         
};

template <class T> CNoeud<T>::CNoeud() {
       this->contenu = nullptr;
       this->pred = nullptr;
       this->suiv = nullptr; 
}

template <class T> CNoeud<T>::CNoeud(T* pers, CNoeud<T>* pred, CNoeud<T>* suiv) {
       this->contenu = contenu;
       this->pred = pred;
       this->suiv = suiv; 
}

template <class T> CNoeud<T>* CNoeud<T>::get_pred() const {
        return this->pred;
}

template <class T> CNoeud<T>* CNoeud<T>::get_suiv() const {
        return this->suiv;
}

template <class T> T* CNoeud<T>::get_pers() const {
        return this->contenu;
}

template <class T> CNoeud<T>::~CNoeud() {
        delete this->contenu;
}

template <class T> CListe<T>::CListe() {
       this->tete = nullptr;
       this->queue = nullptr;
}

template <class T> CListe<T>::CListe(CNoeud<T>* tete, CNoeud<T>* queue) {
       this->tete = tete;
       this->queue = queue;
}

template <class T>  bool CListe<T>::ajoute(T* p) {
          CNoeud<T>* n = new CNoeud<T> (p,nullptr,nullptr);
          // first element
          if (this->tete == nullptr) {
              this->tete = n;
              this->queue = n;
          } else {
            // ajoute noued à la fin de la liste 
            if (recherche((n->contenu)) != nullptr) {
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

template <class T> T* CListe<T>::recherche(T elemnt) const {
      if (vide()) {
         std::cout << "Liste vide !" << std::endl;
      } else {
         CNoeud<T>* n = this->tete;   
         while (n != nullptr) {    
                if (elemnt == (n->contenu)) 
                   return n->contenu;
                else  
                   n = n->suiv; 
         }
     } 
     return nullptr;
}

template <class T> T* CListe<T>::supprime(std::string id) {
       if (vide()) {
          std::cout << "Liste vide !" << std::endl;
       } else {
             CNoeud<T>* n = (this->tete);
             // delete the first node of the list 
             if ((n->contenu->get_id()) == id) {
                 this->tete=n->suiv;
                 return n->contenu; // ATTENTION : il faut supprimer n->contenu quelque part sinon fuite memoire
            } else {
                // TODO ;-)
         }
     }
     return nullptr; 
}

template <class T> bool CListe<T>::vide() const {
     return (this->tete == nullptr && this->queue == nullptr); 
}

template <class T> void CListe<T>::affiche() const {
     if (vide()) {
         std::cout << "Liste vide !" << std::endl;
     } else {
         CNoeud<T>* n = this->tete;
         while (n != nullptr) {    
                //std::cout << *(n->contenu); // => pour exercice 2
                n->contenu->affiche(); // => pour exercice 3
                n = n->suiv; 
         }
     }
     std::cout << std::endl;
}

template <class T> CNoeud<T>* CListe<T>::get_tete() const {
      return this->tete;
}

template <class T> CNoeud<T>* CListe<T>::get_queue() const {
       return this->queue;
}

template <class T> CListe<T>::~CListe() {
         // nettoyage des elements de la liste
         CNoeud<T>* temp = this->tete;
         CNoeud<T>* suiv;
         while (temp != nullptr) {
               suiv = temp->suiv; 
               delete temp; // personne est supprime dans le destructeur de CNoued
               temp = suiv;  
         } 
         this->tete = nullptr;
}


#endif
