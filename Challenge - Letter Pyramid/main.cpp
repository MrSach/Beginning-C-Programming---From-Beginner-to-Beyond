#include <iostream>
#include <string>

/*
 * 
 * Questions:
 * Which C++ loop(s) did you use and why?
 * 
 * I used the for loops because I wanted to maximise control and also have access to more comprehensive looping mechanisms
 * (for loops allow for complex initialisations, conditions and iterations).
 * For loops also make it easier to debug where there were issues.

How did you handle displaying the leading spaces in each row of the pyramid?
 * 
 * I used the std::getline and std::cin commands to get the line input by the user.
 * For loop used to initialise index i at 0.
 * Loop control is fixed to first character in order to ensure that i always points to first character in a dynamic string.
 * If statement is used to check for leading space.
 * If so, the leading space is then deleted using the std::string.erase(0, 1) method, where 0 is the index of the first character
 * in the string and 1 is the length of an ASCII character in a C++ string.
 * When the first non-space character is detected the loop will stop because of a break command.

Now that you completed the assignment, how might approach the problem differently if you had to solve it again?
 * 
 * I encountered a problem with the iterator for counting backwards because size_t becomes
 * a very large positive value when it falls below 0.
 * To overcome this I needed to debug the values of the size_t values used in the loops used
 * to decrement the index to print out the characters going back in the string.
 * I then found that I needed to add a condition to limit the index values to between 0 and the
 * size of the truncated string.
 * I am happy with the method that I used, so I would use a similar method should I repeat it as it
 * remains a relatively small program.
 * I may use using namespace std for readability, but not using this enhanced the accuracy for reading the
 * library function calls.
 * 
 * Please also note that I have not used the common command:
 * using namespace std
 * 
 * */
 
int main()
{
	//Request input from the user
	std::cout << "Enter a series of letters: ";
	std::string letters {};
	std::getline(std::cin, letters);
	
	//Feedback input to the user
	std::cout << "You entered: " << letters;
	std::cout << std::endl;
	
	//Check and eliminate leading spaces
	for (size_t i {0}; i < letters.size(); )
	{
		if (letters.at(0) == ' ')
		{
			letters.erase(0, 1);
		}
		else
		{
			break;
		}
	}
	
	//Output truncated string
	std::cout << "Truncated string is: " << letters;
	std::cout << std::endl;
	
	//Notify user about the letter pyramid
	std::cout << "Pyramid below: ";
	std::cout << std::endl;
	
	/*Loop through each character and then display all the letters up to and including the
	 * current character in the outer loop, then print them back out in reverse order,
	 * ensuring that the last character is only displayed once.
	 * */
	for (size_t i {0}; i < letters.size(); ++i)
	{
		for (size_t j {letters.size() - i}; (j >= 0) && (j <= letters.size()); --j)
		{
			std::cout << ' ';
		}
		for (size_t j {0}; j <= i; ++j)
		{
			std::cout << letters.at(j);
		}
		
		for (size_t j {i - 1}; (j >= 0) && (j < letters.size()); --j)
		{
			std::cout << letters.at(j);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}