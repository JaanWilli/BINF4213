#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include "spellchecker.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc == 3) {
        string dict(argv[1]);
        string file(argv[2]);

        spellchecker sc(dict);

        sc.start_check(file);
    }
}
