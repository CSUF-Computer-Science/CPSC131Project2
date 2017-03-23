// Project 2
// Texttool.h

#pragma once

#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

class TextTool {
public:
	// default constructor
	TextTool() {
		dupes = 0;
	}

	// destructor
	~TextTool() {
		
	}

	// Load information from a text file with the given filename.
	void loadListFromTextfile(string filename) {
		ifstream ifs;
		ifs.open(filename);

		if (ifs.is_open()) {
			string aword;
			while (ifs >> aword) {
				addEntryBack(aword);
			}
			ifs.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the number of words in the linked list
	int totalWords() {
		return  wordlist.size();
	}

	// add entry at the back of the linked list
	void addEntryBack(const string& aword) {
		wordlist.push_back(aword);
	}

	// print all words stored in the linked list, separated by a space
	const string listToString() {
		string fullText = "";
		for (itr = wordlist.begin(); itr != wordlist.end(); itr++)
		{
			fullText = fullText + *itr + " ";
		}
		return fullText;
	}

	// print duplicated words in the linked list
	void printDuplicates() {
		nextWord = wordlist.begin();
		nextWord++;
		for (itr = wordlist.begin(); itr != wordlist.end(); itr++)
		{
			if (*nextWord == *itr)
			{
				cout << endl << "DUPLICATE LOCATED:  " << *nextWord;
			}
			if (nextWord != wordlist.end())
			{
				nextWord++;
			}
		}
	}

	// remove duplicated words in the linked
	void removeDuplicates() {
		wordlist.unique();
	}

	// determine the total number of duplicated words in the list
	int totalDuplicates() {
		nextWord = wordlist.begin();
		nextWord++;
		for (itr = wordlist.begin(); itr != wordlist.end(); itr++)
		{
			if (*nextWord == *itr)
			{
				dupes++;
			}
			if (nextWord != wordlist.end())
			nextWord++;
		}
		return dupes;
	}

	// check if the list is empty
	bool isEmpty() {
		return wordlist.empty();
	}

	// Empty the list
	void makeEmpty() {
		wordlist.clear();
		/*itr = wordlist.begin();
		while (!wordlist.empty())
		{
			wordlist.erase(itr);
			itr++;
		}*/
	}

private:

	int dupes;
	list<string>::const_iterator itr;
	list<string>::const_iterator nextWord;
	list<string> wordlist;
};

