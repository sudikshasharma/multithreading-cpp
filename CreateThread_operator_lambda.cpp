// Create a simple thread with callable objects and lambda expression


#include<iostream>
#include<thread>


// The operator() is a special operator in C++ that makes an object behave like a function when called with parentheses ()
// Object of such class are funktor and call operator() automatically
class ThreadClass
{
public:
	void operator()()
	{
		std::cout << "Executing class member function" << std::endl;
	}
};

int main()
{
	ThreadClass th_obj;
	std::thread thr1(th_obj);
	std::thread thr2([]() {std::cout<<"Executing thread from lambda expression" << std::endl; });
	std::cout << "Executing Main Thread" << std::endl;
	// Using join, the main thread will wait to finish till the child thread thr1 and thr2 finish their execution
	thr1.join();
	thr2.join();
	return 0;
}