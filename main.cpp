 /*Student Name: <ROJAL BISHWOKARMA>
Student NetID: <rb2298>
Compiler Used: <online GDB, C++>
Program Description:<This program allows the user to create a Binary Search tree with the characters that is the letters of a 
morse code in it. Along with it user can determine the depth of the tree for example the tree can be of depth 3 that is with
only three row. in addition the user is able to traverse the data in each node of the tree which inclue the int data as well as the 
morse character data for example 20 in the tree correspond to R. along with it the user is able to load the file with pre assign 
instuuction in it. In addition user is able to clear all the data from the node of the BST if he wishesh to. Finally the user
is able to convert a english word into morse code for example O correspond to --->*/
 
 
 
 #include "Tokenizer.h"
#include <fstream>
#include "morse.h"
#include<cstring>
#include<cmath>
#include"BST.h"
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


bool processText(istream& is, bool interactive = true)
{
	// implement support for 
	// exit ... exit the program
	// add string string ... concatenate two strings
	// add double double ... sum two integers
	// load file ... loads a file containing supported commands
	string line;
	string command;
	string arg1, arg2;
	double darg1, darg2;
	int in1, in2;
	Morse mo;
	Tokenizer tkn;
	BST *tre = new BST();

	while (true)
	{
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		getline(is, line);
		tkn.setString(line);

		tkn.readWord(command);
		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}
		if (command == "load")
		{
			// load expects a filename .. so read one more word
			if (!tkn.readWord(arg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open())
			{
				status = processText(fin, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}
		
		if (command == "constructTree")
		{
			if (tkn.readInteger(in1))
			{
			    tre->delet();// this method is called to delete the previous tree every time the user creates a new tree
			    int depth = in1;// this is a algorithm given in the project question to construct the tree according to the depth.
				int arrCount= 0;
				for(int rowCount =0;rowCount<=depth;rowCount++)
				{
				    int rowElementCount = pow(2,rowCount);// this tells the the number of element in paticular row
				    int rowElement = pow(2,(depth - rowCount));// tells the value of each element
				    int rowElementCounter= pow(2,(depth - rowCount+1));//incriments the value based on the current level of tree
				    for (int j = 0;j<rowElementCount;j++,rowElement+=rowElementCounter)
				    {//this function helps to iterate through the row of element which is passed into insert method to create the tree
				        tre->insert(rowElement, mo.getValue(arrCount));// used to call the insert method which help to create the BST
				                                                       //and inserts the associated morse value in it as well
				        arrCount++;
				    }
				}
			}
		}
		if (command == "preOrderTraversal")
		{
		    tre->preorder();// inisiates the preorder method

		}
		if (command == "inOrderTraversal")
		{
		    tre->inorder();//initates inorder method
		}
		if (command == "postOrderTraversal")
		{
		    tre->postorder();// initates postorder method
		}
		if (command == "convertString")
		{
			if (tkn.readWord(arg1))
			{
			    string s = arg1;
 
                int n = s.length();// checks the length of the string
 
                char A[100];// a character type array
 
    
                strcpy(A, s.c_str());// this inserts the string into the array A
 
                for (int i = 0; i < n; i++)// this loops through the array and sends each letter through find function
                    tre->findvalue(A[i]);
                    
			}
		}
		if (command == "clear")// this initiates the clear method if the user wishes so.
		{
			tre->clear();
		}
    }


}


int main()
{

	processText(cin);
	return 0;

}