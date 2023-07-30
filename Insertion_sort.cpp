//Insertion sort

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	//Insertion Sort
	//NO swap is done here we shift it here 
	
	
	int arr[]={10,1,7,4,8,2,11};
	int size=7,j,temp;
	
	for(int i=1;i<size;i++){
		
		temp=arr[i];
		
		for(j=i-1;j>=0;j--){
			
			//Shift
			if(arr[j]>temp){
				arr[j+1]=arr[j];
			}else{
				break;
			}
				
		}
		//Assigning to the right space 
		arr[j+1]=temp;
	}
	
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}

/*
Time Complexity: O(n^2)
	Best case: O(n)	if already sorted
	Worst case: O(n^2)
	
Space Complexity: O(1)
*/
