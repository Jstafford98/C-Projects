/* PersonAtMCC.cpp - Function definitions for parent class
 * Author:     Jordan Stafford
 * Module:     7
 * Project:    Lab, Part 1
 * Description:  Function definitions for parent class
 */

#include "PersonAtMCC.h"
#include <iostream>

using namespace std ;

//Constructors
PersonAtMCC::PersonAtMCC(){
    PersonAtMCC(0000000000,"","","") ;
}
PersonAtMCC::PersonAtMCC(long id, string name){
    PersonAtMCC(id,name,"","") ;
}
PersonAtMCC::PersonAtMCC(long id,string name ,string address,string number){
    this->id = id ;
    this->name = name ;
    this->address = address ;
    this->phone = number ;
}

// getters and setters
long PersonAtMCC::getId() {
    return id ;
}
string PersonAtMCC::getName() {
    return name ;
}
string PersonAtMCC::getAddress() {
    return address ;
}
string PersonAtMCC::getPhone() {
    return phone ;
}

// Setters
void PersonAtMCC::setId(long new_id) {
    id = new_id ;
}
void PersonAtMCC::setName(string new_name) {
    name = new_name ;
}
void PersonAtMCC::setAddress(string new_address) {
    address = new_address ;
}
void PersonAtMCC::setPhone(string new_phone) {
    phone = new_phone ;
}

//Display
void PersonAtMCC::showInfo() {
    cout << "ID: " << id << " Name: " << name << " Address: " << address 
         << "\n    Phone: " << phone << endl ;
}
