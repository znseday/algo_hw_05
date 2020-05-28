#ifndef TEST_GENERATOR_H
#define TEST_GENERATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr size_t LEN_STR = 64;

void GenTestRandom(size_t N)
{
    size_t M = pow(10, N);
    vector<string> v;
    v.reserve(M);

    ofstream f_in("0.random_big_objects\\test." + to_string(N) + ".in");
    if (!f_in)
    {
        cout << "Error" << endl;
        exit(0);
    }

    f_in << M << endl;

    for (size_t i = 0; i < M; ++i)
    {
        string r(LEN_STR, 'A');
        for (auto &c : r)
            c = 'A' + rand()%26;

        f_in << r << ((i==M-1)?"":" ");
        v.emplace_back(r);
    }
    f_in.close();

    sort(v.begin(), v.end());

    ofstream f_out("0.random_big_objects\\test." + to_string(N) + ".out");
    for (size_t i = 0; i < M; ++i)
        f_out << v[i] << ((i==M-1)?"":" ");

    f_out.close();
}

void GenTestSameLetters(size_t N)
{
    size_t M = pow(10, N);
    vector<string> v;
    v.reserve(M);

    ofstream f_in("1.letters_big_objects\\test." + to_string(N) + ".in");
    if (!f_in)
    {
        cout << "Error" << endl;
        exit(0);
    }

    f_in << M << endl;

    for (size_t i = 0; i < M; ++i)
    {
        char c = 'A' + rand()%26;
        string r(LEN_STR, c);

        f_in << r << ((i==M-1)?"":" ");
        v.emplace_back(r);
    }
    f_in.close();

    sort(v.begin(), v.end());

    ofstream f_out("1.letters_big_objects\\test." + to_string(N) + ".out");
    for (size_t i = 0; i < M; ++i)
        f_out << v[i] << ((i==M-1)?"":" ");

    f_out.close();
}

void GenTestAllmostSorted(size_t N)
{
    size_t M = pow(10, N);
    vector<string> v;
    v.reserve(M);

    ofstream f_in("2.sorted_big_objects\\test." + to_string(N) + ".in");
    f_in << M << endl;
    if (!f_in)
    {
        cout << "Error" << endl;
        exit(0);
    }

    for (size_t i = 0; i < M; ++i)
    {
        string r(LEN_STR, 'A');
        for (auto &c : r)
            c = 'A' + rand()%26;

        v.emplace_back(r);
    }

    sort(v.begin(), v.end());

    for (size_t i = 0; i < M; ++i)
    {
        if (rand()%100 == 0)
            swap(v[rand()/(double)RAND_MAX*(M-1)], v[rand()/(double)RAND_MAX*(M-1)]);
    }

    ofstream f_out("2.sorted_big_objects\\test." + to_string(N) + ".out");
    for (size_t i = 0; i < M; ++i)
        f_in << v[i] << ((i==M-1)?"":" ");

    sort(v.begin(), v.end());
    for (size_t i = 0; i < M; ++i)
        f_out << v[i] << ((i==M-1)?"":" ");

    f_in.close();
    f_out.close();
}

void GenTestRevers(size_t N)
{
    size_t M = pow(10, N);
    vector<string> v;
    v.reserve(M);

    ofstream f_in("3.revers_big_objects\\test." + to_string(N) + ".in");
    f_in << M << endl;
    if (!f_in)
    {
        cout << "Error" << endl;
        exit(0);
    }

    for (size_t i = 0; i < M; ++i)
    {
        string r(LEN_STR, 'A');
        for (auto &c : r)
            c = 'A' + rand()%26;

        v.emplace_back(r);

    }

    sort(v.begin(), v.end(), greater<string>());

    ofstream f_out("3.revers_big_objects\\test." + to_string(N) + ".out");
    for (size_t i = 0; i < M; ++i)
        f_in << v[i] << ((i==M-1)?"":" ");

    sort(v.begin(), v.end());
    for (size_t i = 0; i < M; ++i)
        f_out << v[i] << ((i==M-1)?"":" ");

    f_in.close();
    f_out.close();
}

#endif // TEST_GENERATOR_H
