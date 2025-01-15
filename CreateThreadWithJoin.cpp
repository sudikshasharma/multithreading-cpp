// Create a simple thread, use join


#include<iostream>
#include<thread>

void Thread1()
{
	std::cout << "Executing Thread 1"<<std::endl;
}

int main()
{
	std::thread thr1(Thread1);
	std::cout << "Executing Main Thread" << std::endl;
	// Using join, the main thread will wait to finish till the child thread thr1 finish its execution
	thr1.join();
	return 0;
}