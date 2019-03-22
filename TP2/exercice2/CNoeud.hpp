#include "CPersonne.hpp"
class CNoeud{
  CNoeud* suiv;
  CNoeud* pred;
  CPersonne* pers;
  public:
    CNoeud();
    CNoeud(CPersonne*,CNoeud*,CNoeud*);
    CPersonne* get_pers() const;
    CNoeud* get_pred() const;
    CNoeud* get_suiv() const;
    ~CNoeud();
}