#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int sum1 = 0;
int sum2 = 0;

int main()
{
	int size;
	
	std::cin >> size;

	int arr[size];

	for(int i = 0; i < size; ++i)
	{	
		 arr[i] = rand() % 100 + 1;
	}

	int pid = fork();
	if(pid < 0)
	{
		std::cout << "Error" << std::endl; 
	}
	if(pid == 0)       //Child Process
	{
		for(int i = 0; i < size; ++i)
		{
			if(arr[i] % 2 == 0)
			{
				sum1 += arr[i];
			}
		}
		std::cout << "Even: " << sum1 << std::endl;
	}
	else if(pid > 0)   //Parent Process
	{
		for(int i = 0; i < size; ++i)
		{
			if(arr[i] % 2 != 0)
			{
				sum2 += arr[i];
			}
		}
		std::cout << "Odd: " << sum2 << std::endl;
	}
	
	return 0;
}

