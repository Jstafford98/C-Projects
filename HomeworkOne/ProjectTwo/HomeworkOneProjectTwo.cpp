/**
*   HomeworkOneProjectTwo.cpp - This program sorts a vector of country objects by inserting them in the correct position as they are added
*   Author: Jordan Stafford
*   Assignment: Homework 1 Project 2
*   Problem Statement: This program aides the user in sorting a vector of countries by area as they are added
*   Algorithim: 1) First, multiple country objects are added that represent a South American country. As each object is created, it is added to the global vector using vecInsert.
                2) vecInsert is able to add the country objects in order by country area using the following algorithim:
                          1) First, we increment the continent_x variables based on the function parameter object's values.
                          2) Next, using a for loop, we iterate through the vector. If the country at the current index has a greater area than the new country object, we insert the object at that index to shift the vector. 
                             Once complete, the function returns.
                          3) If no object in the vector has a larger area than the new country object, we simply insert it at the end using the push_back function.
                3) Once all objects are added, the vector is displayed using the printReport function and the program then exits. printReport creates a formatted display using various iomanip functions.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include "Country.h" 

//Global Variables
vector<Country> countries ;
unsigned int continent_population = 0, continent_area = 0;

//Prototypes
void vecInsert(Country) ; 
void printReport() ;

//Main function
int main() {

  //Add hardcoded elements to vector using vecInsert
  Country argentina("Argentina",45258,1073234) ;
  vecInsert(argentina) ;
  Country bolivia("Bolivia",11696,424052) ;
  vecInsert(bolivia) ;
  Country brazil("Brazil",212845,3287086) ;
  vecInsert(brazil) ;
  Country chile("Chile",19206,291855) ;
  vecInsert(chile) ;
  Country columbia("Columbia",51115,440715) ;
  vecInsert(columbia) ;
  Country ecuador("Ecuador",17705,106851) ;
  vecInsert(ecuador) ;
  Country falkland_islands("Falkland Islands",3,4700) ;
  vecInsert(falkland_islands) ;
  Country french_guiana("French Guiana",290,32253) ;
  vecInsert(french_guiana) ;
  Country guyana("Guyana",787,82978) ;
  vecInsert(guyana) ;
  Country paraguay("Paraguay",7145,157056) ;
  vecInsert(paraguay) ;
  Country peru("Peru",33108,496093) ;
  vecInsert(peru) ;
  Country suriname("Suriname",586,63252) ;
  vecInsert(suriname) ;
  Country uruguay("Uruguay",3475,68037) ;
  vecInsert(uruguay) ;
  Country venezuela("Venezuela",28102,353748) ;
  vecInsert(venezuela) ;

  //Display report of elements
  printReport() ;

}

void vecInsert(Country c){
  
    //Increment population and area accumulators
    continent_area += c.getArea() ;
    continent_population += c.getPopulation() ;

    //Iterate thorugh vector to determine location of new country object
    for (int i = 0 ; i < countries.size() ; i++){
      //If the current element has a greater area than the new object, we use an iterator to insert the object at that index and shift the vector
      if (countries[i].getArea() > c.getArea()){
        countries.insert(countries.begin() + i,c) ;
        return ;
      }
    }
    //If the new object's area is greater than every other object's in the vector, we simply add it to the back
    countries.push_back(c) ;  

}

void printReport(){

  //Print Report Header
  cout << "     " << setw(11) << left << "Country" << " " << setw(10) << right << "Population" << " " << setw(7) << "Area" << endl ;
  cout << "---------------- ---------- ----------" << endl ;
  //Print all objects of vector into a formatted report
  for (Country c : countries)
    cout << fixed  << setprecision(0) << setw(16) << left << c.getName() << " " << setw(10) << right << c.getPopulation() << " " << setw(10) << c.getArea() << endl ;
  //Print Totals
  cout << "--------------------------------------" << endl ;
  cout << setw(16) << left << "Country Totals: " << " " << setw(10) << right << continent_population << " " << setw(10) << continent_area << endl ;
}
