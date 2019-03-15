#include <stdio.h>
#include <iostream>
#include "fonctions.hpp"
using namespace std;
using namespace fonctions;

int main (){
    int len = _strlen("test");
    // cout << len ;
    const char * source = "Strang à copier";
    char destination [23] ;
    _strcpy(destination , source);
    cout << destination << "\n";
    const char * source2 = "La bonne phrase";
    char destination2 [23] ;
    char * test = _strncpy(destination2 , source2 , 19);
    cout << test;
}