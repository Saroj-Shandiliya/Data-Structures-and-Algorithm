#include<bits/stdc++.h>
using namespace std;

/*
//Top Down approach (Recursive and Memonizaton)
//Time Complexity O(n)
//Space Complexity O(n)
int fibo(int n,int dp[]){
    if(n==0||n==1){                 //base case
        return n;
    }
    if(dp[n]!=-1){                  //Checking if the sub problem already has a solution
        return dp[n];
    }
    dp[n]=fibo(n-1,dp)+fibo(n+1,dp);         //Memonization
    return dp[n];
}
*/

//Bottom UP approach
//Time Complexity O(n)
//Space Complexity O(n)
int fiboBot(int n){
    int dp[n+1];
    //Base case
    dp[0]=0;
    dp[1]=1;
    
    //Itterative Approach
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
        //cout<<dp[i-1]<<" + "<<dp[i-2]<<"\n";
    }
    return dp[n];
}

//Space Optimized approach
//Time Complexity: O(n)
//Space Complexity: O(1)
int fiboSpace(int n){
    int prev1=1,prev0=0;
    int curr;
    
    if(n==0||n==1){
        return n;
    }
    
    for(int i=2;i<=n;i++){
        curr=prev1+prev0;
        prev0=prev1;
        prev1=curr;
    }
    return curr;
}

int main(){
    
    cout<<"Fibonacci Serieds Using Dynamic programming !! \n";
    cout<<"Top Down Approach!! (Recursion + Memonization) \n";
    
    int n;
    int dp[n+1];                      //For storing the sub problem's solution
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    
    cout<<"Enter a number: ";
    cin>>n;
    
    //Top Down Approach 
    //cout<<fibo(n,dp)<<"\n";
    
    //Bottom Up approach
    cout<<"Bottom's up Approach!! (Tabulation) \n";
    cout<<fiboBot(n)<<"\n";
    
    //Space Optimized approach
    cout<<"Space Optimized \n";
    cout<<fiboSpace(n)<<"\n";
    return 0;
}

