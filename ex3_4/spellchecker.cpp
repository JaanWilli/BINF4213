#include <sstream>
#include "spellchecker.h"

spellchecker::spellchecker(string &dict) : dictionary(dict) {}

void spellchecker::start_check(string &file) {

    pvector<string> lines(file);
    for (string &line : lines) {
        check_line(line);
    }
}

void spellchecker::check_line(string &line) {

    string::iterator start = line.begin();
    string::iterator stop = line.begin();

    while (next_word(start, stop, line.end())) {
        string word(start, stop);

        if (dictionary.count(word) == 0 && ignored.count(word) == 0) {
            char c;
            cout << "found word: " << word << endl;
            cout << "add, ignore, correct? [a,i,c]: ";
            cin >> c;
            cout << endl;

            if (c == 'a') {
                add(word);
            }
            else if (c == 'i') {
                ignore(word);
            }
            else if (c == 'c') {
                correct(line, start, stop);
            }
            else {
                cout << "Wrong input. Moving on..." << endl << endl;
                continue;
            }
        }
        else {
            start = stop;
        }
    }
}

void spellchecker::add(string &word) {
    dictionary.insert(word);
}

void spellchecker::ignore(string &word) {
    ignored.insert(word);
}

void spellchecker::correct(string &line, string::iterator &start, string::iterator &stop) {
    string new_word;
    cout << "old word: " << string(start, stop) << endl;
    cout << "replace by: ";
    cin >> new_word;
    cout << endl;

    ostringstream os;
    os << string(line.begin(), start) << new_word << string(stop, line.end());
    line = os.str();
    start = line.begin();
    stop = line.begin();
}

bool spellchecker::next_word(string::iterator &start, string::iterator &stop, const string::iterator &end) {

    while (start < end && !isalpha(*start)) {
        ++start;
    }
    stop = start;
    while (stop < end && !isspace(*stop)) {
        ++stop;
    }
    if (stop-1 > start && !isalpha(*(stop-1))) {
        --stop;
    }
    return start != stop;
}
