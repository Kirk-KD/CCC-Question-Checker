#pragma once

#include <string>
#include <vector>
#include <functional>

using namespace std;

class Question
{
public:
    enum class Mode
    {
        ProvidedTestCases,
        CustomInput
    };

    string question_name;
    function<string(vector<string>)> solution_func;

    Question(string question_name, function<string(vector<string>)> solution_func);

    void checkSolution(Question::Mode mode);

private:
    tuple<vector<string>, vector<string>> readSamples();

    void doProvidedTestCases();

    void doCustomInput();
};
