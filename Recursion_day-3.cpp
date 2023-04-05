#include<bits/stdc++.h>
using namespace std;

bool checkSorted(int arr[],int size){
    bool ans;
    if(size==0||size==1){                       //Base Case
        return true;
    }
    if(arr[0]>arr[1]){                          //Processing
        return false;
    }else{
        ans=checkSorted(arr+1,size-1);          //Recursion
    }
    return ans;                                 //return
}

//int getSum(int arr[],int size){
    
//}

bool linearSearch(int arr[],int size,int elmnt){
    bool ans;
    if(size==0){                                 //Base Case
        return false;
    }
    if(arr[0]==elmnt){                          //Processing
        return true;
    }
    ans=linearSearch(arr+1,size-1,elmnt);       //Recursion
    return ans;                                 //Return
}

bool binarySearch(int arr[],int low,int high,int elmnt){
    bool ans;

    //base case
    if(high<low){
        return false;
    }

    //processing
    int mid=(low+((high-low)/2));
    
    if(arr[mid]==elmnt){
        return true;
    }else if(arr[mid]>elmnt){
        ans=binarySearch(arr,low,mid-1,elmnt);      //Recursion
    }else{
        ans=binarySearch(arr,mid+1,high,elmnt);     //Recursion
    }
    return ans;                                     //Return
}

int main(){
    cout<<"Recursion Day: 3!!"<<endl;

    //Biinary Search Using Recursion
    
    //Que:1 we have an array and we have some values in it we have to create a function so that we can know if the array is sorted or not.
    //if sorted then return true else false
    //Basic approach if the first number is smaller than the second and then on so the array is sorted

    //We have to solve the following problem using Recursion

    //Base Case : (if an array has 1 ele then sorted or if 0)
    //if size==0,size==1 then sorted,
    //if (arr[0]>arr[1]) then return false else bool ans=checkSorted(arr+1,size-1)

    int arr[]={0,1,2,3,4,5,6,7,8,9};
    int size=10;

    cout<<"Is the Array Sorted (Using Recursion) : "<<checkSorted(arr,size)<<endl;

    //Home work input an array output should be sum of the array using recursion

    //Linear Search using Recursion

    cout<<"Element found using Linear Search : "<<linearSearch(arr,size,9)<<endl;

    //Binary Search using Recursion

    cout<<"Element Found usnig Binary Search : "<<binarySearch(arr,0,size-1,15)<<endl;


    return 0;
}

//Credits Saroj Shandiliya
