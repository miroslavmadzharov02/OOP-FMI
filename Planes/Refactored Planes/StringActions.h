#pragma once

#ifndef STRINGACTIONS
#define STRINGACTIONS

namespace StringActions
{
	void strcpy_safe(char* dest, const char* src, const int& size);
	bool areStringsEqual(const char* str1, const char* str2);
	void toLower(char* text);
};

#endif 