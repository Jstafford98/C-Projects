/* Instructor.cpp - Definition of functions for the Instructor subclass to PersonAtMCC
 * Author:     Jordan Stafford
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Instructor.h"
#include <iostream>

using namespace std ;

//Constructors
Instructor :: Instructor(long id, string name , string address , string phone, string department, bool is_permanent, double pay_rate, double hours){
      setId(id) ;
      setName(name) ;
      setAddress(address) ;
      setPhone(phone) ;
      this->department = department ;
      this->is_permanent = is_permanent ;
      this->hours = hours ;
      this->pay_rate = pay_rate ;
      
}
// Getters for this class only
string Instructor::getDepartment() {
    return department ;
}
bool Instructor::getIsPermanent() {
    return is_permanent ;
}
double Instructor::getPayRate() {
    return pay_rate ;
}

// Setters for this class only
void Instructor::setDepartment(string new_department) {
    department = new_department ;
}
void Instructor::setIsPermanent(bool new_is_permanent) {
    is_permanent = new_is_permanent ;
}
void Instructor::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate ;
}

//Display
void Instructor::showInfo() {
    PersonAtMCC :: showInfo() ;
    cout << "    Department: " << department << " Permanent? " ;
    is_permanent ? cout << "Yes" : cout << "No" ;
    cout << " Pay-Rate: " << pay_rate << " Hours: " << hours ;
}
