/**
*   DecimalToBinary.cpp - This program converts decimal (base 10) numbers to binary (base 2)
*   Author: Jordan Stafford
*   Assignment: Homework 2 Project 1
*   Problem Statement: This program aides the user in converting decimal numbers to binary 
*   Algorithim: 
               1) First, after entering the main loop, the user is prompted to enter a decimal number to convert to binary.  
               2) Next, we check for the exit case. Since the main loop is intentionally infinite, our sentinel is going to be -1. If the user enters -1, 
                  the loop will break and the program will exit.
               4) After this, the number is converted to binary and displayed to the user. The number is converted using the decimalToBinary function. The 
                  function uses the following Algorithim:
                      1) Store the integer parameter value in the decimal_number variable.
                      2) Next, check to ensure that the provided value is not 0. If it is, we simply return a string containing the character '0'
                      3) Then, we enter a while loop that will loop until our decimal_number variable has been reduced to 0. The following steps implement the 
                         process described in the Decimal to Binary Guide 
                            3a) First, we use the ternary operator to determine which character to add to our string ('0' or '1'). If the current value
                                of the decimal_number variable % 2 == 0, then 0 is added. If variable % 2 == 1, then 1 is added.
                            3b) The result from step 3a is added to the string at index 0 using the std::string::insert function. By going about it
                                this way, we do not have to print the string in reverse or reverse the string at all at the end. The output string will be in order. 
                            3c) Lastly, we divide the decimal_number variable by 2 and then repeat from step 3. 
                      4) Once step 3 is complete, the program will return the binary string in it's proper order.
               5) Once the value is returned and used in step 4, the program loop will continue to a new iteration. Steps 1-5 will continue indefinitely until the user enters -1
                  during step 2. At that time, the program will simply exit. 
    Decimal To Binary Guide:
      To convert a decimal number to binary, you simply divide the starting decimal number by 2 (using integer division) until it is equal to 0.
      each time you divide the number, you add the remainder (Either '0' or '1') to the binary number. For example, 9 /2 = 4 with a remainder of 1
      and 1 / 2 = 0 with a remainder of 1. Once complete, you now just have to rewrite the numbers in reverse to get your decimal number in binary. 
*/
#include <iostream>
#include <string>

using namespace std ;

//Prototypes
string decimalToBinary(int) ;

int main() {
  
  int decimalInput ;

  while (true){

    cout << "Enter a number to convert to a Binary Number (Enter -1 to exit): ", cin >> decimalInput ;//Prompt user for a decimal number

    if (decimalInput == -1)//Check for sentinel
      break ;

    cout << decimalInput << " in binary is " << decimalToBinary(decimalInput) << "." << endl ;//Convert to binary and display to user
  }
}
string decimalToBinary(int n){
  
  int decimal_number = n ;

  string binary = "" ;//Will be used to store our return string

  if (decimal_number == 0)//0 in  binary is simply 0
    return "0" ;

  while (decimal_number){
    decimal_number % 2 ? binary.insert(0,1,'1') : binary.insert(0,1,'0') ;//Insert appropriate binary digit at front of string 
    decimal_number /=2 ;//Divide decimal number by 2 for next iteration
  }
  return binary ;
}
