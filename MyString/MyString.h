#pragma once
// MyString class declaration goes here

#include <iomanip>
#include <iostream>
#include <cstring>


class MyString
{
private:
	char* string;
	int length;
public:
	MyString();//default constructor
	MyString(const char* input);//Takes in a string and creates an object
	MyString(const MyString & S);//Copy constructor
	~MyString();//Destructor deletes the nstring at the end


	int nlength();//displays length of string excluding null
	char& at(int place);// returns a chracter at specified loc-1
	bool empty();// if string is empty returns true else it returns false
	void swap(MyString& from);// swaps the contents of two strings
	MyString substr(int index, int length);// returns an object which is the substring of the object that calls it


	friend ostream& operator << (ostream & OS, const MyString &S);// out stream displays the string
	friend istream& operator >> (istream & IS, MyString &S);//instream takes in a string and creates and object
	MyString& operator = (const MyString& S);//if A and B are object B is "neil", the A =B therefore A is "neil"
	friend  bool operator ==(const MyString& S1, const MyString & S2);// checks if both strings are equal
	friend MyString operator + (const MyString& S1, const MyString & S2);//still buggy


};