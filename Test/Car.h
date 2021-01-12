#pragma once
class Car{
    private:
        int year;
    public:
        Car(int y = 2000): year(y){};
        void printYear() const;
};