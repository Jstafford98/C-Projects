/**
 * This file specifies the Bird class.
 */ 

#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
    public:
        //Constructor
        Bird(string) ;
        //Bird Functionality
        void makeNoise() ;
        //Display
        void showInfo() ;
} ;

#endif 