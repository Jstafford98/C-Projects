#include "Country.h"

using namespace std ;

//Country Implementations
Country::Country(string name,int population, int area){
  mName = name ;
  mArea = area ;
  mPopulation = population ;
}
string Country::getName(){
  return mName ;
}
double Country::getArea(){
  return mArea ;
}
double Country::getPopulation(){
  return mPopulation ;
}


