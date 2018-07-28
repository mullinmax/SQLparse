#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    cout << argc << endl;
    if (argc == 0)
    {
    }
    else if (argc == 1)
    {
    }
    else if (argc == 2)
    {
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
    fin.open(file_name);

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