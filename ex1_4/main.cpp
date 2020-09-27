#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

void print_stack(vector<int>& v) {

    if (v.empty()) {
        cout << "1:  -" << endl;
        return;
    }
    int i = 1;
    for (int x : v) {
        cout << i << ":  " << x << endl;
        i++;
    }
}

void remove_from_stack(int& a, int& b, vector<int>& v) {
    b = v.back();
    v.pop_back();
    a = v.back();
    v.pop_back();
}


int main() {

    stack<int> s;
    vector<int> v;

    while(true) {

        string line;
        getline(cin, line);
        istringstream is(line);

        while(is) {
            string c;
            int a,b;
            is >> c;

            if (c == "n") {
                is >> a;
                v.push_back(a);
            }
            else if (c == "+") {
                remove_from_stack(a,b,v);
                v.push_back(a+b);
            }
            else if (c == "-") {
                remove_from_stack(a,b,v);
                v.push_back(a-b);
            }
            else if (c == "*") {
                remove_from_stack(a,b,v);
                v.push_back(a*b);
            }
            else if (c == "/") {
                remove_from_stack(a,b,v);
                v.push_back(a/b);
            }
            else if (c == "min") {
                remove_from_stack(a,b,v);
                int min = a < b ? a : b;
                v.push_back(min);
            }
            else if (c == "d") {
                v.pop_back();
            }
            else if (c == "q") {
                return 0;
            }
        }
        print_stack(v);
    }
}
