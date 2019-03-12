#include <stdio.h>
#include <iostream>
using namespace std;
struct TPersonne {
    string prenom;
    string nom;
    string mail;
    string id;
};
TPersonne* new_personne();
void affiche(TPersonne *p);