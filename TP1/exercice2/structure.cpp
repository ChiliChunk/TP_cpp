#include <stdio.h>
#include <iostream>
#include "struc.hpp"

using namespace std;

TPersonne * new_personne(){
    TPersonne * p =new TPersonne;
    string tempnom;
    cout << "Le nom: \n";
    cin >> tempnom;
    string tempprenom;
    cout << "Le prenom: \n";
    cin >> tempprenom;
    string tempmail;
    cout << "Le mail: \n";
    cin >> tempmail;
    string tempid;
    cout << "L' id: \n";
    cin >> tempid;
    p->nom = tempnom;
    p->prenom = tempprenom;
    p->mail = tempmail;
    p->id = tempid;
    return p;
}

void affiche(TPersonne * p){
    cout << "Affichage\n";
    cout << "nom\n";
    cout << p->nom<< "\n";
    cout << "prénom\n";
    cout << p->prenom<< "\n";
    cout << "mail\n";
    cout << p->mail<< "\n";
    cout << "id\n";
    cout << p->id << "\n";

}

// int main(){
//    TPersonne * p = new_personne();
//    cout << p << "\n";
//    affiche(p);
//    delete p;
//    p=nullptr;
// }