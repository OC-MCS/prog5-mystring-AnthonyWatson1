// test driver code goes here

#include <iomanip>
#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

int main()
{
	//I use cout so I could see the where bugs would be occuring
	MyString s1;
	s1 = "hello";//Assigning values to each constructor
	MyString s2;
	s2 = "world";
	MyString s3(s1);//Sending value to copy constructor
	cout << s3;
	s1 = s2 = s3;//Testing assignment operator
	cout << s1;
	cout << s2;
	cout << s3;
	s1.swap(s2); //Testing the swap
	cout << s1;
	s1.empty();//Testing if the string is empty
	cout << s1;
	s1.nlength();
	cout << s1;
	s3 = s1 + s2;//Tsting the addition operator and equal operator
	cout << s3;
	s1 == s2; //testing caomparison to see if its the same
	cout << s1 << s2;
	s1 >> s3;//Testing input operator
	s2 << s1;//Testing output operator

	
	return 0;

}