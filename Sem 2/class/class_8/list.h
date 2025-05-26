#pragma once
#include "Object.h"

class List {
protected:
    Object** data;
    int size;
    int cur;
public:
    List(int);
    ~List();
    void Add(void);
    void Del();
    void Show();
    int operator()();
    void HandleEvent(const TEvent& event);
};