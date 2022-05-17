#include "Interval.h"
#include <iostream>

Interval::Interval() : leftBorder_(0), rightBorder_(0) {}

Interval::Interval(const int& leftBorder, const int& rightBorder)
{
	if (leftBorder <= rightBorder)
	{
		leftBorder_ = leftBorder;
		rightBorder_ = rightBorder;
	}
	else
	{
		leftBorder_ = 0;
		rightBorder_ = 0;
	}
}

int Interval::getLeftBorder() const 
{
	return leftBorder_;
}

int Interval::getRightBorder() const 
{
	return rightBorder_;
}

void Interval::initializeIntervalThroughInput()
{
	std::cout << "Enter left border value:\n";
	std::cin >> leftBorder_;
	std::cout << "Enter right border value:\n";
	std::cin >> rightBorder_;
}

void Interval::printInterval()
{
	std::cout << "[" << leftBorder_ << "," << rightBorder_ << "]";
}

void Interval::printMenu()
{
	std::cout << "\n0.Display current interval.\n"
		<< "1.Initialize new interval\n"
		<< "2.Get interval length.\n"
		<< "3.Input number to check if it is in interval.\n"
		<< "4.Get amount of prime numbers in the interval.\n"
		<< "5.Get amount of palindrome numbers in the interval.\n"
		<< "6.Get amount of numbers that don't have duplicate digits.\n"
		<< "7.Are both borders powers of 2.\n"
		<< "8.Get intersection of inputted interval and a newly initialized one.\n"
		<< "9.Find if newly initiliazed interval is subset of the previously inputted one.\n"
		<< "10.Exit the program.\n"
		<< "Select the next action through typing its assigned number:\n";
}

int Interval::getIntervalLength()
{
	if (leftBorder_ < 0)
		return leftBorder_ * -1 + rightBorder_;

	return rightBorder_ - leftBorder_;
}

bool Interval::isNumInInterval(const int& numToSeek)
{
	for (int i = leftBorder_; i <= rightBorder_; i++)
		if (i == numToSeek)
			return true;
	return false;
}

bool isNumPrime(const int& numToCheck)
{
	if (numToCheck < 0)
		return false;

	if (numToCheck == 0 || numToCheck == 1)
		return false;

	for (int i = 2; i <= numToCheck / 2; ++i)
		if (numToCheck % i == 0)
			return false;

	return true;
}

int Interval::amountOfPrimeNums()
{
	int count = 0;
	for (int i = leftBorder_; i <= rightBorder_; i++)
		if (isNumPrime(i))
			count++;
	return count;
}

bool isNumPalindrome(const int& numToCheck)
{
	int digit = 0, numReversed = 0, numCopy = numToCheck;
	do
	{
		digit = numCopy % 10;
		numReversed = (numReversed * 10) + digit;
		numCopy /= 10;
	} while (numCopy != 0);

	return numToCheck == numReversed;
}

int Interval::amountOfPalindromes()
{
	int count = 0;
	for (int i = leftBorder_; i <= rightBorder_; i++)
		if (isNumPalindrome(i))
			count++;
	return count;
}

bool doesNumHaveDuplicateDigits(int numToCheck)
{
	int usedNumbers[10] = { 0 };

	while (numToCheck != 0)
	{
		if (usedNumbers[numToCheck % 10] == 1)
			return true;
		usedNumbers[numToCheck % 10] = 1;
		numToCheck /= 10;
	}
	return false;
}

int Interval::amountOfNumsWithNoDuplicateDigits()
{
	int count = 0;
	for (int i = leftBorder_; i <= rightBorder_; i++)
		if (!doesNumHaveDuplicateDigits(i))
			count++;
	return count;
}

bool isNumPowerOfTwo(int numToCheck)
{
	if (numToCheck <= 0)
		return false;

	while (numToCheck != 1)
	{
		if (numToCheck % 2 != 0)
			return false;
		numToCheck /= 2;
	}
	return true;
}

bool Interval::areBordersPowerOfTwo()
{
	return isNumPowerOfTwo(leftBorder_) && isNumPowerOfTwo(rightBorder_);
}

int maxOfTwoNums(const int& firstNum, const int& secondNum)
{
	if (firstNum > secondNum)
		return firstNum;
	return secondNum;
}

int minOfTwoNums(const int& firstNum, const int& secondNum)
{
	if (firstNum < secondNum)
		return firstNum;
	return secondNum;
}

Interval Interval::getIntersectionOfTwoIntervals(const Interval& firstInterval, const Interval& secondInterval)
{
	Interval result (maxOfTwoNums(firstInterval.leftBorder_, secondInterval.leftBorder_), 
						minOfTwoNums(firstInterval.rightBorder_, secondInterval.rightBorder_));
	return result;
}

bool Interval::isIntervalSubset(const Interval& currentInterval, const Interval& inputInterval)
{
	return currentInterval.leftBorder_ <= inputInterval.leftBorder_ 
			&& currentInterval.rightBorder_ >= inputInterval.rightBorder_;
}