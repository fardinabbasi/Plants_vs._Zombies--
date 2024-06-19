#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

const char COMMA_DELIM = ',';

string trim(const string str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
        return "";
    else
        return str.substr(start, end - start + 1);
}

map<string, map<string, float>> read_config(const string path)
{
    ifstream fin(path);
    if (!fin.is_open())
    {
        cerr << FILE_FAILED_MESSAGE << endl;
    }
    int i;
    map<string, map<string, float>> config;
    map<string, float> inf;
    vector<string> headers;
    string line, data, name;

    getline(fin, line);
    line = trim(line);
    stringstream ss(line);
    while (getline(ss, data, COMMA_DELIM))
    {
        headers.push_back(data);
    }

    while (getline(fin, line))
    {
        inf.clear();
        line = trim(line);
        stringstream ss(line);
        getline(ss, name, COMMA_DELIM);
        i = 1;
        while (getline(ss, data, COMMA_DELIM))
        {
            if (!data.empty())
            {
                inf[headers[i]] = stof(data);
            }
            i++;
        }
        config[name] = inf;
    }

    fin.close();
    return config;
}

#endif