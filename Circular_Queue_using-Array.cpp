//Circular Queue

#include<bits/stdc++.h>
using namespace std;

class Queue{
	//declaration
	public:
	int front;
	int rear;
	int* arr;
	int size;
	
	//Properties
	Queue(){
		this->size=100;
		this->front=-1;
		this->rear=-1;
		arr=new int[size];
	}
	
	void enqueue(int data){
		
		if((front==0 && rear==size-1)||(rear==(front-1)%(size-1))){
			cout<<"Queue Overflow!"<<endl;
			return;
		}else if(front==-1){
			front=rear=0;
			arr[rear]=data;
			return;
		}else if(rear==size-1&&front!=0){
			rear=0;
			arr[rear]=data;
			return;
		}else{
			rear++;
			arr[rear]=data;
		}
		
	}
	
	bool empty(){
		if(front==-1){
			return true;
		}
		return false;
	}
	
	void dequeue(){
		
		if(empty()){
			cout<<"Queue underflow"<<endl;
		}else if(rear=front){					//Single element
			front=rear=-1;
		}else if(front==size-1){				//To maintain cyclic nature
			front=0;
		}else{
			front++;
		}
	}
	
	int top(){
		if(empty()){
			cout<<"Queue Underflow"<<endl;
			return -1;
		}
		return arr[front];	
	}
	
};

int main(){
	
	Queue q;
	
	cout<<"Is Empty: "<<q.empty()<<endl;
	
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.enqueue(70);
	q.enqueue(80);
	
	cout<<"Is Empty: "<<q.empty()<<endl;
	
	cout<<"Front: "<<q.top()<<endl;
	
	q.dequeue();
	
	cout<<"Front: "<<q.top()<<endl;
	
	return 0;
}

/*
Time Complexity: O(1) all Functions
*/
