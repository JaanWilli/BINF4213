#include <iostream>
#include <cstring>

using namespace std;

class parsebuf : public streambuf {

    ostream *os;
    int indent;
    int n;

public:

    parsebuf(ostream &os, int n) : os(&os), indent(0), n(n) {
        os.rdbuf(this);
    }

    void add_indent() {
        for (int i = 0; i < indent * n; ++i) {
            putchar(' ');
        }
    }

    virtual int_type overflow (int_type c) {
        if (c != EOF) {

            if (' ' == c) return c;

            if ('{' == c) {
                putchar(' ');
                putchar(c);
                putchar('\n');
                ++indent;
                add_indent();
            }
            else if ('}' == c) {
                --indent;
                putchar('\n');
                add_indent();
                putchar(c);
                putchar(' ');
            }
            else if ('\n' == c) {
                putchar(c);
                add_indent();
            }
            else {
                putchar(c);
            }
        }
        return c;
    }
};

int main() {
    parsebuf encrypt(cout, 4);
    string s = "if (a < b){pr  int(a);\nif(a > 5){pri   nt(\"yay\")}}else{print(b);}";
    std::cout << s << std::endl;
    return 0;
}
