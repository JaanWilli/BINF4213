#include <iostream>

using namespace std;

class parent {
public:
    parent() {
        cout << "Construct parent class" << endl;
    }

    ~parent() {
        cout << "Destruct parent class" << endl;
    }
};

class child : public parent {
public:
    child() {
        cout << "Construct child class" << endl;
    }

    ~child() {
        cout << "Destruct child class" << endl;
    }
};

int main() {
    child c;
    return 0;
}
