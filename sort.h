#ifndef SORT_H
#define SORT_H

#include "itask.h"

#include <sstream>
#include <chrono>
#include <cmath>

using ClockType = std::chrono::steady_clock;

template <typename V, typename T>
void SortSelection(T first, T last)
{
    for (T it = first; it != last; ++it)
    {
        T it_minV = it;
        T ind = it;
        for (T it_2 = it + 1; it_2 != last; ++it_2)
        {
            if (*it_2 < *it_minV)
            {
                it_minV = it_2;
                ind = it_2;
            }
        }
       // std::iter_swap(it, ind);
        std::swap(*it, *ind);
    }
}

template <typename V, typename T>
void SortInsert(T first, T last)
{
    V t;
    T it_2;
    for (T it = first+1; it != last; ++it)
    {
        it_2 = it;
        t = std::move(*it); // move
        while ( it_2 > first && t < *(it_2-1) )
        {
            *it_2 = std::move(*(it_2-1)); //move
            --it_2;
        }
        *it_2 = std::move(t); // move
    }
}


template <typename V, typename T>
void SortShell_1(T first, T last)
{
    for (size_t gap = std::distance(first, last); gap > 0; gap /= 2)
    {
        for (T it = first; it+gap != last; ++it)
        {
            T it_2 = it + gap;
            V t = std::move(*it_2);
            while ( it_2-gap >= first && t < *(it_2-gap) )
            {
                *it_2 = std::move(*(it_2-gap));
                it_2 -= gap;
            }
            *it_2 = std::move(t);
        }
    }
}

#include <iostream>

template <typename V, typename T>
void SortShell_2(T first, T last)
{
    size_t h = log2(2.0*std::distance(first, last) + 1.0) / log2(3.0);
    //std::cout << "gap = ";
    for (size_t k = h, gap = (pow(3, h)-1)/2;  gap > 0;  --k, gap = (pow(3, k)-1)/2)
    {
        // std::cout << gap << ((gap==1)?"":", "); // Для отладки
        for (T it = first; it+gap != last; ++it)
        {
            T it_2 = it + gap;
            V t = std::move(*it_2);
            while ( it_2-gap >= first && t < *(it_2-gap) )
            {
                *it_2 = std::move(*(it_2-gap));
                it_2 -= gap;
            }
            *it_2 = std::move(t);
        }
    }
    //std::cout << std::endl;
}

template <typename V, typename T>
void SortShell_3(T first, T last)
{
    //              // От 7174453 до 3280 как в SortShell_2.................... 1750 и до 1 "Best known, 2005-2011"
    size_t gaps[18] = {7174453, 2391484, 797161, 265720, 88573, 29524, 9841, 3280, 1750, 701, 301, 132, 57, 23, 10, 4, 1, 0};

    size_t SizeAll = (size_t)std::distance(first, last);

    size_t h;
    for (h = 0; h < 18; h++)
        if (gaps[h] < SizeAll)
            break;

    //std::cout << "gap = ";
    for (size_t k = h, gap = gaps[h];  gap > 0;  ++k, gap = gaps[k])
    {
        //std::cout << gap << ((gap==1)?"":", ");   // Для отладки
        for (T it = first; it+gap != last; ++it)
        {
            T it_2 = it + gap;
            V t = std::move(*it_2);
            while ( it_2-gap >= first && t < *(it_2-gap) )
            {
                *it_2 = std::move(*(it_2-gap));
                it_2 -= gap;
            }
            *it_2 = std::move(t);
        }
    }
    //std::cout << std::endl;
}


template <typename V, typename T>
void HeapDown(T first, T last, T root)
{
    size_t i = std::distance(first, root);
    size_t j;
    size_t n = std::distance(first, last);

    while (2*i + 1 < n)
    {
        j = 2*i + 1;
        if ( j+1 < n && *(first+j) < *(first+j+1) )
            ++j;

        if ( *(first+i) < *(first+j) )
        {
            std::iter_swap(first+i, first+j); // std::swap(*(first+i), *(first+j));
            i = j;
        }
        else
            return;
    }
}



template <typename V, typename T>
void SortHeap(T first, T last)
{
    size_t n = std::distance(first, last);

    for (int j = (n-2)/2; j >= 0; --j)
        HeapDown<V>(first, last, first + j);

//    for (auto it = first; it != last; ++it)  // для отладки
//        std::cout << *it << "  ";
//    std::cout << std::endl;

    while (n > 1)
    {
        std::iter_swap(first, first+n-1); // std::swap(*first, *(first+n-1));
        --n;
        HeapDown<V>(first, first+n, first);
    }
}
//------------------------------------------------------


class Sort : public ITask
{
public:
    virtual std::vector<std::string> Run(const std::vector<std::string> &_data, SortType_t _sortType) override;
};



class SortBogObjects : public ITask
{
public:
    virtual std::vector<std::string> Run(const std::vector<std::string> &_data, SortType_t _sortType) override;

};

#endif // SORT_H
