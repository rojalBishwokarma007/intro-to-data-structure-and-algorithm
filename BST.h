/*Student Name: <ROJAL BISHWOKARMA>
Student NetID: <rb2298>
Compiler Used: <online GDB, C++>
Program Description:<This program allows the user to create a Binary Search tree with the characters that is the letters of a 
morse code in it. Along with it user can determine the depth of the tree for example the tree can be of depth 3 that is with
only three row. in addition the user is able to traverse the data in each node of the tree which inclue the int data as well as the 
morse character data for example 20 in the tree correspond to R. along with it the user is able to load the file with pre assign 
instuuction in it. In addition user is able to clear all the data from the node of the BST if he wishesh to. Finally the user
is able to convert a english word into morse code for example O correspond to --->*/



#include <iostream>
#include"node.h"
#pragma once
using namespace std;



 class BST{
public:
	BST()
	{
	    root = nullptr;
	}//constructor
	~BST()
	{
	  delet(root);  
	}//distructor

	void insert(int dat, char val);//to insert the data and the appropriate morse data
	void inorder();//function for inorder traversal of data and morse data
	void postorder();//function for postorder traversal of data and morse data
	void clear();//function to clear the data and morse data from the tree
	void delet();// function to delete the whole tree
	void preorder();// function for the preordertraversal of data and morse data
	bool search(int a);// function to search the data related to the morse data
	void findvalue(char i);//function that traverse the whole tree to find the data related to morse data


private:
	 void insert(int dat,char val, Node *node);//to insert the data and the appropriate morse code
    void inorder(Node *node);//function for inorder traversal of data and morse data
    void postorder(Node *node);//function for postorder traversal of data and morse data
    void clear(Node *node);//function to clear the data and morse data from the tree
    void delet(Node *node);// function to delete the whole tree
   void preorder(Node *node);// function for the preordertraversal of data and morse data
   void findvalue(char i,Node *node);// function to search the data related to the morse data
   bool search(int data,Node *node);//function that traverse the whole tree to find the data related to morse data
    Node *root;
};