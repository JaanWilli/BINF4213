#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

string path = R"(C:\Users\willi\Documents\BINF4213\ex1_3\)";


void spell_check() {
    set<string> dict;
    string dict_word;
    string text_word;

    ifstream dict_stream;
    dict_stream.open(path + "dict.txt");

    while (getline(dict_stream, dict_word)) {
        dict.insert(dict_word);
    }

    ifstream text_stream;
    text_stream.open(path + "text.txt");

    while (text_stream >> text_word) {
        if (dict.count(text_word) == 0) {
            cout << text_word << endl;
        }
    }
}


int main() {
    spell_check();
}
