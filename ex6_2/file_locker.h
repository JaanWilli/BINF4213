#ifndef EX6_2_FILE_LOCKER_H
#define EX6_2_FILE_LOCKER_H

#include <string>

using namespace std;

class file_locker {

    string file;

    void lock();
    void unlock();

public:

    explicit file_locker(string &file);
    ~file_locker();

    string getFileName();

};


#endif //EX6_2_FILE_LOCKER_H
