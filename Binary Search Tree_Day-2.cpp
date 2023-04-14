#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    node* left;
    node* right;
    int data;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* &root,int data){
    if(root==NULL){                                 //Base Case
        root=new node(data);
        return root;
    }
    if(data>root->data){
        root->right=insertNode(root->right,data);
    }
    if(data<root->data){
        root->left=insertNode(root->left,data);
    }
    return root;
}

node* takeInput(node* root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertNode(root,data);
        cin>>data;
    }
    return root;
}

bool isBST(node* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right;
    }else{
        return false;
    }
}

int solve(node* root,int& i,int k){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left!= -1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,i,k);
}

pair<int,int> predeSuc(node* root,int key){
    node* temp=root;
    int pred=-1;
    int succ=-1;
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    
    node* leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    
    node* rightTree=temp->right;
    while(rightTree!=NULL){
        pred=rightTree->data;
        rightTree=rightTree->left;
    }
    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}

node* LCA(node* root,int a,int b){
    //base case
    if(root==NULL){
        return NULL;
    }
    /*                  //Iterative approach
    while(root!=NULL){
        if(root->data < a && root->data < b){
            root=root->right;
        }
        if(root->data > a && root->data > b){
            root=root->left;
        }else{
            return root;
        }
    }*/
    
    
    if(root->data < a && root->data < b){
        return LCA(root->right,a,b);
    }
    if(root->data > a && root->data > b){
        return LCA(root->left,a,b);
    }
    return root;
}

int main(){
    
    //Binary Search Tree Problem
    
    //Quetion 1: Validate BST
    //input a tree 
    //ther question here is that is it a proper binary search tree
    //For every node left subtree will be smaller then the root and the right will be greater
    //Approach 1
    //inorder traversal will always be a sorted respponse in a BST
    
    //Approach 2:
    //here the approach is if we check according to the range of ther tree like
    //for the left part of the tree the range will be from -infnity to the root value and for the right it will be the root value to +infnity 
    
    node* root=NULL;
    cout<<"Enter data to create BST: \n";
    // Data : 10 5 21 7 27 5 4 3 -1
    
    root = takeInput(root);
    
    cout<<"\n Checking is BST: "<<isBST(root,INT_MIN,INT_MAX);
    
    //Find kTh smallest and kth largest number in the BST
    //Approach: go for a Inorder traversal and then increment the value of k 
    //Once the kth value is reached you have the kth smallest element
    int i=0;
    int a=solve(root,i,3);
    cout<<"\n 3rd smallest number is : "<<a;
    //Approach 2: use morris traversal and complete the following code
    
    //We have to find inordere predecessor and successor
    //Predecesor: max element in the left sub tree
    //Succesoor : min element in the right sub tree
    
    //Approach we use inorder traversal and store the vallues in a data structure and then once all done we can then easily find the values
    //Approach 2:1> fint the node and then minVal and maxVal  
    
    pair<int,int> ans=predeSuc(root,5);
    cout<<"\nPredecessor : "<<ans.first;
    cout<<"\nSuccessor : "<<ans.second;
    
    //LCA in a BST
    //Lowest common ansestor
    node* lca=LCA(root,5,27);
    cout<<"\n LCA: "<<lca->data;
    return 0;
}

//Credits : Saroj Shandiliya
