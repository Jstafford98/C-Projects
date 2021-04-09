 #include <iostream>
#include <fstream>
#include <math.h>

using namespace std ;

//Constants
const string FILE_NAME = "array.dat" ;

int main(){

    //Open the file
    fstream data_file(FILE_NAME,ios::binary | ios :: in | ios::out) ;
    if (!data_file){
        cout << "ERROR: File does not exist." << endl ;
        exit(1) ;  
    }

    //Get the value multiplier
    double multiplier ;
    cout << "Please enter the multiplier: " ;
    cin >> multiplier ;

    //Apply the value multiplier to each integer value in the file and display the results
    cout << "Reading and updating ints. . . " << endl ;
    for (int i = 1; i <=10 ; i++){
        int data ;
        long long position = data_file.tellg() ;
        data_file.read(reinterpret_cast<char *>(&data),sizeof(int)) ;
        cout << data << "-> " ;
        data = round(data*multiplier) ;
        cout << data << endl ;
        data_file.seekp(position,ios::beg) ;
        data_file.write(reinterpret_cast<char *>(&data),sizeof(int))  ;
    }
  //Apply the multiplier to each double value in the file and display the results
    cout << "\nReading doubles. . . " << endl ;
    for (int i = 1; i <=10 ; i++){
        double data ;
        long long position = data_file.tellg() ;
        data_file.read(reinterpret_cast<char *>(&data),sizeof(double)) ;
        cout << data << "-> " ;
        data *= multiplier ;
        cout << data << " (root of " << pow(data,2) << ")" << endl ;
        data_file.seekp(position,ios::beg) ;
        data_file.write(reinterpret_cast<char *>(&data),sizeof(double)) ;
    }



}
