#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define debug true

using namespace std;

void argParse(vector<string> args, string& inFileName, string outFileName, int& lineNumber)
{
    for_each(args.begin(), args.end(), [&](string arg) -> void {
        switch (arg[1]) {
        case 'L':
        case 'l':
            lineNumber = stoi(arg.substr(3));
            break;
        case 'I':
        case 'i':
            inFileName = arg.substr(3);
            break;
        case 'O':
        case 'o':
            outFileName = arg.substr(3);
            break;
        default:
            cout << "Invalid argument: " << arg << endl;
            cout << "Accepted arguments are -L,-I,-O for Line number, Input file and Output file respectivly" << endl;
        }
        if (debug) {
            cout << arg << endl;
        }
    });
    if (inFileName == "") {
        cout << "Please provide an input filename" << endl;
    }
    if (outFileName == "") {
        cout << "Please provide an output filename" << endl;
    }
    return;
}

int main(int argc, char* argv[])
{
    string inFileName = "";
    string outFileName = "";
    int lineNumber = -1;
    cout << argc << endl;
    vector<string> args;
    if (argc > 1) {
        args.assign(argv + 1, argv + argc);
    }
    argParse(args, inFileName, outFileName, lineNumber);
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
    if (!fin.fail()) {
        while (!fin.eof()) {
            getline(fin, temp);
            lines.push_back(temp);
        }
    } else {
        cout << "File failed to open" << endl;
    }
    return lines;
}