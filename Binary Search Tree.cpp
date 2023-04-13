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

void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp =q.front();
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

bool SearchBST(node* root,int srch){
    if(root==NULL){                         //base case
        return false;
    }
    if(root->data==srch){                   //base case
        return true;
    }
    bool ans;
    if(srch>root->data){
        ans=SearchBST(root->right,srch);
    }else {                                 //if(srch<root->data)
        ans=SearchBST(root->left,srch);
    }
    return ans;
}

bool SearchBSTiterative(node*root,int srch){
    node* temp=root;
    bool ans;
    while(temp!=NULL){
        if(temp->data==srch){
            ans=true;
        }
        if(srch>temp->data){
            temp=temp->right;
        }else {
            temp=temp->left;
        }
    }
    return ans;
}

node* minVal(node* root){       //To find the min values in the tree
    node* temp;
    temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* maxVal(node* root){       //To find the max values in the tree
    node* temp;
    temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node* deleteFromBST(node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 Child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        
        //1 Child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        
        //2 Child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
        
    }else if(root->data>val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

int main(){
    //Binary Saearch Tree
    cout<<"Binary Search Tree!!! \n";
    
    //The best part of binary search is that the time complexity to search is O(log n)
    //Binary Search tree there will be a root node the nodes on the left side will be smaller then the root node while the node on the right will be greated than the root node
    
    node* root=NULL;
    cout<<"Enter data to create BST: \n";
    // Data : 10 5 21 7 27 5 4 3 -1
    
    root = takeInput(root);
    
    cout<<"Level Order traversal!! \n";
    levelOrder(root);
    
    //Search In a BST:
    cout<<"\n"<<27<<" Exist in BST : "<<SearchBST(root,27)<<"\n";
    //in the normal recursive approach we have the time complexity as tha of O(logn) and for skewed tree (example where all data is either less than the root or greated than the root then in athat casre the TC is O(n))
    //The space complexityt is noit constant in the above approach to search that tis the recursion 
    //So to makethe time complexity constant we have to use an iterarive approah
    
    cout<<"\n"<<27<<" Exist in BST : "<<SearchBSTiterative(root,27)<<"\n";
    
    //inorder LNR prints always sorted
    
    cout<<"\nMax Value : "<<maxVal(root)<<"\n";
    cout<<"\nMin Value : "<<minVal(root)<<"\n";
    
    //Deletion in a binary tree
    //if the node to be deleted has 0 child simply delete the node
    //if one child then replace it with the node
    //if two child replace with its predecessor
    //or replace it with the node
    
    cout<<"\nDelete from a Binary Search Tree value : 27 \n"<<"\n";
    root=deleteFromBST(root,27);
    
    cout<<"Level Order traversal!! \n";
    levelOrder(root);
    
    return 0;
}

//Credits : Saroj Shandiliya
