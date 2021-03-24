/**
* AnimalDriver.cpp - This program demonstrates inheritance within the Animal class and it's children
* Author: Jordan Stafford
* Module: 7
* Lab 7 Project 2
* Problem Statement: This program showcases various inheritance concepts
* Algorithim: 1) First, 3 objects are declared of Animal, Dog, and Bird classes, respectively. These objects will be used to demonstrate various
*                functionalities.
*             2) Next, for all 3 objects, we call the showInfo, makeNoise, and sleep functions on them and display the results. 
*
* Questions: 1) The base class is Animal
*            2) The derived classes are Dog and Bird
*            3) The Animal class does not have a defined superclass like in Java
*            4) The showInfo and makeNoise functions are overriden in both Dog and Bird. The sleep function is not. 
*            5) No, because protected data members are available to subclasses. Yes, becaue base access modifiers will not affect the accessibility 
                of  private members. 
**/

#include "Animal.h"
#include "Bird.h"
#include "Dog.h"

using namespace std ;

int main(){

    //Objects to test
    Animal oscar("Oscar") ;
    Dog inka("Inka","Mutt") ;
    Bird tweety("Tweety") ;

    //Animal
    oscar.showInfo() ;
    cout << endl ;
    oscar.makeNoise() ;
    cout << endl ;
    oscar.sleep() ;
    cout << endl ;

    //Dog
    inka.showInfo() ;
    cout << endl ;
    inka.makeNoise() ;
    cout << endl ;
    inka.sleep() ;
    cout << endl ;
    
    //Bird
    tweety.showInfo() ;
    cout << endl ;
    tweety.makeNoise() ;
    cout << endl ;
    tweety.sleep() ;
    cout << endl ;

}