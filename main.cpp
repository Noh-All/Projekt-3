#include <iostream>
#include <vector>
#include "MergeSorter.h"

int main() {
    // 1. Instancja dla int
    MergeSorter<int> intSorter;
    std::vector<int> intTab = { 12, 11, 13, 5, 6, 7 };

    std::cout << "--- TEST INT ---\nPrzed: ";
    for (int x : intTab) std::cout << x << " ";
    std::cout << "\n";

    intSorter.sort(intTab);

    std::cout << "Po:    ";
    for (int x : intTab) std::cout << x << " ";
    std::cout << "\n\n";

    // 2. Instancja dla double
    MergeSorter<double> doubleSorter;
    std::vector<double> doubleTab = { 12.5, 1.1, 13.9, 0.5, 6.0 };

    std::cout << "--- TEST DOUBLE ---\nPrzed: ";
    for (double x : doubleTab) std::cout << x << " ";
    std::cout << "\n";

    doubleSorter.sort(doubleTab);

    std::cout << "Po:    ";
    for (double x : doubleTab) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}