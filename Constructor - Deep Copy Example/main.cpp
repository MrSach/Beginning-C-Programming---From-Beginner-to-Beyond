#include <iostream>
#include "MyString.hpp"

int main (int argc, char ** argv)
{
	std::cout << "Copy Constructors - Deep Copy Example";
	std::cout << std::endl;
	std::cout << std::endl;

	/*
		Initailise a "MyString" instance with default arguments.
	*/
	MyString a;
	
	/*
		Initialise a "MyString" instance with a character string argument.
	*/
	MyString b {"Hello"};

	/*
		Initialise a "MyString" instance using the Copy Constructor.
		Pass in "MyString" "b".
	*/
	MyString c {b};

	/*
		Display the contents of "MyString" instances "a", "b" and "c".
		"a" Should display the default empty string with a size of 0.
		"b" should display the string "Hello" with a length of 5.
		"c" should also display "Hello" with a length of 5.
	*/
	a.display ();
	b.display ();
	c.display ();

	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
