#include "StringActions.h"

void StringActions::strcpy_safe(char* dest, const char* src, const int& size)
{
	int i;
	for (i = 0; i < size - 1 && src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
}

bool StringActions::areStringsEqual(const char* str1, const char* str2)
{
	for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
		if (str1[i] != str2[i])
			return false;
	return true;
}

void StringActions::toLower(char* text)
{
	do
	{
		if (*text >= 'A' && *text <= 'Z')
			*text += 'a' - 'A';
	} while (*text++ != '\0');
}