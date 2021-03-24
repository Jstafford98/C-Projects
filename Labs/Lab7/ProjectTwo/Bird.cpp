/**
 *  This file finishes the specification of the Bird class.
 */ 

#include "Bird.h"

using namespace std ;

Bird::Bird(string name): Animal(name){
    cout << "The Bird " << Animal::getName() << " has been created.\n";
}   

void Bird::makeNoise(){
    cout << "The Bird " << Animal::getName() << " is chirping." ;
}

void Bird::showInfo(){
    cout << "The Bird " << Animal::getName() ;
}
