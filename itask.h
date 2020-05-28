// Header-only library for otus-algo homework testing
// Written by Sergey Tsynikin, 2020

#ifndef ITASK_H
#define ITASK_H

#include <string>
#include <vector>
#include <functional>

enum class SortType_t
{
    Select,
    Insert,
    Shell_1,
    Shell_2,
    Shell_3,
    Heap,
    std_Sort
};


class ITask
{
public:
    virtual std::vector<std::string> Run(const std::vector<std::string> &_data, SortType_t _sortType) = 0;

    virtual ~ITask() {};
};



#endif // ITASK_H
