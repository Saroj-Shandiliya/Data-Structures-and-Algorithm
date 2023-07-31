#include<bits/stdc++.h>
//#include<array>
//#include<vector>
//#include<deque>

using namespace std;

int main(){


	//Arrray STL
	
	/*
	array<int,4> a={1,2,3,4};				//Declaration
	int size=a.size();						//size
	
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	
	cout<<"Element at 2 nd index:"<<a.at(2);
	cout<<"Empty or not: "<<q.empty()<<endl;
	
	//a.front();
	//a.back();
		
	cout<<endl;
	
	//Time Complexity: O(1)			For all operations
	
	*/
	
	//-----------------------------------------------------------------------------------------------------------------
	
	//Vector
	
	vector<int> v;
	
	vector<int> a(5,1);						//here the size is decalred as 5 and all the element are inatialiized as 1
	
	vector<int> j(a);						//we have copied a in j
	
	//for(int i:a){
	//	cout<<i<<" ";
	//}
	
	cout<<"Capacity: "<<v.capacity()<<endl;
	cout<<"Size: "<<v.size()<<endl;
	
	v.push_back(1);
	
	cout<<"Capacity: "<<v.capacity()<<endl;
	cout<<"Size: "<<v.size()<<endl;
	
	v.push_back(2);
	
	cout<<"Capacity: "<<v.capacity()<<endl;
	cout<<"Size: "<<v.size()<<endl;
	
	v.push_back(3);
	
	cout<<"Capacity: "<<v.capacity()<<endl;
	cout<<"Size: "<<v.size()<<endl;
	
	v.push_back(4);
	
	cout<<"Front: "<<v.front()<<endl;
	cout<<"Back: "<<v.back()<<endl;
	
	v.pop_back();						//Removes the last element
	
	cout<<endl<<endl<<endl;
	
	//Time Complexity: O(1)				For all operations
	
	//-----------------------------------------------------------------------------------------------------------------
	
	//DEC Double ended queue
	
	cout<<"Deque:"<<endl;
	
	deque<int> d;
	
	d.push_back(1);	
	d.push_front(2);
	
	cout<<"First index: "<<d.front()<<endl;
	cout<<"First index: "<<d.at(0)<<endl;
	
	cout<<"Empty or Not: "<<d.empty()<<endl;
	
	//d.pop_front();
	//d.pop_back();
	
	cout<<"Max Size: "<<d.max_size()<<endl;

	cout<<endl<<endl<<endl;
	
	//d.erase(d.begin,d.begin()+1);					//Erases data in the range
	
	//-----------------------------------------------------------------------------------------------------------------
	
	//List Doubly Linked list
	
	cout<<"List Doubly Linked list: "<<endl;
	
	list<int> l;
	
	//list<int> n(5,100);
	
	l.push_back(1);
	l.push_front(2);
	
	//l,pop_back();
	//l.pop_front();
	
	cout<<"Size: "<<l.size()<<endl;
	
	cout<<endl<<endl<<endl;
	
	//Time Complexity: O(1) for all operation apart fronm Erase for erase O(n)
	
	//-----------------------------------------------------------------------------------------------------------------
	
	//Priority Queue:
	
	cout<<"Priority Queue: "<<endl;
	
	priority_queue<int> maxi;					//Max heap
	
	priority_queue<int,vector<int>,greater<int> > mini;				//Min heap
	
	//Push
	maxi.push(1);
	maxi.push(2);
	maxi.push(3);
	maxi.push(4);
	maxi.push(5);
	
	mini.push(5);
	mini.push(4);
	mini.push(3);
	mini.push(2);
	mini.push(1);
	
	int size=maxi.size();
	cout<<"Size :"<<size<<endl;
	
	for(int i=0;i<size;i++){
		cout<<maxi.top()<<" ";
		maxi.pop();
	}
	cout<<endl;
	
	for(int i=0;i<size;i++){
		cout<<mini.top()<<" ";
		mini.pop();
	}
	cout<<endl;
	
	cout<<endl<<endl<<endl;
	
	
	//-----------------------------------------------------------------------------------------------------------------
	
	//Set
	
	cout<<"Set: "<<endl;
	
	set<int> s;
	
	//insert data
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(0);
	
	//for(auto i : s){
	//	cout<<i<<" ";
	//}
	//cout<<endl;
	
	cout<<"Is 5 present: "<<s.count(5)<<endl;
	
	set<int>::iterator itr=s.find(5);
	
	cout<<"Value present at itr->"<<*itr<<endl;
	
	//Time Complexity: O(log n) for insert count find erase and others are O(1) 
	
	cout<<endl<<endl<<endl;
	
	//-----------------------------------------------------------------------------------------------------------------
	
	//Map
	
	cout<<"Map:"<<endl;
	
	map<int,string> m;
	
	//insertion
	m[1]="tom";
	m[3]="jerry";
	m[2]="Oggy";
	
	m.insert({5,"ferb"});
	
	cout<<"Finding 5 : "<<m.count(5)<<endl;
	
	//auto it=m.find(5);
	
	//cout<<(*it).first<<" -> "<<(*it).second<<endl;
	
	//m.erase(5);
	
	
	//Time Complexity: In case of map it is O(log n) as things are stored in sorted manner
	// But for unordered map it it O(1)
		
	return 0;
}
