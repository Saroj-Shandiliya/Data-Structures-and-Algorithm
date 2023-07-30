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
		this->front=0;
		this->rear=0;
		arr=new int[size];
	}
	
	void enqueue(int data){
		if (rear<size){
			arr[rear]=data;
			rear++;
			return;
		}
		cout<<"Queue overflow!"<<endl;
	}
	
	bool empty(){
		if(rear==front){
			return true;
		}
		return false;
	}
	
	void dequeue(){
		if(empty()){
			cout<<"Queue Underflow"<<endl;
			return;
		}
		front++;
		if(empty()){
			front=0;
			rear=0;
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
