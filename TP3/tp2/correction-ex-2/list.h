#ifndef LIST_H
#define LIST_H

#include "../correction-ex-1/person.h"

class CListe;

class CNoeud {
      friend class CListe; 
      private : 
        CPersonne* pers;
        CNoeud* pred;
        CNoeud* suiv;
      public :
        CNoeud(); 
        CNoeud(CPersonne*,CNoeud*,CNoeud*);
        CPersonne* get_pers() const;
        CNoeud* get_pred() const;
        CNoeud* get_suiv() const;
        ~CNoeud();
};

class CListe {
       friend class CNoeud; 
       CNoeud* tete;
       CNoeud* queue;
       public : 
         CListe();
         CListe(CNoeud*,CNoeud*);
         bool ajoute(CPersonne*);
         CPersonne* recherche(std::string) const;
         CPersonne* supprime(std::string);
         bool vide() const; 
         CNoeud* get_tete() const;
         CNoeud* get_queue() const;
         void affiche() const;
         ~CListe();         
};

#endif
