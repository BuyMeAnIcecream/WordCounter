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

std::string grabWord(std::string &in)
{
	

	size_t indexOfNextWS = in.find(' ');
	std::string token = in.substr(0, indexOfNextWS);
	//TODO peal it from ' Since in English you can have ' in midst of word - let's remove it from the end and beginning of the word in case it's a quote or something
	std::string grabbed = token;
	



	if (in.length() > indexOfNextWS + 1)
		in.erase(0, indexOfNextWS + 1);
	return grabbed;
}
int main()
{
	std::string path = "alice.txt";
	std::string input = getFileContents(path.c_str());
	//store words as keys and their count as values
	std::map <std::string, int> wordCount;
//	std::cout<<wordCount.max_size();

	std::string undesiredChars = ",.!?():<>;";

	removeCharsFromString(input, undesiredChars.c_str());
	//path.max_size()
//	std::cout << input;
	
	size_t pos = 0;
	
	do 
	{
		std::string word = grabWord(input);
		std::cout << word<<" ";
		//insert new if it hasn't appeared before
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
		

	} while (pos = input.find(' ') != std::string::npos);


	for (auto it = wordCount.cbegin(); it != wordCount.cend(); ++it)
	{
		std::cout << it->first << " " <<   " " << it->second << "\n";
	}
    return 0;
} 

