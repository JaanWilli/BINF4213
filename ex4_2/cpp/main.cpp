#include <algorithm>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

template<typename E, typename C>
void startFinder(C c, bool (*matcher)(const E)) {
    auto start = chrono::high_resolution_clock::now();
    auto elem_it = find_if(c.begin(), c.end(), matcher);
    auto stop = chrono::high_resolution_clock::now();

    auto time = chrono::duration_cast<chrono::nanoseconds>(stop - start).count()/1000000000.0;

    cout << setprecision(2) << fixed;
    if (elem_it == c.end()) {
        cout << "No match found in " << time << " seconds." << endl;
    }
    else {
        cout << "Found match in " << time << " seconds." << endl;
    }
}

int main() {
    const int size = 100000000;
    const int target = 0;

    vector collection = vector<int>();
    collection.reserve(size);

    for (int i = 0; i < size-1; ++i) {
        collection.push_back(1);
    }
    collection.push_back(target);

    auto matcher = [](const int toMatch) { return target == toMatch; };

    startFinder<int>(collection, matcher);

    return 0;
}