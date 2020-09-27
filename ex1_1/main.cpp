#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int hello_world() {
    cout << "Hello World" << endl;
    return 0;
}

int convert() {
    ifstream ifile;
    ifile.open(R"(C:\Users\willi\Documents\BINF4213\ex1_1\in.txt)");
    ofstream ofile;
    ofile.open(R"(C:\Users\willi\Documents\BINF4213\ex1_1\out.txt)");

    char c;
    if (ifile.is_open() && ofile.is_open()) {
        while(ifile.good()) {
            ifile.get(c);
            if (c=='\n') ofile << "\r\n";
            else ofile << c;
        }
        ifile.close();
    }
    else {
        cout << "unable to open";
    }
    return 0;
}

int main() {
    hello_world();
    convert();
}
