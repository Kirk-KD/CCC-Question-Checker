#include "Question.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
namespace fs = std::filesystem;

using namespace std;

inline std::string& rtrim(std::string& s)
{
	// https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring

	s.erase(s.find_last_not_of('\n') + 1);
	return s;
}

bool hasEnding(string s, string ending) {
	if (s.length() >= ending.length())
		return (0 == s.compare(s.length() - ending.length(), ending.length(), ending));

	return false;
}

vector<string> splitString(string s, char spliter) {
	vector<string> res;

	string curr_string = "";
	for (char c : s) {
		if (c == spliter) {
			res.push_back(curr_string);
			curr_string = "";
		}
		else curr_string += c;
	}

	if (curr_string.length() != 0) res.push_back(curr_string);

	return res;
}

string addIndent(string s) {
	string res = "    ";
	
	for (const char c : s) {
		res += c;
		if (c == '\n') res += "    ";
	}

	return res;
}

Question::Question(string question_name, function<string(vector<string>)> solution_func) :
	question_name(question_name), solution_func((solution_func)) {
	cout << "Question: " << question_name << endl;
}

tuple<vector<string>, vector<string>> Question::readSamples() {
	// https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c

	vector<string> inputs, outputs;

	for (const auto& entry : fs::directory_iterator(question_name)) {
		string curr_path = entry.path().u8string();

		std::ifstream ifs(curr_path);
		std::string content((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));

		if (hasEnding(curr_path, "in")) inputs.push_back(rtrim(content));
		else outputs.push_back(rtrim(content));
	}

	return { inputs, outputs };
}

void Question::doProvidedTestCases() {
	auto [inputs, outputs] = readSamples();

	int total = inputs.size();
	int pass = 0;

	cout << "Running all " << total << " test cases for question " << question_name << ":" << endl;

	auto inputs_it = inputs.begin();
	auto outputs_it = outputs.begin();
	int sample_num = 1;

	while (inputs_it != inputs.end()) {
		vector<string> splited = splitString(*inputs_it, '\n');

		auto start_time = chrono::high_resolution_clock::now();
		string actual_out = solution_func(splited);
		auto stop_time = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);

		cout << "  ====== Sample #" << sample_num + 1 << " ======" << endl << endl;
		cout << "    ----------- Input -----------" << endl << addIndent(*inputs_it)  << endl << endl;
		cout << "    ------ Expected Output ------" << endl << addIndent(*outputs_it) << endl << endl;
		cout << "    ------- Actual Output -------" << endl << addIndent(actual_out)  << endl << endl;

		bool passed = actual_out == *outputs_it;
		if (passed) ++pass;

		cout << "  ====== Sample #" << sample_num + 1 << " Result: " << (passed ? "PASS" : "FAIL") << " ======" << endl << endl;

		++inputs_it;
		++outputs_it;
		++sample_num;
	}

	cout << "Total: " << total << " | Passed: " << pass << " | Failed: " << total - pass << endl;
	cout << "Final Result: " << (total == pass ? "PASS" : "FAIL") << endl;
}

void Question::doCustomInput(string inputs[]) {

}
