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
    
    // Data : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 18 -1 -1
    
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
    BuildFromLevel(root);
    
    return 0;
}
