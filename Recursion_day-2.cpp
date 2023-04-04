#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
  int ans;
  if(n==0){                                    //Base Case
    return 0;
  }
  if(n==1){                                    //Base Case
    return 1;
  }
  ans=fibonacci(n-1)+fibonacci(n-2);          //Processing & recursiveness
  return ans;
}

int countStairs(int n){
    int ans;
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    ans=countStairs(n-1)+countStairs(n-2);
    return ans;
}

void sayDigits(int n,string arr[]){
    int digit;
    if(n==0){                                   //Base case
        return ;
    }
    //Processing
    digit=n%10;
    n=n/10;

    sayDigits(n,arr);                               //Recursion
    cout<<arr[digit]<<" ";
}

int main(){
    cout<<"Recursion Day: 2!!\n";


    cout<<"\n Fibonacci prob!! \n";
    //Fibonacci Problem
    //0 1 2 3 5 8 13 21 .......
    //create a function to print the fibonacci number of the nth term 

    //We all know that in fibonacci each terms is the sum of last two terms
    //f(n)=f(n-1)+f(n-2), where n is the nth term.
    //base case if(n==0) return 0; if(n==1) return 1;

    int n=8;              //OUTPUT should be 21
    cout<<n<<"th term in the Fibonacci series is: "<<fibonacci(n)<<"\n";

    cout<<"\n Distinct ways to reach to the top prob!! \n";
    //Count the number of distinct way can we climb the stairs
    //if we can either jump 2 stairs at a time or 1 stair at a time

    //Lets say you are at the top so u could have reached there by either jumping 
    //from the last(n-1) or secod last (n-2). So for any stair n we can device a function
    //f(n)=f(n-1)+f(n-2); where n is the nth stair

    //base Case    if(n<0) then return 0; if(n==0) then return 1; 
    
    n=5;               //OUTPUT should be 8
    cout<<"There are "<<countStairs(n)<<" distinct ways to reach to the "<<n<<"th stair.\n";

    cout<<"\n Say Digit 543 prob!! \n";
    //Say digits
    //input given a digit 412 output should be four one two

    //so all we have to do is to find the number by mod 10 and div 10
    //Base case if(n==0) return ; 

    string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    n=543;
    sayDigits(n,arr);

    return 0;
}

//Credits Saroj Shandiliya
