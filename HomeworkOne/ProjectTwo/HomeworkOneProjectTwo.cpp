#include <iostream>
#include <iomanip>
#include <vector>
#include "Country.h" 

vector<Country> countries ;

void vecInsert(Country&) ; 
void printReport() ;

int main() {

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

  printReport() ;

}
void vecInsert(Country &c){

  int count = 0 ;

  if (countries.size() == 0){
    countries.insert(countries.begin(),c) ;
    cout << c.getName() << " added." << endl ;
  }
  else
    for (Country x : countries){
      if (x.getArea() > c.getArea()){
        countries.insert(countries.begin() + count,c) ;
        break ;
      }
    }
    count++ ;
    
}
void printReport(){
  for (Country c : countries)
    cout << "Country: " << c.getName() << ",Area: " << c.getArea() << endl ;
}
