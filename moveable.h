#ifndef MOVEABLE_H
#define MOVEABLE_H


#define MOVE_ENABLED

extern bool IsDebugOutput;

#define MY_DEBUG_ONLY(x) { if(IsDebugOutput) {x}  }

#include <iostream>

class Moveable
{
private:
    char *s = nullptr;

public:
    Moveable();

    Moveable(const char *_s);

    Moveable(const Moveable& ob);

    Moveable& operator=(const Moveable& ob);

#ifdef MOVE_ENABLED
    // пусто         данные
    Moveable(Moveable&& ob) noexcept;
    // данные                  данные
    Moveable& operator=(Moveable&& ob) noexcept;
#endif
    ~Moveable();

    void PrintMe() &;
    void PrintMe() &&;

    friend std::ostream & operator<<(std::ostream &s, const Moveable &ob);
    friend bool operator<(const Moveable &a, const Moveable &b);
};


#endif // MOVEABLE_H
