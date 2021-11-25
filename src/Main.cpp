#include <iostream>
#include <string>
#include <vector>
#include "Question.h"

using namespace std;

/* A solution function must have a return type of string and a parameter of type vector<string> */
string solution(vector<string> input) {
    int x = stoi(input[0]), y = stoi(input[1]);
    if (x < 0 && y > 0) return "2";
    if (x > 0 && y > 0) return "1";
    if (x < 0 && y < 0) return "3";
    return "4";
}

int main() {
    Question question("j1", solution); /* Edit question name */
    question.doProvidedTestCases();

    cout << "(ENTER to quit)" << endl;
    cin.get();
}
