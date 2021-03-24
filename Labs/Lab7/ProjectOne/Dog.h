/**
 *  This file specifies the Dog class.
 */ 

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
  
    private:
        string breed ;
    public:
        //Consturctor
        Dog(string,string) ;
        //Accessor and Mutator
        string getBreed() ;
        void setBreed(string) ;
        //Functionality
        void makeNoise() ;
        //Display
        void showInfo() ;

} ;

#endif 