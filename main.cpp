/*
Names: Angus Wai (100719558), Jason Lee (100698121), Jiminy Cao (100701335), Roderick “R.J.” Montague (100701758), Ulric Miller (100693403)
Date: 10/17/2018
References: Cplusplus.com - random_shuffle(http://www.cplusplus.com/reference/algorithm/random_shuffle/), Stackoverflow.com - "Is it possible to random shuffle an array of int elements" (https://stackoverflow.com/questions/14720134/is-it-possible-to-random-shuffle-an-array-of-int-elements)

*/

// GAME DEVELOPMENT WORKSHOP - PROJECT 2

#include <iostream>
#include <random>
#include <ctime>

const unsigned short int LEN(45);
static unsigned short int ary[LEN] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 7, 7, 7, 7, 8, 8, 8, 8, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13 }; // #13 is te sorry card

int cardGet();


int cardGet() // cardGet2 optimized
{
	static unsigned short int index;

	if (index == 0 ^ index >= 45) // shuffles the array only at the start, or once all values have been used
	{
		std::random_shuffle(std::begin(::ary), std::end(::ary)); // shuffles array from beginning to end.
		index = 0;
	}

	index++;
	return ::ary[index - 1]; // index is added to before being sent back, so index - 1 is used for what needs to be returned.
}

// int sorry()
int main()
{
	srand(time(0)); // seeding the randomizer.
	
	for (int i = 0; i < ::LEN; i++) // prints on extra character
	{
		std::cout << cardGet() << std::endl;
		if (i == 45)
			std::cout << "\n-----------------------" << std::endl;
	}
	

	system("pause");
	return 0;
	return 0;
}
