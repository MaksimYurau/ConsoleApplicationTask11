#include "Set.h"
#include <iostream>

int main() {
    setlocale(0, "ru");

    Set set1;
    Set set2;

    set1.addElement(0);
    set1.addElement(2);
    set1.addElement(3);
    set1.addElement(3);

    set2.addElement(2);
    set2.addElement(3);
    set2.addElement(4);
    set2.addElement(4);

    std::cout << "Множество 1: ";
    set1.printSet();

    std::cout << "Множество 2: ";
    set2.printSet();

    Set intersectionSet = set1.intersection(set2);
    std::cout << "Пересечение множеств: ";
    intersectionSet.printSet();

    Set differenceSet = set1.difference(set2);
    std::cout << "Разность множеств (множество 1 - множество 2): ";
    differenceSet.printSet();

    set1.addElement(8);

    std::cout << "Множество 1: ";
    set1.printSet();

    set1.removeElement(8);

    std::cout << "Множество 1: ";
    set1.printSet();

    set1.addElementAt(4, 3);
    std::cout << "Множество 1 после добавления элемента 4 на позицию 1: ";
    set1.printSet();

    set2.removeElementAt(0);
    std::cout << "Множество 2 после удаления элемента на позиции 0: ";
    set2.printSet();

    std::cout << std::endl;

    system("pause");

    return 0;
}
