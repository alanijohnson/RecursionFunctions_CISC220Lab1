/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alani Johnson
 * TA: Taghreed Bagies
 * 2/16/17
 *
 * This file contains functons for lab 1.
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;

//function declarations
bool isPrime(int num); //problem 2
void multTables(int num); //problem 3
void manyMultTables(int num); //problem 4
void collatzConjecture(int num); //problem 5
void leapYears(int year); //problem 6
void xStar(int num); //problem 7
void collatzConjectureBetweenValues(int num1,int num2); //problem 8
bool isPrime_Recursive(int num, int count); //problem 9
int multTables_Recursive(int num1, int start, int stop); //problem 10
int leapYears_Recursive(int year,  int futureyears); //problem 11

int main(int argc, char** argv) {
    
    cout << "Hello World!" << endl; //problem 1
    
    cout<<isPrime(5)<<endl; //problem 2

    multTables(4); //problem 3

    manyMultTables(12); //problem 4

    collatzConjecture(300); //problem 5

    leapYears(2017); //problem 6
    
    xStar(3); //problem 7
    
    collatzConjectureBetweenValues(2,4); //problem 8
    
    isPrime_Recursive(29,28); //problem 9
    
    multTables_Recursive(4,1,12); //problem 10
    
    leapYears_Recursive(2017,400); //problem 11
    

    return 0;
}
/*
 * Problem 2:
 * evaluate whether or not an inputted value int
 * is a prime number (it has no factors other than 1 and itself)
 */
bool isPrime(int num) { //problem 2
    bool boolean = true;
    for (int i = 2; i <= pow(num, 0.5); i++) { //test from 2 to the square root of the input
        if ((num % i) == 0) { //if the number is divisible then it is prime
            boolean = false;
        } 
    }
    return boolean;
}

/* 
 *Problem 3
 *prints the multiplication facts for an integer from 1-12
 */
void multTables(int num) { //problem 3

    for (int i = 1; i <= 12; i++) {
        cout<<num<<"x"<<i<<"="<<i*num<<endl;
    }
}

/*
 *Problem 4
 * prints all the multipication facts from 1-12 for all values up to the inputted int
 * the function calls multTables from problem 3 
 */
void manyMultTables(int num) { //problem 4
    for (int i = 1; i <= num; i++) {
        multTables(i); //call the function from problem 3
        cout << endl;
    }
}

/*
 *Problem 5
 * executes the collatz conjecture for a given int value
 * collatz conjecture:
 * given any positive natural number, you will always
eventually reach 1 if you follow the following formula: if the number is even, divide by 2, and if the
number is odd, multiply by 3 and add 1
 */
void collatzConjecture(int num) { //problem 5
    int loopCount = 0;
    int temp = num;
    while (temp != 1) {
        if (temp % 2 == 0) {
            temp = temp / 2;
        } else {
            temp = (3 * temp) + 1;
        }
        loopCount++;
    }
    cout << "Loops made: " << loopCount << endl;
}

/*
 *problem 6
 * prints all the leap years for the next 400 years
 * a leap year is a year divisible by 4 that isn't divisible by 100.
 * if the year is divisible by 100 it must not also be divisible by 400
 */
void leapYears(int year) { //Problem 6
    int nextLeapYear = 0;
    int nextYear = year + 1;
    for(nextYear;nextYear<=year+400;nextYear++) {
        if (nextYear%4 == 0){
            if (!(nextYear%100==0)){
                cout<<nextYear<<endl;
            } else{
                if (nextYear%400!=0){
                    cout<<nextYear<<endl;
                }
            }
        }
    }
    
}

/*
 *Problem 7
 * create a star with branches the length of an int value
 * in class it was specified that this int doesn't have to round to make it odd
 */
void xStar(int num){ //Problem 7
    if (num==1){
        cout<<"*"<<endl;
    } else{
    //num = (num%2!=0?num:num+1);
    int y=0;
    for (int x=num; x>1; x--){
        cout<<string(y,' ')<<"*"<<string(2*x-3,' ')<<"*"<<endl;
        y++;
    }
     cout<<string(y,' ')<<"*"<<endl;
     y--;
    for (int x=2; x<=num; x++){
        cout<<string(y,' ')<<"*"<<string(2*x-3,' ')<<"*"<<endl;
        y--;
    }
}
}

/*
 *Problem 8
 * CollatzConjecture between two values
 * this function checks to make sure the collatz conjecture is valid between two int values
 * if valid "Collatz Conjecture is still working" is printed
 */
void collatzConjectureBetweenValues(int num1,int num2) { //problem 8
    int loopCount = 0;
    int temp = 0;
    for (int x=num1; x<=num2;x++){
        temp = x;
        loopCount = 0;
                
    while (temp != 1) {
        if (temp % 2 == 0) {
            temp = temp / 2;
        } else {
            temp = (3 * temp) + 1;
        }
        loopCount++;
    }
    //cout << "Loops made: " << loopCount << endl;
}
    cout << "Collatz Conjecture is still working" << endl;
}

/*
 * Problem 9
 * evaluate whether or not an inputted value int
 * is a prime number (it has no factors other than 1 and itself)
 * uses the recursion
 */
bool isPrime_Recursive(int num, int oneless) { //problem 9
    if (oneless<=1){
        return true;
    } else{
        if (num%oneless==0){
            return false;
        } else{
            return isPrime_Recursive(num,oneless-1);
        }
        
    }
    
    
    
}

/* 
 *Problem 10
 *prints the multiplication facts for an integer from 1-12
 * uses recursion
 */
int multTables_Recursive(int num1, int start, int stop) { //problem 10

    if (start>stop){
        return stop;
    } else{
        cout<<num1<<"x"<<start<<"="<<num1*start<<endl;
        return multTables_Recursive(num1,start+1,stop);
    }
    
}

/*
 *problem 6
 * prints all the leap years for the next 400 years
 * a leap year is a year divisible by 4 that isn't divisible by 100.
 * if the year is divisible by 100 it must not also be divisible by 400
 * uses recursion
 */
int leapYears_Recursive(int year, int futureYears) { //Problem 11
    
    if (futureYears<0){
        return 0;
    } else{
        if (year%4 == 0){
            if (!(year%100==0)){
                cout<<year<<endl;
            } else{
                if (year%400!=0){
                    cout<<year<<endl;
                }
                
            }
            
    }
        return(leapYears_Recursive(year+1,futureYears-1));
    
}
}
