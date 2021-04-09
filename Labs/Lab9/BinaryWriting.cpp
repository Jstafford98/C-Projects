#include <iostream>
#include <fstream>
#include <math.h>

using namespace std ;

//Constants
const string FILE_NAME = "array.dat" ;

int main(){

    //Open the file
    ofstream data_file(FILE_NAME,ios::binary | ios::out) ;
    if (!data_file){
        cout << "ERROR: File does not exist." << endl ;
        exit(1) ; 
    }

    //Write numbers 1-10 to file as integers
    for (int i = 1 ; i <= 10 ; i++){
        double val = sqrt(i) ;
        cout << "Values: " << i << endl ;
        data_file.write(reinterpret_cast <char *>(&i),sizeof(int)) ;
        
    }
  
    //Write the square roots of number 1-10 to the file as doubles
    for (int i = 1 ; i <= 10 ; i++){
        double val = sqrt(i) ;
        cout << " Sqrt: " << val << endl ;
        data_file.write(reinterpret_cast <char *>(&val),sizeof(double)) ;
        
    }

    //Close the file
    data_file.close() ;

}
