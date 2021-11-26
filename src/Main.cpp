#include <iostream>
#include <string>
#include <vector>

#include "Question.h"

using namespace std;

/* A solution function must have a return type of string and a parameter of type vector<string>. */
/* If you choose to use question.doCustomInput(), ignore the input parameter and do your own input handling. */
string solution(vector<string> input)
{
    /* These are usage examples made for the J1 question "Quadrant Selection" of the 2017 Junior CCC.*/
    /* https://www.cemc.uwaterloo.ca/contests/computing/2017/stage%201/juniorEF.pdf */
    /* Delete all the comments in this function when using. */

    /* ProvidedTestCases mode example: */
    /*
        int x = stoi(input[0]), y = stoi(input[1]);

        if (x < 0 && y > 0) return "2";
        if (x > 0 && y > 0) return "1";
        if (x < 0 && y < 0) return "3";
        return "4";
    */

    /* CustomInput mode example: */
    /*
        int x, y;
        cin >> x;
        cin >> y;

        if (x < 0 && y > 0) return "2";
        if (x > 0 && y > 0) return "1";
        if (x < 0 && y < 0) return "3";
        return "4";
    */
}

int main()
{
    Question question("j1", solution); /* Edit question name. */
    question.checkSolution(Question::Mode::ProvidedTestCases); /* Use ProvidedTestCases or CustomInput. */
}
