#include "Question.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>

#include "Util.h"

namespace fs = std::filesystem;

using namespace std;

Question::Question(string question_name, function<string(vector<string>)> solution_func) :
	question_name(question_name), solution_func((solution_func))
{
	cout << "Question: " << question_name << endl;
}

tuple<vector<string>, vector<string>> Question::readSamples()
{
	// https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c

	vector<string> inputs, outputs;

	for (const auto& entry : fs::directory_iterator(question_name))
	{
		string curr_path = entry.path().u8string();

		std::ifstream ifs(curr_path);
		std::string content((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));

		string trimmed_content = Util::rtrim(content);
		if (Util::hasEnding(curr_path, "in")) inputs.push_back(trimmed_content);
		else outputs.push_back(trimmed_content);
	}

	return { inputs, outputs };
}

void Question::doProvidedTestCases()
{
	auto [inputs, outputs] = readSamples();

	int total = inputs.size();
	int pass = 0;

	cout << "Running all " << total << " test cases for question " << question_name << ":" << endl;

	auto inputs_it = inputs.begin();
	auto outputs_it = outputs.begin();
	int sample_num = 1;

	while (inputs_it != inputs.end())
	{
		vector<string> splited = Util::splitString(*inputs_it, '\n');

		// Time solution function execution duration
		auto start_time = chrono::high_resolution_clock::now();
		string actual_out = solution_func(splited);
		auto stop_time = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();

		cout << "  ====== Sample #" << sample_num << " ======" << endl << endl;
		cout << "    ----------- Input -----------" << endl << Util::addIndent(*inputs_it)  << endl << endl;
		cout << "    ------ Expected Output ------" << endl << Util::addIndent(*outputs_it) << endl << endl;
		cout << "    ------- Actual Output -------" << endl << Util::addIndent(actual_out)  << endl << endl;

		bool passed = actual_out == *outputs_it;
		if (passed) ++pass;

		cout << "  ====== Sample #" << sample_num << " Result: " << (passed ? "PASS" : "FAIL")
			<< " (" << duration << "ms) ======" << endl << endl;

		++inputs_it;
		++outputs_it;
		++sample_num;
	}

	cout << "Total: " << total << " | Passed: " << pass << " | Failed: " << total - pass << endl;
	cout << "Final Result: " << (total == pass ? "PASS" : "FAIL") << endl;
}

void Question::doCustomInput(string inputs[])
{

}
