#pragma once

#ifndef SET_H
#define SET_H

class Set {
private:
    int* elements;
    int size;
    int capacity;

public:
    Set();
    ~Set();

    void addElement(int element);
    void removeElement(int element);
    bool contains(int element) const;
    void printSet() const;

    Set intersection(const Set& other) const;
    Set difference(const Set& other) const;
};

#endif  // SET_H