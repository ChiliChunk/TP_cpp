#include "struc.hpp"

struct TNoeud {
    TNoeud * suivant;
    TNoeud * precedent;
    TPersonne * contenu;
    };

struct TList {
    TNoeud * tete;
    TNoeud * queue;
};

bool ajoute(TList *,TPersonne *);

TPersonne * supprime(TList * list , const string id);

void affiche (const TList * );