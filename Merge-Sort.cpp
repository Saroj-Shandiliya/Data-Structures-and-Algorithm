
//Merge Sort

#include<bits/stdc++.h>

using namespace std;

void merge(int *arr,int s,int e){
	int mid=(s+e)/2;
	
	int len1=mid-s+1;
	int len2=e-mid;
	
	int *first=new int[len1];
	int *second=new int[len2];
	
	//copy values
	int m=s;
	for(int i=0;i<len1;i++){
		first[i]=arr[m++];
	}
	
	m=mid+1;
	for(int i=0;i<len2;i++){
		second[i]=arr[m++];
	}
	
	int index1=0,index2=0;
	m=s;
	
	while(index1<len1 && index2<len2){
		if(first[index1]<second[index2]){
			arr[m++]=first[index1++];
		}else{
			arr[m++]=second[index2++];
		}
	}
	
	while(index1<len1){
		arr[m++]=first[index1++];
	}
	
	while(index2<len2){
		arr[m++]=second[index2++];
	}
	
}

void mergeSort(int *arr,int s,int e){
	
	if(s>=e){
		return ;
	}
	
	int mid=(s+e)/2;
	
	mergeSort(arr,s,mid);
	
	mergeSort(arr,mid+1,e);
	
	merge(arr,s,e);
}

int main(){
	int size=9;
	int arr[size]={9,6,4,7,8,2,3,1,5};
	
	mergeSort(arr,0,size-1);
	
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}
