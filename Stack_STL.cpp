#include<bits/stdc++.h>
//#include<stack>;

using namespace std;

int main(){
	
	//Stack using STL
	stack<int> s;
	
	//empty
	cout<<"Stack empty: "<<s.empty()<<endl;
	
	//push operation
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	
	//top opearation
	cout<<"Top element: "<<s.top()<<endl;
	
	//pop operation
	s.pop();
	
	//size 
	cout<<"Size of Stack: "<<s.size()<<endl;
	
	s.pop();						//POP opeariton
	
	cout<<"Size of Stack: "<<s.size()<<endl;
	
	return 0;
}
