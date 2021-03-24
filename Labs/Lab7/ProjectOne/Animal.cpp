/**
 * This file finishes the specification of the Animal class. See header for function documentation.
 */ 

#include "Animal.h"

using namespace std ;

Animal::Animal(string name){
    this->name = name ;
    cout << "The Animal " << this->name << " has been created.\n" ;
}

string Animal::getName(){
    return name ;
}
void Animal::setName(string name){
    this->name = name ;
}

void Animal::sleep(){
    cout << "The Animal " << name << " is sleeping." ;
}
void Animal::makeNoise(){
    cout << "The Animal " << name << " is making a noise." ;
}

void Animal::showInfo(){
    cout << "The Animal " << name ;
}