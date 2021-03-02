#ifndef COUNTRY_Y
#define COUNTRY_Y

#include <string>

using namespace std ;

class Country {
  //Data Members
  private:
    string mName ;
    double mPopulation ;
    double mArea ;
  public:
    //Constructor
    Country(string,int,int) ;
    //Getters
    string getName() ;
    double getPopulation() ;
    double getArea() ;
} ;

#endif 
