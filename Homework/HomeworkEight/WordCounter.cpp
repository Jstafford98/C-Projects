/* WordCounter.cpp - This program counts the total words in a c string
 * Author:     Jordan Stafford
 * Module:     8
 * Project:    Homework, Project 1
 * Problem statement: Counts total words in a given c string
 *
 * Algorithm:
 *   1. First, the user is prompted to enter a set of text under 250 characters long. 
 *   2. The entered text is stored in a c string and the termination character is added to the end. 
 *   3. Finally, the output of the countWords function is printed to the screen. The count words function iterates all charactesr in the c string and increments a counter every time a ' ' character is encountered. This counter is what is returned. 
 */

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std ;

//Prototypes
int countWords(char*, int) ;

int main(){

    //Create a C string of a given size
    const int SIZE = 256 ;
    char input[SIZE] ;
    //Read in an input of up to 250 characters
    cout << "Enter a string to count the total words (250 character limit): " ;
    cin.getline(input,SIZE) ;
    //Add termination character
    input[SIZE-1] = '\0' ;
    //Display word count
    cout << countWords(input,SIZE) ;


}

/**
 * This function counts all words in a set of text by delimiting words with a ' ' character. Mulitple ' ' in a row will not be counted.
 */
int countWords(char *c,int size){
    
    int count = 1 ;
    //Case of empty string
    if (size == 0)
        return 0 ;
    //Iterate cstring and cout each space as a word
    char prev ;
    for_each(c,c+size,[&](char &c){
        if (c == ' '){
            if (prev  != ' '){
                prev = c ;
                count++ ;
            }
        }
        prev = c ;
    }) ;
    //Return count
    return count ;
}