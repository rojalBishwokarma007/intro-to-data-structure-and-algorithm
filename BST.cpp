/*Student Name: <ROJAL BISHWOKARMA>
Student NetID: <rb2298>
Compiler Used: <online GDB, C++>
Program Description:<This program allows the user to create a Binary Search tree with the characters that is the letters of a 
morse code in it. Along with it user can determine the depth of the tree for example the tree can be of depth 3 that is with
only three row. in addition the user is able to traverse the data in each node of the tree which inclue the int data as well as the 
morse character data for example 20 in the tree correspond to R. along with it the user is able to load the file with pre assign 
instuuction in it. In addition user is able to clear all the data from the node of the BST if he wishesh to. Finally the user
is able to convert a english word into morse code for example O correspond to --->*/


#include<iostream>
#include"BST.h"
using namespace std;

void BST::insert(int dat, char val){//this method insert the data and morse data into the tree
	if(root != nullptr){
		insert(dat,val, root);
	}else{
		root = new Node;
		root->data = dat;
		root->mors = val;
		root->left = root->right = nullptr;
		
	}
}

void BST::insert(int dat, char val, Node *node){//this method insert the data and morse data into the tree

	if(dat< node->data){
		if(node->left != nullptr){
			insert(dat, val, node->left);
		}else{
			node->left = new Node;
			node->left->data = dat;
			node->left->mors = val;//puting the morse value into the node
			node->left->left=node->left->right = nullptr;
		  
		}
	}else if(dat >= node->data){
		if(node->right != nullptr){
			insert(dat,val, node->right);
		}else{
			node->right = new Node;
			node->right->data = dat;
			node->right->mors = val;// puting the morse value into the node
			node->right->right = node->right->left = nullptr;
			 
		}
	}

}

void BST::inorder(){//prints the inorder traversal of morse as well as tree data from the node
	inorder(root);
	cout<<"\n";
}

void BST::inorder(Node *node){//prints the inorder traversal of morse data as well as tree data from the node
	if(node != nullptr){
		inorder(node->left);
		cout << node->data << " ";
		cout<<"["<<node->mors<<"]"<<", ";
		inorder(node->right);
	}
}
void BST::clear(){// this clears the contents of each node in the tree was little bit confused to put method or delete method
                  // to clear the data of the tree used this insted to clear all the data
	clear(root);
}

void BST::clear(Node *node){// this helps to clear all the data from the node ot the tree
	if(node != nullptr){
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

void BST:: delet()// deletes the whole tree by deleting the root node
{
    delet(root);
}

void BST::delet(Node *node)//deleats the whole tree by deleting the root node
{
    delete root;
}

void BST::preorder(){//prints the preorder traversal of morse as well as tree data from the node
	preorder(root);
	cout << "\n";
}

void BST::preorder(Node *node){//prints the preorder traversal of morse as well as tree data from the node
	if(node != nullptr){
		cout << node->data << " ";
		cout<<"["<<node->mors<<"]"<<", ";
		preorder(node->left);
		preorder(node->right);
	}
}
void BST::postorder(){//prints the postorder traversal of morse as well as tree data from the node
	postorder(root);
	cout << "\n";
}


void BST::postorder(Node *node){//prints the postorder traversal of morse as well as tree data from the node
	if(node != nullptr){
		postorder(node->left);
		postorder(node->right);
		cout << node->data << " ";
		cout<<"["<<node->mors<<"]"<<", ";
	}
}

void BST::findvalue(char i){//helps to find the data associated with the morse value like R = 20 and much more
	findvalue(i,root);
	cout << "\n";
}

void BST::findvalue(char i, Node *node){//helps to find the data associated with the morse value like R = 20 and much more with the 
                                        //help of the inorder traversal
    	if(node != nullptr){
		findvalue(i,node->left);
		if (node->mors == i)//if the traversed morse data in the node is equal to user input data
		{
		    int b = node->data;
		    cout<<i;
		    search (b);//it inisiates the search of the letter that the user entered so that it can find the morse code
		    
		}
		findvalue(i, node->right);
	}

}

bool BST ::search(int a)//search for the value to find the morse code
{
    search(a,root);
    return true;
}

bool BST::search(int a , Node* node)// search for the user input character which is a letter and prints morse code accordingly
{
    while(node!=nullptr)
    {
        if(a>node->data)
        {
            node=node->right;// if the data is to the right print "-"
            cout<<"-";
        }
        else if (a<node->data)// if the data is to the left print "."
        {
            node=node->left;
            cout<<".";
        }
        else if (a == node->data)// if the data is found return true
        {
            return true;
        }
        
    }
    return true;
}



