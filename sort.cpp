#include "sort.h"
#include "moveable.h"

#include <sstream>

#include <chrono>

using ClockType = std::chrono::steady_clock;

using namespace std;

vector<std::string> Sort::Run(const vector<string> &_data, SortType_t _sortType)
{
    vector<string> res;
    if (_data.size() != 2 )
        return res;

    uint64_t N = stoull(_data.front());

    stringstream ss_in;
    ss_in.str(_data[1]);

    vector<int> array;

    array.resize(N);   // Аналог обычного массива
    for (size_t i = 0; i < N; ++i)
    {
        ss_in >> array[i];
    }

//    int *a = new int[N];
//    for (size_t i = 0; i < N; ++i)
//        ss_in >> a[i];

    std::chrono::time_point<ClockType> TimeStart = ClockType::now();

    switch (_sortType)
    {
        case SortType_t::Select:
            SortSelection<int>(array.begin(), array.end());   // array работает быстрее, чем обычный динамический массив
//            SortSelection<int>(a, a+N);
        break;
        case SortType_t::Insert:
            SortInsert<int>(array.begin(), array.end());
//            SortInsert<int>(a, a+N);
        break;
        case SortType_t::Shell_1:
            SortShell_1<int>(array.begin(), array.end());
//            SortShell_1<int>(a, a+N);
        break;
        case SortType_t::Shell_2:
            SortShell_2<int>(array.begin(), array.end());
//            SortShell_1<int>(a, a+N);
        break;
        case SortType_t::Shell_3:
            SortShell_3<int>(array.begin(), array.end());
//            SortShell_1<int>(a, a+N);
        break;
        case SortType_t::Heap:
            SortHeap<int>(array.begin(), array.end());
//            SortHeap<int>(a, a+N);
        break;
        case SortType_t::std_Sort:
            sort(array.begin(), array.end());
//            sort(a, a+N);
        break;

    }

    std::chrono::time_point<ClockType> TimeEnd = ClockType::now();
    double Time = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(TimeEnd - TimeStart).count();
    Time /= 1.0e9;

    stringstream ss_out;
    for (size_t i = 0; i < N; ++i)
//        ss_out << a[i] << ((i==N-1)?"":" ");
        ss_out << array[i] << ((i==N-1)?"":" ");

    res.emplace_back(ss_out.str());
    res.emplace_back(to_string(Time));

//    delete[]a;

    return res;
}


vector<std::string> SortBogObjects::Run(const vector<string> &_data, SortType_t _sortType)
{
    vector<string> res;
    if (_data.size() != 2 )
        return res;

    uint64_t N = stoull(_data.front());

    stringstream ss_in;
    ss_in.str(_data[1]);

    vector<Moveable> array;

    for (size_t i = 0; i < N; ++i)
    {
        string s;
        ss_in >> s;
        array.emplace_back(s.c_str());
    }
    array.shrink_to_fit();

    std::chrono::time_point<ClockType> TimeStart = ClockType::now();

    switch (_sortType)
    {
        case SortType_t::Select:
            SortSelection<Moveable>(array.begin(), array.end());
//            SortSelection<Moveable>(a, a+N);
        break;
        case SortType_t::Insert:
            SortInsert<Moveable>(array.begin(), array.end());
//            SortInsert<Moveable>(a, a+N);
        break;
        case SortType_t::Shell_1:
            SortShell_1<Moveable>(array.begin(), array.end());
//            SortShell_1<Moveable>(a, a+N);
        break;
        case SortType_t::Shell_2:
            SortShell_2<Moveable>(array.begin(), array.end());
//            SortShell_1<Moveable>(a, a+N);
        break;
        case SortType_t::Shell_3:
            SortShell_3<Moveable>(array.begin(), array.end());
//            SortShell_1<Moveable>(a, a+N);
        break;
        case SortType_t::Heap:
            SortHeap<Moveable>(array.begin(), array.end());
//            SortHeap<Moveable>(a, a+N);
        break;
        case SortType_t::std_Sort:
            sort(array.begin(), array.end());
//            sort(a, a+N);
        break;

    }

    std::chrono::time_point<ClockType> TimeEnd = ClockType::now();
    double Time = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(TimeEnd - TimeStart).count();
    Time /= 1.0e9;

    stringstream ss_out;
    for (size_t i = 0; i < N; ++i)
    {
//        ss_out << a[i] << ((i==N-1)?"":" ");
        ss_out << array[i] << ((i==N-1)?"":" ");
    }

    res.emplace_back(ss_out.str());
    res.emplace_back(to_string(Time));

//    delete[]a;

    return res;
}

