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
#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::stringstream;
using std::string;


class Tokenizer
{
private:
	stringstream ss;
public:
	Tokenizer() { ss.exceptions(std::ios::failbit); }
	Tokenizer(const string& source) { ss.str(source); ss.exceptions(std::ios::failbit); }

	void setString(const string& str);
	bool isEmpty() const;
	bool readLine(string& line);
	bool readInteger(int& val);
	bool readWord(string& val);
	bool readDouble(double& val);
	bool readChar(char& val);

	void rewind();
	void clear();
};