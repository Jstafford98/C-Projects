#include <iostream>
#include <vector>
#include <ctime>

using namespace std ;

int main() {

  vector<int> elements ;
  srand((unsigned) time(0)) ;//Set seed
  int lowestNum = 11 ;//Instance variable to track the lowest number in the vector 'elements'
  
  //Fill elements with 30 random numbers between 0 and 10
  for (int i = 0 ; i < 30 ; i++){
    int tmp = rand() % RAND_MAX + 1 ;//Generate a random number between 1 and RAND_MAX
    tmp %= 11 ;//Reduce random number between 0 and 10
    int count = 0 ;//This variable will store the index of the first number that is lower than our newly generated random number
    //Determine insertion point for new number
    if (elements.size() == 0){//If this is the first element, we had to put it into the vector ourselves. Otherwise, an exception occurs. 
      vector<int> :: iterator it = elements.insert(elements.begin(),tmp) ;//Insert random number at 0
      continue ;
    } else if (tmp <= lowestNum){//If this number is lower than any in the vector. Program requires this statement or elements will be limited to only numbers greater than the first number provided
      lowestNum = tmp ;
      vector<int> :: iterator it = elements.insert(elements.end(),tmp) ;//Insert random number at end
    } else {
      for (int i : elements){ 
      if (i < tmp){
          vector<int> :: iterator it = elements.insert(elements.begin() + count,tmp) ;//Insert random number at count
          break ;
        }
        count++ ;
      }
    }
  }

  //Print the vector and remove elements until the vector is empty
  while ((!elements.size() == 1) || (!elements.empty())){
    cout << elements.back() << ", " ;
    elements.pop_back() ;
  }

  return 0 ;
}
