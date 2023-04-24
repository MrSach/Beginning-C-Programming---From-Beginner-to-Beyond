/*
	Program
		Character Randomiser - Secret Message
		
	Purpose
		Prompts text input from the user and outputs an encrypted character string.
		
	Author
		Sacha
	
	Date
		15.7.2021
		
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

int main()
{
	/*
		Prompt user for a line of text input.
	*/
	std::cout << "Please enter a secret message: ";
	std::string message {};
	std::getline(std::cin, message);
	std::cout << std::endl;
	
	/*
		Establish the character range using variables for the maximum and minimum.
		As ASCII characters have an integer numeric code, typecast from character literals to integers.
		Note that uppercase characters appear before lowercase ones in the ASCII table.
	*/
	std::size_t min_ASCII {0};
	min_ASCII = static_cast<int>('A');
	std::size_t max_ASCII {0};
	max_ASCII = static_cast<int>('z');
	
	/*
		Generate a two-dimensional vector of characters.
		For the first major vector, generate all the possible characters.
		This should be in the order, "A - Z", followed by "a - z".
		They are all added to element 0 in the main vector.
	*/
	std::vector<std::vector<char>> char_list { {}, {} };
	for (size_t i {min_ASCII}; i <= (min_ASCII + 25); ++i)
	{
		char_list.at(0).push_back(static_cast<char> (i));
	}
	for (size_t i {max_ASCII - 25}; i <= max_ASCII; ++i)
	{
		char_list.at(0).push_back(static_cast<char> (i));
	}

	/*
		Display alpha characters in order of subvector elements.
	*/
	std::cout << std::endl;
	std::cout << "Here is the alphabet and key mapping";
	std::cout << std::endl;

	for (auto item : char_list.at(0))
	{
		std::cout << item;
	}
	
	/*
		Generate random seed.
	*/
	std::srand (time(NULL));
	int random_value {0};

	/*
		Calculate a random number for each iteration.
		Check the index in the major vector's element 0 to find the character within the subvector.
		Also check if the character has already been added to element 1 of the major vector.
		Allocate an element in the major vector element 1 for each character in the major vector element 0.
		Remember that the major vector element 1 contains a shuffled list of entries from major element 0.
		Continue looping through until all characters have been mapped between the major vectors.
	*/
	for (size_t i {0}; i < 52; )
	{
		random_value = rand() % 52;
		char query_char {}; 
		query_char = char_list.at(0).at(random_value);
		bool char_mapped {0};
		for (size_t j {0}; j < char_list.at(1).size(); ++j)
		{
			if (query_char == char_list.at(1).at(j))
			{
				char_mapped = 1;
			}
		}
		if (char_mapped == 0)
		{
			char_list.at(1).push_back(query_char);
			++i;
		}
	}
	
	std::cout << std::endl;

	/*
		Output the list of characters from the randomised vector.
	*/
	for (auto item : char_list.at(1))
	{
		std::cout << item;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	
	/*
		Remind the user of their earlier input.
	*/
	std::cout << "You entered: ";
	std::cout << message;
	std::cout << std::endl;
	
	std::string encrypted_message {};

	/*
		Using the message, encrypt using the character from the same index in the randomised vector.
		Do this for each character in the message to generate an encrypted message.
	*/
	for (size_t i {0}; i < message.size(); ++i)
	{
		bool char_matched {0};
		char buffer_char {};
		for (size_t j {0}; j < char_list.at(0).size(); ++j)
		{
			if (message.at(i) == char_list.at(0).at(j))
			{
				encrypted_message+= char_list.at(1).at(j);
				char_matched = 1;
			}
		}
		if (char_matched == 0)
		{
			encrypted_message+= message.at(i);
		}
	}
	
	/*
		Display the encrypted message.
	*/
	std::cout << "Encrypted message: " << encrypted_message;
	
	std::cout << std::endl;
	
	/*
		Now create a string to store the decrypted message as proof of concept.
	*/
	std::string decrypted_message {};
	
	/*
		Perform the same function on the randomised vector, but using the index for the character in the randomised vector string to get the original character from the ordered string.
		Essentially this is the reverse of the encryption process.
	*/
	for (size_t i {0}; i < encrypted_message.size(); ++i)
	{
		bool char_matched {0};
		char buffer_char {};
		for (size_t j {0}; j < char_list.at(1).size(); ++j)
		{
			if (encrypted_message.at(i) == char_list.at(1).at(j))
			{
				decrypted_message+= char_list.at(0).at(j);
				char_matched = 1;
			}
		}
		if (char_matched == 0)
		{
			decrypted_message+= message.at(i);
		}
	}
	
	/*
		Display the decrypted message.
	*/
	std::cout << "Decrypted message: " << decrypted_message;
	std::cout << std::endl;
	std::cout << std::endl;
	
	return 0;
}
