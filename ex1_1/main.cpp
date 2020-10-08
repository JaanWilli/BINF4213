#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void hello_world() {
    cout << "Hello World" << endl;
}

int main(int argc, char *argv[]) {
    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);
    char c;
    for (;;) {
        ifs.get(c);
        if (!ifs.good()) break;
        if (c=='\n') ofs << "\r\n";
        else if (c == '\r') {
            ofs << "\n";
            ifs.get(c);
        }
        else ofs << c;
    }
}
