/*
	Pragma and block guards.
*/

#pragma once

#ifndef MY_STRING_HPP_DEEP_COPY_CONSTRUCTOR_EXAMPLE
	#define MY_STRING_HPP_DEEP_COPY_CONSTRUCTOR_EXAMPLE

class MyString
{
protected:
	/*
		Declare the character string.
	*/
	char * str;
public:
	MyString ();
	
	/*
		Copy Constructor
	*/
	MyString (const MyString & rhs);
	MyString (const char * rhs);
	~ MyString ();

	/*
		'Getter' and 'setter' member methods.
	*/
	long unsigned int get_length () const;
	char * get_string () const;
	void display () const;
};

#endif

