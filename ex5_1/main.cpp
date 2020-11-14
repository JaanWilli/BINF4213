#include <iostream>
#include <regex>
#include "../ex3_2/pvector.h"
#include "../ex3_2/pset.h"

using namespace std;

void start_check(string &d, string &f) {

    pset<string> dict(d);
    pvector<string> file(f);

    for (string line : file) {
        regex match_words("\\w+");

        auto start = sregex_iterator(line.begin(), line.end(), match_words);
        auto stop = sregex_iterator();

        for(sregex_iterator w = start; w != stop; ++w) {
            smatch match = *w;
            string word = match.str();

            for (const string& el : dict) {
                regex match_dict(el);
                if (regex_match(word, match_dict)) {
                    cout << "Found a match: " << word << endl;
                    break;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc == 3) {
        string dict(argv[1]);
        string file(argv[2]);

        start_check(dict, file);
    }
}
