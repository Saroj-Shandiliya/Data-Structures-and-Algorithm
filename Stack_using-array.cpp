//Implementation of stack using array

#include<bits/stdc++.h>
//#include<stack>;

using namespace std;

class Stack{
	//properties
	public:
		int *arr;
		int top;
		int size;
	
	//behaivour
	Stack(int size){
		this->size=size;
		arr=new int[size];
		this->top=-1;
	}
	
	void push(int ele){							//Pushes an element to the empty space in the stack
		if(top>=size-1){
			cout<<"Stack Full"<<endl;
			return;
		}
		
		top=top+1;
		arr[top]=ele;
		return;
	}
	
	void pop(){									//Removes the top element
		if(empty()){
			cout<<"Stack Empty"<<endl;
			return;
		}
		top--;
	}
	
	void peek(){								//Peeks element at the top
		if(empty()){
			cout<<"Stack Empty"<<endl;
			return;
		}
		cout<<arr[top]<<endl;
	}
	
	bool empty(){								//Checks if Stack is empty or not
		if(top>=0){
			return false;
		}
		return true;
	}
	
};

int main(){
	
	Stack st(6);								//Creation
	
	//Push
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	st.push(70);
	
	//Peek
	st.peek();
	
	//pop
	st.pop();
	
	st.peek();
	
	/*
	Time Complexity:
	push -> O(1)
	pop -> O(1)
	peek/top ->O(1)
	empty -> O(1)
	*/
	
	
	return 0;
}
