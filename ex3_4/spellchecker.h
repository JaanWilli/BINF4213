#ifndef EX3_4_SPELLCHECKER_H
#define EX3_4_SPELLCHECKER_H

#include <set>

#include "../ex3_2/pset.h"
#include "../ex3_2/pvector.h"

using namespace std;

class spellchecker {

    pset<string> dictionary;
    std::set<string> ignored;

public:

    explicit spellchecker(string &dict);

    void start_check(string &file);
    void check_line(string &line);

    void add(string &word);
    void ignore(string &word);
    static void correct(string &line, string::iterator &start, string::iterator &stop);

    static bool next_word(string::iterator &start, string::iterator &stop, const string::iterator &end);

};


#endif //EX3_4_SPELLCHECKER_H
