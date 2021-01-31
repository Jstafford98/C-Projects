/**
*   HomeworkOneProjectOne.cpp - This program generates a vector with 30 random numbers between 1 and 10
*   Author: Jordan Stafford
*   Assignment: Homework 1 Project 2
*   Problem Statement: This program helps the user generate a vector a random values
*   Algorithim: 
               1) First, the seed is set for rand() so we can generate a new random number each time.
               2) Then, a for loop is used to generate 30 random numbers. With each iteration, a new random number is generated between
                  0 and RAND_MAX. We then use the modulo operator to reduce the number to a digit between 0 and 10. 
               3) The vecInsert function is then used to insert each random number as it is generated into the global vector in descending
                  order. See function implementation for function algorithim.
               4) After the for loop exits, the printVec function is called, which prints all values in the vector in ascending order in a formatted manner using the 
                  pop_back function since the vector was stored in descending order.
*/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std ;

//Prototypes
void printVec() ;
void vecInsert(int) ;

//Global Variables
vector<int> elements ;
int lowestNum = 11 ;//Instance variable to track the lowest number in the vector 'elements'

//Main Function
int main() {

    //Set seed
    srand((unsigned) time(0)) ;

    //Fill elements with 30 random numbers between 0 and 10
    for (int i = 0 ; i < 30 ; i++){
        int tmp = rand() % RAND_MAX + 1 ;//Generate a random number between 1 and RAND_MAX
        tmp %= 11 ;//Reduce random number between 0 and 10
        vecInsert(tmp) ;
    }

    //Display result
    printVec() ;

}//End main

void printVec(){

    //Print the vector and remove elements until the vector is empty
    while ((elements.size() > 1)){
        cout << elements.back() << ", " ;
        elements.pop_back() ;
    }
    cout << elements.back() << "." ;

}//End printVec

/**
 * This function inserts a primitive integer value into a global vector in descending order using a linear search. This function uses a multi-way if to determine the numbers insertion point.
 * If this is the first entry to the vector, the function simply inserts it at the beginning. 
 * If this is the lowest number we have attempted to insert thus far, it is inserted at the end.
 * Otherwise, we iterate over the vector using a for loop and compare each value to the new value. If the new value is greater than the current value, we insert the new value at that position.
 */
void vecInsert(int tmp){

    //This variable will store the index of the first number that is lower than our newly generated random number
    int count = 0 ;

    //Determine insertion point for new number
    if (elements.size() == 0){//If this is the first element, we had to put it into the vector ourselves. Otherwise, an exception occurs. 
        vector<int> :: iterator it = elements.insert(elements.begin(),tmp) ;//Insert random number at 0
    } else if (tmp <= lowestNum){//If this number is lower than any in the vector. Program requires this statement or elements will be limited to only numbers greater than the first number provided
        lowestNum = tmp ;
        vector<int> :: iterator it = elements.insert(elements.end(),tmp) ;//Insert number at end
    } else {
        for (int i : elements){ 
            if (i < tmp){
                vector<int> :: iterator it = elements.insert(elements.begin() + count,tmp) ;//Insert number at count
                return ;
            }
            count++ ;
        }//for
    }//else
}//End vecInsert

