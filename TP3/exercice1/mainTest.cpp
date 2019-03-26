#include <iostream>
#include "list.h"
using namespace std;

int main() {
    CListe<int> listeInt (nullptr, nullptr);
    int *pi1 = new int;
    // int *pi2 = new int;
    // int *pi3 = new int;

    // (*pi1) = 1;
    // (*pi2) = 2;
    // (*pi3) = 3;

    listeInt.ajoute(pi1);
    // listeInt.ajoute(pi2);
    // listeInt.ajoute(pi3);

    // listeInt.affiche();
    // //------------------------

    // CPersonne* p1 = new CPersonne("1", "tre", "fds", "rt@re.fe");
    // CPersonne* p2 = new CPersonne("2", "tazd", "fazdds", "razdt@rdae.fe");
    // CPersonne* p3 = new CPersonne("3", "trgfge", "fdvbs", "rtcvbn@recv.fe");

    // CListe<CPersonne>* listePerson = new CListe<CPersonne> (nullptr, nullptr);
    // listePerson -> ajoute(p1);
    // listePerson -> ajoute(p2);
    // listePerson -> ajoute(p3);

    // listePerson -> affiche();
    // delete listePerson;
    // listePerson = nullptr;

    // return 0;
}