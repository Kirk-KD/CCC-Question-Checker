#pragma once

#include <string>
#include <vector>
#include <functional>

using namespace std;

class Question
{
public:
	string question_name;
	function<string(vector<string>)> solution_func;

	Question(string question_name, function<string(vector<string>)> solution_func);

	void doProvidedTestCases();

	void doCustomInput(string inputs[]);

private:
	tuple<vector<string>, vector<string>> readSamples();
};
