#include "gtest/gtest.h"
#include "../SortowanieApp/MergeSorter.h" // Teraz widzi ten plik, bo go dodaliœmy
#include <algorithm>
#include <vector>
#include <random>

class MergeSortTest : public ::testing::Test {
protected:
    MergeSorter<int> sorter;
};

// 1. Ju¿ posortowana
TEST_F(MergeSortTest, AlreadySorted) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 2. Odwrotna kolejnoœæ
TEST_F(MergeSortTest, ReverseSorted) {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 3. Losowa
TEST_F(MergeSortTest, RandomArray) {
    std::vector<int> arr = { 10, 2, 8, 1, 5 };
    std::vector<int> expected = { 1, 2, 5, 8, 10 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 4. Tylko ujemne
TEST_F(MergeSortTest, OnlyNegative) {
    std::vector<int> arr = { -5, -1, -3, -10 };
    std::vector<int> expected = { -10, -5, -3, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 5. Ujemne i dodatnie
TEST_F(MergeSortTest, MixedPositiveAndNegative) {
    std::vector<int> arr = { -5, 10, 0, -3, 2 };
    std::vector<int> expected = { -5, -3, 0, 2, 10 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 6. Pusta tablica
TEST_F(MergeSortTest, EmptyArray) {
    std::vector<int> arr = {};
    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

// 7. Jeden element
TEST_F(MergeSortTest, SingleElement) {
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 8. Duplikaty
TEST_F(MergeSortTest, WithDuplicates) {
    std::vector<int> arr = { 3, 1, 2, 3, 1 };
    std::vector<int> expected = { 1, 1, 2, 3, 3 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 9. Ujemne z duplikatami
TEST_F(MergeSortTest, NegativeWithDuplicates) {
    std::vector<int> arr = { -3, -1, -3, -5, -1 };
    std::vector<int> expected = { -5, -3, -3, -1, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 10. Mix z duplikatami
TEST_F(MergeSortTest, MixedWithDuplicates) {
    std::vector<int> arr = { -2, 2, 0, -2, 2 };
    std::vector<int> expected = { -2, -2, 0, 2, 2 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 11. Dwa elementy
TEST_F(MergeSortTest, TwoElementsSorted) {
    std::vector<int> arr = { 1, 2 };
    std::vector<int> expected = { 1, 2 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 12. Du¿a tablica (>100)
TEST_F(MergeSortTest, LargeArray) {
    std::vector<int> arr;
    for (int i = 200; i > 0; --i) arr.push_back(i);
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 13. Du¿a tablica mix (>100)
TEST_F(MergeSortTest, LargeMixedArray) {
    std::vector<int> arr;
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(-100, 100);
    for (int i = 0; i < 150; ++i) arr.push_back(dist(rng));

    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}