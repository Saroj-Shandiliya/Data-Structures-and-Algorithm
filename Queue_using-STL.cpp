#include<bits/stdc++.h>
//#include<queue>

using namespace std;

int main(){
	
	//Queue Implementation using STL
	queue<int> q;						//Declaration
	
	//Empty
	cout<<"Is queue Empty:"<<q.empty()<<endl;
	cout<<"Size: "<<q.size()<<endl;
	
	//Enqueue
	q.push(10);
	
	cout<<"Size: "<<q.size()<<endl;
	
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);	
	
	//front element
	cout<<"Front: "<<q.front()<<endl;
	cout<<"Size: "<<q.size()<<endl;
	
	//dequeue
	q.pop();
	
	//front element
	cout<<"Front: "<<q.front()<<endl;
	cout<<"Size: "<<q.size()<<endl;
	
	//Empty
	cout<<"Is queue Empty:"<<q.empty()<<endl;
	
	return 0;
}

/*
Time Complexity: O(1) all Functions
*/
