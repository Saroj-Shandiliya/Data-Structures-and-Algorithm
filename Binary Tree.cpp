#include<bits/stdc++.h>
using namespace std;

class node{                                 //BluePrint of the tree node
  public:
  int data;
  node* left;
  node* right;
  
  node(int data){
      this->data=data;
      this->left=NULL;
      this->right=NULL;
  }
};

node* createTree(node* root){                   //Create tree
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data to the left of "<<root->data<<" :";
    root->left=createTree(root->left);
    
    cout<<"Enter data to the right of "<<root->data<<" :";
    root->right=createTree(root->right);
    
    return root;
}

void levelOrder(node* root){
    queue<node*> q;
    
    q.push(root);
    q.push(NULL);               //Seperator
    
    //Whenever we get a null we go to the next line
    
    while(!q.empty()){
        node* temp=q.front();
        
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void InOrder(node* root){
    if(root==NULL){                             //Base Case
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
    return;
}

void PreOrder(node* root){
    if(root==NULL){                             //Base Case
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

void PostOrder(node* root){
    if(root==NULL){                             //Base Case
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
    return;
}

void BuildFromLevel(node* root){
    queue<node*> q;
    cout<<"Enter Data for root:"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        cout<<"Enter data for left of "<<temp->data<<": ";
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        
        cout<<"Enter data for Right of "<<temp->data<<": ";
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

int findHeight(node* root){
    if(root==NULL){                             //Base Case
        return 0;
    }
    //Processing
    int left=findHeight(root->left);
    int right=findHeight(root->right);
    
    int ans=max(left,right)+1;
    return ans;                                 //Return
}

int diameter(node* root){                       //TC : O(N^2)
    if(root==NULL){
        return 0;
    }
    int opt1=diameter(root->left);
    int opt2=diameter(root->right);
    int opt3=findHeight(root->left) + 1 +findHeight(root->right);
    
    int ans=max(opt1,max(opt2,opt3));
    return ans;
}

pair<int,int> diameterHeight(node* root){                   //TC ; O(N)
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    
    pair<int,int> left=diameterHeight(root->left);
    pair<int,int> right=diameterHeight(root->right);
    
    int opt1=left.first;
    int opt2=right.first;
    int opt3=left.second + 1 + right.second;
    
    pair<int,int> ans;
    ans.first=max(opt1,max(opt2,opt3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}

int main(){
    //Binary Tree
    
    cout<<"\n Binary Tree \n";
    
    // Node: element of a tree is known as node
    // Root: the top most logical node which is the start of the tree
    // Children: any node which haas a parent node is known as child node
    // Sibling: any two or mode node whose parent is same
    // Ancenstor: take any node and start going to the top/root then all the nodes in the way is known as ancenstor
    // Descendant: from any node start going to the leaf node ( the last nodes from which no new node starts) all the nodes in the way are it's descendants
    
    // In a binary tree there are 0,1,2 nodes.
    // Every node contails two pointers one to point to the left and one to point to the right
    
    //Creation of binary tree
    
    // Data : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 18 19 -1 -1 -1
    
    node* root=NULL;
    root=createTree(root);
    
    //LevelOrder Traversal  also known as breadth first search
    //This is where we print the data level by level
    //we will be using queue to create levelOrder traversal
    
    cout<<"\n Level Order Traversal \n";
    levelOrder(root);
    
    //Homework reverse level order traversal
    
    //INorder   |   PreOrder    |   PostOrder           here N stands for Print
    //Inorder LNR first Left-> Node-> Right
    //Preorder NLR node-> left-> right
    //PostOrder LRN left-> right-> node
    
    
    cout<<"\nInOrder: \n";
    InOrder(root);
    
    cout<<"\nPreOrder: \n";
    PreOrder(root);
    
    cout<<"\nPostOrder: \n";
    PostOrder(root);
    
    //Build from level order
    //BuildFromLevel(root);
    
    //Binary tree Day 2 Questions
    
    //Find Height of a Binary tree
    //Height is basically the longest part between root to the leaf 
    
    //Expected Time Complexity: O(N)
    
    //Approach: Using recursion find max(right sub tree and left sub tree +1 
    //base case: if root==NULL return 0;
    cout<<"\nHeight of the tree : "<<findHeight(root);
    
    //Diameter of a Binary Tree
    //Longest path between any two end nodes
    
    //Approach: we can find diameter in three different ways
    //Option 1: Either it can be situated in left part of the tree
    //Option 2: It can be situated in the right part of the tree
    //Option 3: It can be situated in the combination of both right +left
    //height(root->left)+1+height(root->right)
    
    cout<<"\nDiameter of the tree : "<<diameter(root);
    
    //Approach 2: instead of calling the height function from the diameter function why not we return both height and diameter
    pair<int,int> p;
    p=diameterHeight(root);
    cout<<"\nDiameter of the tree : "<<p.first;
    
    
    
    return 0;
}
