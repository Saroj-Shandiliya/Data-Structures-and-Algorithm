//Selection Sort

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int arr[]={5,6,2,3,4,1};				//initalizing
	int size=6;
	int min;								//To keep track of minimum element
	
	for(int i=0;i<size-1;i++){
		min=i;								//Keeping track of min index
		for(int j=i;j<size;j++){
			if(arr[j]<arr[min]){			//finding the minimum 
				min=j;
			}
		}
		
		//Swapping the values of the i th index with the min
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
	
}

/*
Time Complexity: O(n^2)
		Best case: O(n^2)
		Worst case: O(n^2)


Space Complexity: O(1)
no extra space is needed

Use Case:
1. When the size of the arr,vector is small then we can use selection sort
*/
