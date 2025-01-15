// Create a simple thread
// This program will abort since main thread here executes before child thread (Thread1), so the destructor of thread will be called to kill off zombie thread (thread1) and program aborts. To avoid this, use join.

#include<iostream>
#include<thread>

void Thread1()
{
	std::cout << "Executing Thread 1"<<std::endl;
}

int main()
{
	std::thread th(Thread1);
	std::cout << "Executing Main Thread" << std::endl;
	return 0;
}