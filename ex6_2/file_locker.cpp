#include <iostream>
#include "file_locker.h"

void file_locker::lock() {
    cout << "'" << getFileName() << "' is locked." << endl;
}

void file_locker::unlock() {
    cout << "'" << getFileName() << "' is unlocked." << endl;
}

file_locker::file_locker(string &file) : file(file) {
    lock();
}

file_locker::~file_locker() {
    unlock();
}

string file_locker::getFileName() {
    return file;
}
