#include <iostream>
#include <queue>
using namespace std;


struct node
{
    node *left;
    int data;
    node *right;
};
node *newNode(int data){
    
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printLevelOrder(node *root){
    
    if(!root) return;
    node *temp;
    std::queue <node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(!temp){
            cout<<endl;
            if(!Q.empty()) Q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) Q.push(temp->left);
            if(temp->right) Q.push(temp->right);
            
        }
    }
}
 


int main() {
     node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    printLevelOrder(root);
	//code
	return 0;
}
