#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char **)
{
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

	std::cout << "------------------ TEST1 ------------------" << std::endl;
	{
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			a[i] = i;
		}
		Array<int> b(a);
		b[0] = 42;
		for (unsigned int i = 0; i < b.size(); i++)
		{
			std::cout << "a[" << i << "]: " << a[i] << "\t\t";
			std::cout << "b[" << i << "]: " << b[i] << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "------------------ TEST2 ------------------" << std::endl;
	{
		Array<char> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			a[i] = i + 65;
		}
		Array<char> b(10);
		for (unsigned int i = 0; i < b.size(); i++)
		{
			b[i] = i + 97;
		}
		std::cout << "BEFORE ASSIGNATION" << std::endl;
		for (unsigned int i = 0; i < b.size(); i++)
		{
			std::cout << "a[" << i << "]: ";
			if (i < a.size())
				std::cout << a[i] << "\t\t";
			else
				std::cout << " "
						  << "\t\t";
			std::cout << "b[" << i << "]: " << b[i] << std::endl;
		}
		b = a;
		std::cout << "AFTER ASSIGNATION" << std::endl;
		for (unsigned int i = 0; i < b.size(); i++)
		{
			std::cout << "a[" << i << "]: " << a[i] << "\t\t";
			std::cout << "b[" << i << "]: " << b[i] << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "------------------ TEST3 ------------------" << std::endl;
	{
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			a[i] = i;
		}
		try
		{
			std::cout << a[5] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "------------------ TEST4 ------------------" << std::endl;
	{
		int *a = new int();
		std::cout << "*a: " << *a << std::endl;
	}

	return 0;
}