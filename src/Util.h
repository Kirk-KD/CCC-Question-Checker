#pragma once

#include <string>
#include <vector>

using namespace std;

class Util
{
public:
	static inline string& rtrim(string& s)
	{
		// https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring

		s.erase(s.find_last_not_of('\n') + 1);
		return s;
	}

	static inline bool hasEnding(string s, string ending)
	{
		if (s.length() >= ending.length())
			return (0 == s.compare(s.length() - ending.length(), ending.length(), ending));

		return false;
	}

	static string addIndent(string s);

	static vector<string> splitString(string s, char spliter);
};
