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

void Tokenizer::setString(const string& str)
{
	ss.str(str);
	ss.clear();
}
bool Tokenizer::isEmpty() const
{
	if (ss.eof()) return true;
	return false;
}
bool Tokenizer::readLine(string& line)
{
	if (isEmpty()) return false;
	if (getline(ss, line)) return true;
	return false;
}
bool Tokenizer::readInteger(int& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}
bool Tokenizer::readWord(string& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}
bool Tokenizer::readDouble(double& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}

bool Tokenizer::readChar(char& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}

void Tokenizer::rewind()
{
	ss.seekg(0, ss.beg);
}
void Tokenizer::clear()
{
	setString("");
	ss.setstate(std::ios::eofbit);
}