// FizzBuzz game in a separate thread (say fizz if %3=0, buzz if %5=0, fizzbuzz if both, say number if none)

#include<iostream>
#include<thread>
#include<string>


void FizzBuzzGame()
{
	int turns = 30;
	std::string players[4]{"Abdul","Bart","Claudia","Divya"};
	for (int i = 1; i < turns; i++)
	{
		std::cout << players[(i-1) % 4] << " says ";
		if (i % 3 == 0 && i % 5 == 0)
			std::cout << "fizzbuzz!" << std::endl;
		else if (i % 3 == 0)
			std::cout << "fizz!" << std::endl;
		else if (i % 5 == 0)
			std::cout << "buzz!" << std::endl;
		else std::cout << i << std::endl;
	}
}

int main()
{
	std::thread thr(FizzBuzzGame);
	thr.join();
	return 0;

}