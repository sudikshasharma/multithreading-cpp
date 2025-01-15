// Multithreaded functions with arguments

#include<iostream>
#include<thread>
#include<string>



class threadClass
{
public:
	void MemberFunc()
	{
		std::cout << "Executing thread from class's member function" << std::endl;
	}
};

void FunctionOutside(int num)
{
	std::cout << "Executing thread for function with arguments...number = " << num << std::endl;
}

void FunctionWithRef(int &num)
{
	std::cout << "Executing thread with reference passed...number = " << num << std::endl;
	num = 10;
}

void MoveTheLvalue(int&& rval)
{
	std::cout << "Executing thread using move, converted lvalue to rvalue = " << rval << std::endl;
}

int main()
{
	int num1 = 3,num2=4, num3 = 5;
	threadClass thObj;
	// Thread with an argumented function as entry point
	std::thread thr1(FunctionOutside,num1);
	// moved lvalue as entrypoint
	std::thread thr2(MoveTheLvalue, std::move(num2));
	std::cout << "Checking moved lvalue = " << num2 << std::endl;
	// ref as entry point
	std::thread thr3(FunctionWithRef, std::ref(num3));
	std::cout << "Checking changed reference value = " << num3 << std::endl;
	// class's member function as entry point
	std::thread thr4(&threadClass::MemberFunc, &thObj);
	// lambda expression with arguments as entry point
	std::thread thr5([](int num4, int num5)
		{std::cout << "Numbers inside labda expression : " << num4 << " ," << num5 << std::endl; }, 6, 7);
	thr1.join();
	thr2.join();
	thr3.join();
	thr4.join();
	thr5.join();
	return 0;

}