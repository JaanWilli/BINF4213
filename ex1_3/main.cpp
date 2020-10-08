#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Invalid arguments: [dictionary file] [text file]" << endl;
        return 0;
    }

    set<string> dict;
    string w;

    ifstream ifdict(argv[1]);
    while (ifdict >> w) {
        dict.insert(w);
    }

    ifstream iftext(argv[2]);
    while (iftext >> w) {
        if (w.back() == '.' || w.back() == '?' || w.back() == '!') w.pop_back();
        if (dict.count(w) == 0) {
            cout << w << endl;
        }
    }
}
