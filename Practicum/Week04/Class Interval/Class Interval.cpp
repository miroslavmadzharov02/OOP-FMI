#include "Interval.h"
#include <iostream>

int main()
{
	Interval interval;
	interval.initializeIntervalThroughInput();

	int inputNum = -1;
	do
	{
		interval.printMenu();
		std::cin >> inputNum;
		switch (inputNum)
		{
		case 0:
			interval.printInterval();
			std::cout << '\n';
			break;
		case 1:
			interval.initializeIntervalThroughInput();
			break;
		case 2:
			interval.printInterval();
			std::cout << " has a length of " << interval.getIntervalLength() << '\n';
			break;
		case 3:
			int tempNum;
			std::cout << "Input number to check:\n";
			std::cin >> tempNum;
			std::cout << tempNum << " is in interval: " << std::boolalpha << interval.isNumInInterval(tempNum) << '\n';
			break;
		case 4:
			interval.printInterval();
			std::cout << " has a total of " << interval.amountOfPrimeNums() << " prime numbers.\n";
			break;
		case 5:
			interval.printInterval();
			std::cout << " has a total of " << interval.amountOfPalindromes() << " palindrome numbers.\n";
			break;
		case 6:
			interval.printInterval();
			std::cout << " has a total of " << interval.amountOfNumsWithNoDuplicateDigits() << " numbers with no duplicate digits.\n";
			break;
		case 7:
			std::cout << "The border values are powers of two: " << 
				std::boolalpha << interval.areBordersPowerOfTwo() << '\n';
			break;
		case 8:
		{
			Interval inputtedInterval;
			inputtedInterval.initializeIntervalThroughInput();
			Interval intersection = intersection.getIntersectionOfTwoIntervals(interval, inputtedInterval);
			std::cout << "The intersection is ";
			intersection.printInterval();
			std::cout << '\n';
			break;
		}
		case 9:
		{
			Interval inputtedInterval;
			inputtedInterval.initializeIntervalThroughInput();
			std::cout << "Newly inputted interval is a subset: "
				<< std::boolalpha << interval.isIntervalSubset(interval, inputtedInterval) << '\n';
			break;
		}
		case 10:
			std::cout << "Exited program successfully.\n";
			break;
		default:
			std::cout << "Invalid input.\n";
			break;
		}
	} while (inputNum != 10);
	
	return 0;
}
