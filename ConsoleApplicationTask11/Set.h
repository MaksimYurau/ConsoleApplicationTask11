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
    void addElementAt(int element, int position);
    void removeElement(int element);
    void removeElementAt(int position);
    bool contains(int element) const;
    void printSet() const;

    Set intersection(const Set& other) const;
    Set difference(const Set& other) const;
};

#endif  // SET_H