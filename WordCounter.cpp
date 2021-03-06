// WordCounter.cpp : Defines the entry point for the console application.
//

#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <streambuf>
#include <cerrno>
#include <map>

//read the input
std::string getFileContents(const char *filename)
{
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in)
	{
		return(std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));
	}
	throw(errno);
}

//remove the undesired chars 
void removeCharsFromString(std::string &str, const char* charsToRemove) {
	for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
		str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
	}
}

void removeCharFromString(std::string &str, const char charToRemove) {

	str.erase(remove(str.begin(), str.end(), charToRemove), str.end());

}

void uppercaseWord(std::string &str)
{
	int i = 0;
	char c;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

std::string grabWord(std::string &in)
{
	

	size_t indexOfNextWS = in.find(' ');
	std::string grabbed = in.substr(0, indexOfNextWS);

	if (in.length() > indexOfNextWS + 1)
		in.erase(0, indexOfNextWS + 1);

	//uppercase them all
	uppercaseWord(grabbed);
	
	
//	std::cout << grabbed<< " where first letter is "<< (int)grabbed[0]<< " and length is: "<< grabbed.length()<< '\n';
	return grabbed;
}
int main()
{
	std::string path = "alice.txt";
	std::string input = getFileContents(path.c_str());
	//store words as keys and their count as values
	std::map <std::string, int> wordCount;
//	input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
//	std::cout << input;
	
	std::string undesiredChars = ",.!?():<>;\"1234567890'-";
//	removeCharFromString(input, '\n');

	//std::string::size_type i = 0;
	//while (i < input.length()) {
	//	i = input.find('\n', i);
	//	if (i == std::string::npos) {
	//		break;
	//	}
	//	input.erase(i);
	//}
	std::cout << input;


	removeCharsFromString(input, undesiredChars.c_str());
//	removeCharsFromString(input, '\n')
	//path.max_size()
	
	
	size_t pos = 0;
	
	do 
	{
		std::string word = grabWord(input);

		//for some reason we have a lot of spaces...
		if ((int)word[0] == 0)
			continue;
		else {
			if (wordCount.find(word) == wordCount.end())
			{
				wordCount[word] = 1;
			}
			else
			{
				int occurance = wordCount[word];
				occurance++;
				wordCount[word] = occurance;
			}

		}

	} while (pos = input.find(' ') != std::string::npos);


	for (auto it = wordCount.cbegin(); it != wordCount.cend(); ++it)
	{
//		std::cout << it->first << " " << it->second << "\n";
	}
    return 0;
} 

