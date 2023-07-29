#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int arr[]={5,6,2,3,4,1};				//initalizing
	int size=6;
	
	for(int i=0;i<size-1;i++){
		
		//cout<<"Round "<<i+1<<endl;
		
		bool swapped=false;					//To optimize the solution 
		
		for(int j=0;j<size-i;j++){
			
			if(arr[j]>arr[j+1]){
				swapped=true;				//if swapped then true
				swap(arr[j],arr[j+1]);		//Swapping
			}
		
			/*for(int i=0;i<size;i++){
				cout<<arr[i]<<" ";
			}
		
			cout<<endl;*/
		}
		
		if(swapped==false){					//If no swap has occured then the array is already sorted no need of moving forward
			break;
		}
		
		//cout<<endl;
	}
	
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
	
	return 0;
}

/*
Time Complexity O(n^2)
		Best case : O(n)   If the array is already sorted

Space Complexity O(1)
*/
