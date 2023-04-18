#include "MyString.hpp"
#include <cstring>
#include <iostream>

/*
	Constructor - no arguments.
	Initialise "str" to nullptr, then allocate memory for a single character.
	Assign the value of a null character to the new memory location.
*/
MyString::MyString ()
:
	str {nullptr}
{
	this->str = new char [1];
	* (this->str) = '\0';
}

/*
	Constructor - character string argument.
	Initialise the "str" pointer to nullptr.
	Get the length of the string "rhs" passed through as a parameter.
	Add 1 to this length to make room for a trailing null character.
	Allocate memory to "str" with this character length.
	Use the C function strcpy to copy the character string.
*/
MyString::MyString (const char * rhs): str {nullptr}
{
	this->str = new char [std::strlen (rhs) + 1];
	std::strcpy (this->str, rhs);
}

/*
	Copy Constructor.
	Initialises "str" to nullptr.
	"str" from the source object to copy from is then used to calculate the size of memory to allocate for "str" in the new object.
	Add 1 to the size in order to accommodate the length of the string.
	Allocate this new size to "str" for the new object.
	Copy the rhs object's "str" value to the value for the new object's "str" value.
*/
MyString::MyString (const MyString & rhs): str {nullptr}
{
	this->str = new char [std::strlen (rhs.str) + 1];
	std::strcpy (this->str, rhs.str);
}

/*
	Destructor.
	As "str" is a character array, it is important to delete this.
*/
MyString::~MyString()
{
	delete [] str;
}

/*
	Get the length of the "str" member attribute.
*/
unsigned long int MyString::get_length () const
{
	return std::strlen (this->str);
}

/*
	Get the character string value of "str".
*/
char * MyString::get_string () const
{
	return this->str;
}

/*
	Member method.
	Displays the "str" character string, followed by the length of the value of "str".
*/
void MyString::display () const
{
	std::cout << this->get_string ();
	std::cout << ": ";
	std::cout << this->get_length ();
	std::cout << std::endl;
}
