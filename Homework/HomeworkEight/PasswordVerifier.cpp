/* PasswordVerifier.cpp - This function ensures a user provided password meets specified requirements
 * Author:     Jordan Stafford
 * Module:     8
 * Project:    Homework, Project 2
 * Problem statement: This problem ensures are password entires are valid
 *
 * Algorithm:
 *   1.  First, the user is prompted to enter a password.
 *   2.  The password is then passed to the validate function, which iterates each character in the string and checks if it meets one of the boolean
 *       flags representing the password requirements. 
 *   3.  Once all characters have been checked, the boolean flags are passed to the generateErrorMessage function. 
 *   4.  The generateErrorMessage function prints various messages about failed requirements to the console using the boolean flags.
 *   5.  Lastly, the validate function returns a boolean value representing whether or not the password is valid. 
 *   6.  If the password was not valid, steps 1-5 are repeated. Otherwise, an acceptance message is printed and the program exits.
 */

#include <iostream>
#include <string.h>
#include <algorithm>


using namespace std ;

//Prototypes
bool validate(string) ;
bool inValueRange(char,int,int) ;
void generateErrorMessage(bool,bool,bool,bool,bool) ;

int main(){

    string input ;

    //Run until a valid password is entered
    do {
        //Prompt input from user
        cout << "          Enter a password that:\n" ;
        cout << "------------------------------------------------\n" ;
        cout << "      -is at least 6 characters long\n" ;
        cout << "      -contains one uppercase letter\n" ;
        cout << "      -contians one lowercase letter\n" ;
        cout << "             -contains a digit\n" ;
        cout << "            -contains no spaces\n" ;
        cout << "------------------------------------------------\n" ;
        cout << "Password:" ;
        getline(cin,input) ;
    } while (!validate(input)) ;
    cout << "Password has been accepted!\n" ;

    
}

/**
 * This function validates a Password passed as a string based on the following requirements:
 *      - Length greater than or equal to 6
 *      - Has one upper and one lowercase letter
 *      - Has a digit
 *      - Has no blank spaces
 */
bool validate(string str){

    //ASCII range constants
    const int DIGIT_LOWER_BOUND = 48          , DIGIT_UPPER_BOUND = 57            ,
              CHAR_LOWER_CASE_LOWER_BOUND = 65, CHAR_UPPER_CASE_LOWER_BOUND = 97  ,
              CHAR_LOWER_CASE_UPPER_BOUND = 90, CHAR_UPPER_CASE_UPPER_BOUND = 122 ;

    bool has_upper = false, has_lower = false, has_digit = false , no_blanks = true, meets_length = str.length() >= 6 ; 

    //Iterate string using a lambda, checking for case, digit, or blank spaces
    for_each(str.begin(),str.end(),[&](char c){
        if (inValueRange(c,CHAR_UPPER_CASE_LOWER_BOUND,CHAR_UPPER_CASE_UPPER_BOUND)){
            has_lower = true ;
        }else if (inValueRange(c,CHAR_LOWER_CASE_LOWER_BOUND,CHAR_LOWER_CASE_UPPER_BOUND)){
            has_upper = true ;
        }else if (inValueRange(c,DIGIT_LOWER_BOUND,DIGIT_UPPER_BOUND)){
            has_digit = true ;
        }else if (c == ' '){
            no_blanks = false ;
        }
        
    }) ;

    //Prompt system to show errors
    generateErrorMessage(!meets_length,!has_upper, !has_lower, !has_digit, !no_blanks) ;

    //Return true is all criteria is met, false otherwise
    return meets_length && has_upper && has_lower && has_digit && no_blanks ;
}

/**
 * This function prints erros depending on the passed parameters.
 */
void generateErrorMessage(bool too_short, bool no_upper, bool no_lower, bool no_digit, bool has_blank){

    bool fail = too_short || no_upper || no_lower || no_digit || has_blank ;

    if (!fail)
        return ;

    cout << "\n\n            Invalid: Password is: \n" ;
    cout <<     "------------------------------------------------\n" ;    if (too_short)
        cout << "               -too short.\n" ;
    if (no_upper)
        cout << "   -does not contain an upper case character.\n" ;
    if (no_lower)
        cout << "   -does not contain a lower case character.\n" ;
    if (no_digit)
        cout << "         -does not contain a digit.\n" ;
    if (has_blank)
        cout << "         -contains a blank space.\n" ;
    cout << "\n\n" ;


}

/**
 * This function determines if a character is within a value range 
 * @param c is the character we are checking
 * @param lower_bound is an inclusive, lowest accepted value for that range
 * @param upper_bound is an inclusive, highest accepted value for that range
 */
bool inValueRange(char c, int lower_bound, int upper_bound){
    int val = c ;
    return (c >= lower_bound && c <= upper_bound) ;
}

