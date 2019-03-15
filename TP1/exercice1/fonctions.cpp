#include <stdio.h>
#include <iostream>
#include "fonctions.hpp"
using namespace std;

size_t fonctions::_strlen (const char * str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

void fonctions::_strcpy (char * destination, const char *source){
    for (int i = 0 ; i < 23 ; i ++){
        destination[i] = ';';
    }
    size_t lenDest = fonctions::_strlen(destination);
    size_t lenSource = fonctions::_strlen(source);
    if (lenDest > lenSource){
        for (int i = 0 ; i < lenSource ; i++){
            destination[i] = source[i];
        }
    }
    else{
    }

}

char * fonctions::_strncpy (char *destination, const char *source,size_t num){
     for (int i = 0 ; i < 23 ; i ++){
        destination[i] = '0';
    }
    size_t lenDest = fonctions::_strlen(destination);
    size_t lenSource = fonctions::_strlen(source);
    if (lenDest > lenSource){
        for (int j = 0 ; j < num ; j++){
            if (j > lenSource){
               destination[j] = '0' ;
            }
            else{
            destination[j] = source[j];
            }
        }
    }
    return destination;
}