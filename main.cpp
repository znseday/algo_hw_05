#include <iostream>

#include "itask.h"
#include "tester.h"

#include "sort.h"
#include "test_generator.h"

using namespace std;
namespace fs = std::experimental::filesystem;

bool IsDebugOutput = false;

int main()
{  
//    for (size_t i = 0; i < 7; ++i) // Для big_objects
//    {
//        GenTestRandom(i);
//        GenTestSameLetters(i);
//        GenTestAllmostSorted(i);
//        GenTestRevers(i);
//    }
//    return 0;

    Sort s;
    Tester testerSortRandom(&s, "0. Random", fs::current_path().string() + "\\0.random");
    testerSortRandom.SetMaxTests(7);
    testerSortRandom.RunTasks(SortType_t::Select);
    testerSortRandom.RunTasks(SortType_t::Insert);
    testerSortRandom.SetMaxTests(8);
    testerSortRandom.RunTasks(SortType_t::Shell_1);
    testerSortRandom.RunTasks(SortType_t::Shell_2);
    testerSortRandom.RunTasks(SortType_t::Shell_3);
    testerSortRandom.RunTasks(SortType_t::Heap);
    testerSortRandom.RunTasks(SortType_t::std_Sort);

    Tester testerSortDigits(&s, "1. Digits", fs::current_path().string() + "\\1.digits");
    testerSortDigits.SetMaxTests(7);
    testerSortDigits.RunTasks(SortType_t::Select);
    testerSortDigits.RunTasks(SortType_t::Insert);
    testerSortDigits.SetMaxTests(8);
    testerSortDigits.RunTasks(SortType_t::Shell_1);
    testerSortDigits.RunTasks(SortType_t::Shell_2);
    testerSortDigits.RunTasks(SortType_t::Shell_3);
    testerSortDigits.RunTasks(SortType_t::Heap);
    testerSortDigits.RunTasks(SortType_t::std_Sort);

    Tester testerSortSorted(&s, "2. Sorted", fs::current_path().string() + "\\2.sorted");
    testerSortSorted.SetMaxTests(7);
    testerSortSorted.RunTasks(SortType_t::Select);
    testerSortSorted.RunTasks(SortType_t::Insert);
    testerSortSorted.SetMaxTests(8);
    testerSortSorted.RunTasks(SortType_t::Shell_1);
    testerSortSorted.RunTasks(SortType_t::Shell_2);
    testerSortSorted.RunTasks(SortType_t::Shell_3);
    testerSortSorted.RunTasks(SortType_t::Heap);
    testerSortSorted.RunTasks(SortType_t::std_Sort);

    Tester testerSortRevers(&s, "3. Revers", fs::current_path().string() + "\\3.revers");
    testerSortRevers.SetMaxTests(7);
    testerSortRevers.RunTasks(SortType_t::Select);
    testerSortRevers.RunTasks(SortType_t::Insert);
    testerSortRevers.SetMaxTests(8);
    testerSortRevers.RunTasks(SortType_t::Shell_1);
    testerSortRevers.RunTasks(SortType_t::Shell_2);
    testerSortRevers.RunTasks(SortType_t::Shell_3);
    testerSortRevers.RunTasks(SortType_t::Heap);
    testerSortRevers.RunTasks(SortType_t::std_Sort);
    //----------------------------------------------------

    //-----  big_objects ---------------------------------
    IsDebugOutput = false;
    SortBogObjects sbo;
    Tester testerSortRandomBigObjects(&sbo, "0. Random (big_objects)", fs::current_path().string() + "\\0.random_big_objects");
    testerSortRandomBigObjects.SetMaxTests(6);
    testerSortRandomBigObjects.RunTasks(SortType_t::Select);
    testerSortRandomBigObjects.RunTasks(SortType_t::Insert);
    testerSortRandomBigObjects.SetMaxTests(7);
    testerSortRandomBigObjects.RunTasks(SortType_t::Shell_1);
    testerSortRandomBigObjects.RunTasks(SortType_t::Shell_2);
    testerSortRandomBigObjects.RunTasks(SortType_t::Shell_3);
    testerSortRandomBigObjects.RunTasks(SortType_t::Heap);
    testerSortRandomBigObjects.RunTasks(SortType_t::std_Sort);

    Tester testerSortLettersBigObjects(&sbo, "0. Letters (big_objects)", fs::current_path().string() + "\\1.letters_big_objects");
    testerSortLettersBigObjects.SetMaxTests(6);
    testerSortLettersBigObjects.RunTasks(SortType_t::Select);
    testerSortLettersBigObjects.RunTasks(SortType_t::Insert);
    testerSortLettersBigObjects.SetMaxTests(7);
    testerSortLettersBigObjects.RunTasks(SortType_t::Shell_1);
    testerSortLettersBigObjects.RunTasks(SortType_t::Shell_2);
    testerSortLettersBigObjects.RunTasks(SortType_t::Shell_3);
    testerSortLettersBigObjects.RunTasks(SortType_t::Heap);
    testerSortLettersBigObjects.RunTasks(SortType_t::std_Sort);

    Tester testerSortSortedBigObjects(&sbo, "2. Sorted (big_objects)", fs::current_path().string() + "\\2.sorted_big_objects");
    testerSortSortedBigObjects.SetMaxTests(6);
    testerSortSortedBigObjects.RunTasks(SortType_t::Select);
    testerSortSortedBigObjects.RunTasks(SortType_t::Insert);
    testerSortSortedBigObjects.SetMaxTests(7);
    testerSortSortedBigObjects.RunTasks(SortType_t::Shell_1);
    testerSortSortedBigObjects.RunTasks(SortType_t::Shell_2);
    testerSortSortedBigObjects.RunTasks(SortType_t::Shell_3);
    testerSortSortedBigObjects.RunTasks(SortType_t::Heap);
    testerSortSortedBigObjects.RunTasks(SortType_t::std_Sort);

    Tester testerSortReversBigObjects(&sbo, "3. Revers (big_objects)", fs::current_path().string() + "\\3.revers_big_objects");
    testerSortReversBigObjects.SetMaxTests(6);
    testerSortReversBigObjects.RunTasks(SortType_t::Select);
    testerSortReversBigObjects.RunTasks(SortType_t::Insert);
    testerSortReversBigObjects.SetMaxTests(7);
    testerSortReversBigObjects.RunTasks(SortType_t::Shell_1);
    testerSortReversBigObjects.RunTasks(SortType_t::Shell_2);
    testerSortReversBigObjects.RunTasks(SortType_t::Shell_3);
    testerSortReversBigObjects.RunTasks(SortType_t::Heap);
    testerSortReversBigObjects.RunTasks(SortType_t::std_Sort);

    return 0;
}



