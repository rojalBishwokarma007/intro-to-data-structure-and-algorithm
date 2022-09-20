 /*Student Name: <ROJAL BISHWOKARMA>
Student NetID: <rb2298>
Compiler Used: <online GDB, C++>
Program Description:<This program allows the user to create a Binary Search tree with the characters that is the letters of a 
morse code in it. Along with it user can determine the depth of the tree for example the tree can be of depth 3 that is with
only three row. in addition the user is able to traverse the data in each node of the tree which inclue the int data as well as the 
morse character data for example 20 in the tree correspond to R. along with it the user is able to load the file with pre assign 
instuuction in it. In addition user is able to clear all the data from the node of the BST if he wishesh to. Finally the user
is able to convert a english word into morse code for example O correspond to --->*/

#pragma once

class Morse{// a morse class that contains all the character value that is to be converted to morse code when user enters it

private:
	char morseTree[64] = 
	{
		'\0',
		// 2nd Row
		'E',
		'T',
		// 3rd Row
		'I', 'A',
		'N', 'M',
		// 4th Row
		'S', 'U', 'R', 'W',
		'D', 'K', 'G', 'O',
		// 5th Row
		'H', 'V', 'F', '\0', 'L', '\0', 'P', 'J',
		'B', 'X', 'C', 'Y', 'Z', 'Q', '\0', '\0',
		// 6th Row
		'5', '4', '\0', '3', '\0', '\0', '\0', '2', '\0', '\0', '+', '\0', '\0', '\0', '\0', '1',
		'6', '=', '/', '\0', '\0', '\0', '\0', '\0', '7', '\0', '\0', '\0', '8', '\0', '9', '0'
	};
	public:
	char getValue(int j){//get function that returns each letter from the morseTree array according to the location.
	    int val;
	    val = morseTree[j];
	    return val;// returns the character value accordingly.
	}
};