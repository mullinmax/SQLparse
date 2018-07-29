#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string fileName;
    int lineNumber = -1;
    cout << argc << endl;
    if (argc == 1)
    {
        cout << "Please provide a file name" << endl;
    }
    else if (argc == 2)
    {
        fileName = argv[1];
    }
    else if (argc == 3)
    {
        if (argv[1] == "-l" || argv[1] == "-L")
        {
            cout << "please provide line number AND filename" << endl;
        }
    }
    else if (argc == 4)
    {
        if (argv[1] == "-l" || argv[1] == "-L")
        {
            lineNumber = stoi(argv[2]);
            fileName = argv[3];
        }
    }
    else
    {
    }
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