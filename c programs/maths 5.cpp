// C++ program to generate a random number in a range

#include <iostream>
#include <random>
using namespace std;

// Probablity function will randomly generate a number between 0 and 1 and compare it with p 
// then return 0 or 1 based on the comparison where we will assign 0 or 1 to reflection and all
bool Probablity(double p) 
{
    // Define range
    double min = 0;
    double max = 1;
    srand(time(NULL)*time(NULL));
   double randomValue= ((double)rand())/RAND_MAX;
    //cout << randomValue << endl;//
    if(randomValue < p){return 0;}
    return 1;
}

int main (){
    double p=0.56;
    cout << Probablity(p) <<endl;
}