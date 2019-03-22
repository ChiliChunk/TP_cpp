#include "CNoeud.hpp"

class CList{
  private:
    CNoeud* tete;
    CNoeud* queue;
    public:
      CList();
      CList(CNoeud*,CNoeud*);
      bool ajoute(CPersonne*);
      CPersonne* recherche (string) const;
      CPersonne* supprime(string);
      bool vide()const();
      void affiche() const;
      CNoeud* get_tete() const;
      CNoeud* get_queue() const ;
      ~CList();
}