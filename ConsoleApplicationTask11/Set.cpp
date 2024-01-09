#include "Set.h"
#include <iostream>

Set::Set() {
    capacity = 10;
    size = 0;
    elements = new int[capacity];
}

Set::~Set() {
    delete[] elements;
}

void Set::addElement(int element) {
    if (size == capacity) {
        capacity *= 2;
        int* newElements = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
    elements[size++] = element;
}

void Set::addElementAt(int element, int position) {
    if (position < 0 || position > size) {
        std::cout << "Некорректная позиция" << std::endl;
        return;
    }

    if (size == capacity) {
        capacity *= 2;
        int* newElements = new int[capacity];
        for (int i = 0; i < position; ++i) {
            newElements[i] = elements[i];
        }
        newElements[position] = element;
        for (int i = position; i < size; ++i) {
            newElements[i + 1] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
    else {
        for (int i = size; i > position; --i) {
            elements[i] = elements[i - 1];
        }
        elements[position] = element;
    }
    size++;
}

void Set::removeElement(int element) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; ++i) {
            elements[i] = elements[i + 1];
        }
        size--;
    }
}

void Set::removeElementAt(int position) {
    if (position < 0 || position >= size) {
        std::cout << "Некорректная позиция" << std::endl;
        return;
    }
    for (int i = position; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    size--;
}

bool Set::contains(int element) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

void Set::printSet() const {
    std::cout << "{ ";
    for (int i = 0; i < size; ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << "}" << std::endl;
}

Set Set::intersection(const Set& other) const {
    Set result;

    for (int i = 0; i < size; ++i) {
        if (other.contains(elements[i])) {
            result.addElement(elements[i]);
        }
    }

    return result;
}

Set Set::difference(const Set& other) const {
    Set result;

    for (int i = 0; i < size; ++i) {
        if (!other.contains(elements[i])) {
            result.addElement(elements[i]);
        }
    }

    return result;
}


/*
#include "Set.h"
#include <iostream>

Set::Set() : top(nullptr) {}

Set::~Set() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Set::addElement(int element) {
    if (!contains(element)) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
    }
}

void Set::addElementAt(int element, int position) {
    if (position <= 0) {
        addElement(element);
        return;
    }

    int count = 0;
    Node* current = top;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current != nullptr) {
        Node* newNode = new Node(element);
        newNode->next = current->next;
        current->next = newNode;
    }
}

void Set::removeElement(int element) {
    if (top == nullptr) {
        return;
    }

    // If the element to be removed is at the top
    if (top->data == element) {
        Node* temp = top;
        top = top->next;
        delete temp;
        return;
    }

    Node* current = top;
    while (current->next != nullptr && current->next->data != element) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void Set::removeElementAt(int position) {
    if (position <= 0 || top == nullptr) {
        return;
    }

    if (position == 1) {
        Node* temp = top;
        top = top->next;
        delete temp;
        return;
    }

    int count = 1;
    Node* current = top;
    while (current->next != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

bool Set::contains(int element) const {
    Node* current = top;
    while (current != nullptr) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void Set::printSet() const {
    Node* current = top;
    std::cout << "{ ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "}" << std::endl;
}

Set Set::intersection(const Set& other) const {
    Set result;
    Node* current = top;
    while (current != nullptr) {
        if (other.contains(current->data)) {
            result.addElement(current->data);
        }
        current = current->next;
    }
    return result;
}

Set Set::difference(const Set& other) const {
    Set result;
    Node* current = top;
    while (current != nullptr) {
        if (!other.contains(current->data)) {
            result.addElement(current->data);
        }
        current = current->next;
    }
    return result;
}
*/