# include "MyString.h"
# include <iostream>
# include <cstring>

using namespace std;

/*temp = is a temporary variable*/

MyString::MyString()
{
	length = 1;
	string = new char[length];
	string[length - 1] = '\0';
}

MyString::MyString(const char *input)
{
	length = strlen(input) + 1;
	string = new char[length];
	for (int i = 0; i < (length - 1); i++)
	{
		string[i] = input[i];
	}
	string[(length - 1)] = NULL;
}

MyString::MyString(const MyString& S)
{
	length = S.nlength;
	string = new char[length];
	for (int i = 0; i < (length - 1); i++)
	{
		string[i] = S.string[i];
	}

	if (string[length - 1] != '\0') 
	{ string[length - 1] = '\0'; }
}

MyString::~MyString()
{
	delete[] string;
}


int MyString::nlength()
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

char& MyString::at(int place)
{
	return string[place - 1];
}

bool MyString::empty()
{
	if (string[0] == NULL && length == 1) 
	{ return true; }
	else 
	{ return false; }
}

void MyString::swap(MyString &from)
{
	int lengtha = length; int lengthb = from.length;
	char *temp1 = new char[lengtha];
	char *temp2 = new char[lengthb];

	for (int i = 0; i < (lengtha - 1); i++)
	{
		temp1[i] = string[i];
	}
	if (temp1[lengtha - 1] != '\0') { temp1[lengtha - 1] = '\0'; }

	for (int j = 0; j < (lengthb - 1); j++)
	{
		temp2[j] = from.string[j];
	}
	if (temp2[lengthb - 1] != '\0') { temp2[lengthb - 1] = '\0'; }

	delete[] string; 
	delete[]from.string;

	string = new char[lengthb];
	length = lengthb;
	from.string = new char[lengtha];
	from.length = lengtha;

	for (int k = 0; k < (lengthb - 1); k++)
	{
		string[k] = temp2[k];
	}
	if (string[lengthb - 1] != '\0') 
	{ string[lengthb - 1] = '\0'; }

	for (int l = 0; l < (lengtha - 1); l++)
	{
		from.string[l] = temp1[l];
	}
	if (from.string[lengtha - 1] != '\0') 
	{ from.string[lengtha - 1] = '\0'; }

	delete[]temp1;
	delete[]temp2;
}


MyString MyString::substr(int index, int length)
{
	short size = length + 1;
	char* temp = new char[size];
	int j = 0;
	for (int i = index, j = 0; i < length; i++, j++)
	{
		temp[j] = string[i];
	}
	if (temp[size - 1] != '\0') { temp[size - 1] = '\0'; }


	MyString SUB;
	SUB.length = size;
	delete[]SUB.string;
	SUB.string = new char[size];
	for (short m = 0; m < (size - 1); m++)
	{
		SUB.string[m] = temp[m];
	}

	if (SUB.string[size - 1] != '\0') 
	{ SUB.string[size - 1] = '\0'; }
	return SUB;
	delete[]temp;
}



bool operator == (const MyString & S1, const MyString & S2)
{
	if (S1.length == S2.length)
	{
		short counter1 = S1.length;
		int counter2 = 0;
		int i = 0;
		while (i != counter1)
		{
			if (S1.string[i] != S2.string[i]) { counter2++; }
			i++;
		}
		cout << i << " " << counter2 << endl;
		if (counter2 != 0) { return false; }
		else { return true; }
	}
	else { return false; }

}

ostream& operator <<(ostream & OS, const MyString& S)
{
	OS << S;
	return OS;
}

istream& operator >>(istream & IS, MyString& S)
{
	char* input = new char[100];
	IS.getline(input, 100);

	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	S.nlength = i + 1;
	delete[]S.substr;
	S.substr = new char[(i + 1)];
	for (int j = 0; j < (i); j++)
	{
		S.substr[j] = input[j];
	}
	S.substr[i] = '\0';
	delete[]input;
	return IS;
}

MyString& MyString::operator =(const MyString &S)
{
	length = S.length;
	delete[] string;
	string = new char[length];
	for (int i = 0; i < (length - 1); i++)
	{
		string[i] = S.string[i];
	}
	string[(length - 1)] = '\0';
	return *this;
}

MyString operator + (const MyString& S1, const MyString & S2)
{
	int size = (S1.nlength - 1) + (S2.nlength - 1) + 1;
	char * temp = new char[size];
	for (int i = 0; i < (S1.nlength - 1); i++)
	{
		temp[i] = S1.string[i];
	}

	int j = 0;
	for (short k = S1.nlength - 1, j = 0; k < (size - 1); k++, j++)
	{
		temp[k] = S2.string[j];
	}

	if (temp[size - 1] != '\0') { temp[size - 1] = '\0'; }

	MyString S3(temp);
	delete[] temp;
	return S3;
}