#pragma once

template <class T>
class List
{
    private:
        T element;
    public:
        void put(T arg){element = arg;}
        T get(){return element;}

};