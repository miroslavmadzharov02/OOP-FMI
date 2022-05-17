#pragma once

//TODO: IFNDEF

class Interval
{
private:
	int leftBorder_;
	int rightBorder_;

public:
	Interval();
	Interval(const int& leftBorder, const int& rightBorder);
	int getLeftBorder() const;
	int getRightBorder() const;

	void initializeIntervalThroughInput();
	void printInterval();
	void printMenu();

	int getIntervalLength();
	bool isNumInInterval(const int& numToSeek);
	int amountOfPrimeNums();
	int amountOfPalindromes();
	int amountOfNumsWithNoDuplicateDigits();
	bool areBordersPowerOfTwo();
	Interval getIntersectionOfTwoIntervals(const Interval& firstInterval, const Interval& secondInterval);
	bool isIntervalSubset(const Interval& currentInterval, const Interval& inputInterval);
};