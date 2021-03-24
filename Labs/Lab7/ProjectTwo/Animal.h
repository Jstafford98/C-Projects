/**
 *  This header file specifies the requirements for the Animal class
 */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std ;

class Animal{
    private:
        string name ;

    public:

        //Constructor
        Animal(string) ;
        //Accessor and Mutator
        string getName() ;
        void setName(string) ;
        //Animal Functionalities
        void sleep() ;
        void makeNoise() ;
        //Display
        void showInfo() ;

} ;

#endif 