#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define debug = true;

using namespace std;

void argParse(string in)
{
    if (debug)
    {
        cout << in << endl;
    }
}

int main(int argc, char *argv[])
{
    string fileName;
    int lineNumber = -1;
    cout << argc << endl;
    vector<string> args;
    if (argc > 1)
    {
        args.assign(argv + 1, argv + argc);
    }
    for_each(args.begin(), args.end(), argParse);
    return 0;
}

//reads in a file line by line to a vector
vector<string> read_file(string file_name)
{
    vector<string> lines;

    //initialize
    fstream fin;
    fin.open(file_name.c_str());

    //read
    string temp;
    if (!fin.fail())
    {
        while (!fin.eof())
        {
            getline(fin, temp);
            lines.push_back(temp);
        }
    }
    else
    {
        cout << "File failed to open" << endl;
    }
    return lines;
}