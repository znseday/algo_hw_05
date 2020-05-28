// Header-only library for otus-algo homework testing
// Written by Sergey Tsynikin, 2020

#ifndef TESTER_H
#define TESTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <experimental\filesystem>
#include <chrono>
#include <iomanip>
#include <list>
#include <tuple>

#include "itask.h"

namespace fs = std::experimental::filesystem;

using ClockType = std::chrono::steady_clock;



class Tester
{
protected:

    SortType_t SortType = SortType_t::Select;

    std::list<std::tuple<std::string, ITask*>> Tasks;

    std::string Path;

    ITask *ActiveTask = nullptr;

    size_t MaxTests = 10;

    void RunTests()
    {
        std::cout << std::setw(6) << "Test#" << std::setw(8) <<
                     "Status" << std::setw(14) << "Time, s" << std::endl;

        std::cout << std::boolalpha;

        for (size_t nr = 0;; ++nr)
        {
            std::string inFile  = Path + "\\test." + std::to_string(nr) + ".in";
            std::string outFile = Path + "\\test." + std::to_string(nr) + ".out";

            if ( !fs::exists(inFile) || !fs::exists(outFile) || nr >= MaxTests )
                break;

            std::cout << std::setw(6) << nr << ":" << std::endl;
            bool res_test = RunTest(inFile, outFile);
            std::cout << "Test passed: " << res_test << std::endl << std::endl;

        }
    }

    bool RunTest(const std::string &_inFile, const std::string &_outFile)
    {
        std::vector<std::string> data;
        std::string line;
        std::ifstream i_stream_in(_inFile);
        while (getline(i_stream_in, line))
            data.emplace_back(move(line));   // Уточнить можно ли повторно использовать line после move ?
//            data.emplace_back(line);

        std::vector<std::string> expects;
        std::ifstream i_stream_out(_outFile);
        while (getline(i_stream_out, line))
//            expects.emplace_back(line);
            expects.emplace_back(move(line));   // Уточнить можно ли повторно использовать line после move ?


        std::vector<std::string> results = ActiveTask->Run(data, SortType);

        std::string expect = expects.front();

        std::string actual = results.front();


        bool res_line = expect == actual;
        std::cout << std::setw(8+6) << res_line << std::setw(14) << results[1] << std::endl;

        return res_line;
    }

public:
    Tester() = delete;

    //void SetSortFunc(sortFunc_t<T> _fSort) { fSort = _fSort;}
    //void SetSortType(SortType_t _SortType) {SortType = _SortType;}

    void AddTask(ITask *_task, const std::string &_name)
    {
        Tasks.emplace_back(_name, _task);
    }

    Tester(ITask *_task, const std::string &_name, const std::string &_path) : Path(_path)
    {
        AddTask(_task, _name);
    }

    void RunTasks(SortType_t _sortType)
    {
        SortType = _sortType;
        std::string sortName;
        switch (_sortType)
        {
            case SortType_t::Select:
                sortName = "Selection Sort";
            break;
            case SortType_t::Insert:
                sortName = "Insert Sort";
            break;
            case SortType_t::Shell_1:
               sortName = "Shell Sort v.1 (N/2)";
            break;
            case SortType_t::Shell_2:
               sortName = "Shell Sort v.2 ((3^k - 1)/2)";
            break;
            case SortType_t::Shell_3:
               sortName = "Shell Sort v.3 (v.2 + \"Best known\")";
            break;
            case SortType_t::Heap:
                sortName = "Heap Sort";
            break;
            case SortType_t::std_Sort:
                sortName = "std::sort";
            break;

        }

        for (const auto [name, task] : Tasks)
        {
            std::cout << "Task - " << name << " - " << sortName << ":" << std::endl;
            ActiveTask = task;
            RunTests();
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }


    void SetMaxTests(size_t _maxTests) { MaxTests = _maxTests;}
//    void SetShowExpects(bool _showExpects) {ShowExpects = _showExpects;}
//    void SetShowActuals(bool _showActuals) {ShowActuals = _showActuals;}
//    void SetShowTime(bool _showTime) {ShowTime = _showTime;}
};

#endif // TESTER_H
