/**
 *  This file finishes the specification of the Dog class. See header file for function documentation. 
 */ 

#include "Dog.h"

using namespace std ;

Dog::Dog(string name, string breed) : Animal(name) {
    this-> breed = breed ;
    cout << "The Dog " << Animal::getName() << " of breed " << this-> breed << " has been created.\n" ;
}
string Dog::getBreed(){
    return breed ;
}
void Dog::setBreed(string breed){
    this->breed = breed ;
}
void Dog::makeNoise(){
    cout << "The Dog " << Animal::getName() << " is barking." ;
}
void Dog::showInfo(){
    cout << "The Dog " << Animal::getName() << " of breed " << breed << "." ;
}

