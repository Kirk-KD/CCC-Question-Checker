#include "Util.h"

string Util::addIndent(string s)
{
    string res = "    ";

    for (const char c : s)
    {
        res += c;
        if (c == '\n') res += "    ";
    }

    return res;
}

vector<string> Util::splitString(string s, char spliter)
{
    vector<string> res;

    string curr_string = "";
    for (char c : s)
    {
        if (c == spliter)
        {
            res.push_back(curr_string);
            curr_string = "";
        }
        else curr_string += c;
    }

    if (curr_string.length() != 0) res.push_back(curr_string);

    return res;
}
