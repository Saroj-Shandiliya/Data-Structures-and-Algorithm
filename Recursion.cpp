    //Recursion
    //What??
    //when a function calls itself directly or indirectly
    //if u have a big problem and depends on a small problem then we can use recursion
    
    //example if we have to fing 2^n then the logcic is 2 is to be multiplied n times or 2*(2^n-1) where n!=0 (Base Case)
    //Recursive relation 
    
    //Factorial (if 5! then 5*4*3*2*1)
    //in this we can use recursive approach as we can call a function until it reaches a point where n*(n-1)! where n!=0 (Base Case)
    //the point u want the function to stop the function calling itself or recursion to stop is known as base case
    //So now we need a base case and a recurrance relation
    
    //In base case we need to return

    // Why is base case mandatory??
    // Lets say that there is no base case in factorial function then the function will be calling itself
    //for 5,4,3,2,1,0,-1,-2,-3,-4,-5,......... and there will reach a moment where the function stack
    //will overflow in that case there will be a segmentation fault.

    //Recursion tree
    //  4->3->2->1->0           --  Function call
    // 24<-6<-2<-1<-1           --  Return

    //Recursion Function Structure
    // Function(parameter){
    //     Base Case;
    //     Processing;
    //     Recurrance relation;
    // }

    //In whichever function if the recurrance relation is at the end or after Processing
    //then it is a tail recursion, if it is before processing then it is a head recursion


#include <bits/stdc++.h>
using namespace std;

int factorial(int num){
    int ans;
    if(num==0){                 //Base Case
        return 1;
    }else{
        ans=num*factorial(num-1);
    }
    return ans;
}

int toPower(int num,int power){
    int ans;
    if (power==0){              //Base Case
        return 1;
    }else{
        ans=num*toPower(num,power-1);
    }
    return ans;
}

void PrintCountTail(int num){
    if(num==0){                 //Base Case
        return;
    }
    cout<<num<<" ";             //Processing
    PrintCountTail(num-1);      //Tail Recursion
}

void PrintCountHead(int num){
    if(num==0){                 //Base Case
        return;
    }
    PrintCountHead(num-1);      //Head Recursion
    cout<<num<<" ";             //Processing
}

int main() {
    cout << "Recursion!"<<endl;
    

    //Print Counting            [EXAMPLE of Tail recursion]
    //input n=5
    //output : 5 4 3 2 1
    cout<<"Print Count!!"<<endl<<"Tail : ";
    PrintCountTail(5);

    //input n=5                 [EXAMPLE of Head recursion]
    //output : 1 2 3 4 5
    cout<<endl<<"Head : ";
    PrintCountHead(5);

    //factorial 
    cout<<endl<<"5! = "<<factorial(5)<<endl;
    
    //Power of any number
    cout<<"2^4 = "<<toPower(2,4)<<endl;
    cout<<"3^3 = "<<toPower(3,3)<<endl;
    
    return 0;
}

//Credits    Saroj Shandiliya
