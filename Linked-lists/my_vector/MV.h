#pragma once
#include <algorithm>
#include <sstream>
#include <string>
#include "VectorInterface.h"

template<class T>
class MV: public VectorInterface<T>{
    private:
        int spot;
        int capacity;
        const static int BASE_CAPACITY = 10;
        T *data;

        //Resizes the data array when capacity is reached
        void resize(){
            capacity *= 2;
            T *tmp = new T[capacity];
            for(int i = 0; i < spot; i++){
                tmp[i] = data[i];
            }
            delete []data;
            data = tmp;
        }
    public:
        //Constructor
        MV(void){
            spot = 0;
            capacity = BASE_CAPACITY;
            data = new T[capacity];
        }; 
        //Destructor
        ~MV(void){
            delete []data;
        };

        void push_back(T value){
            if(spot == capacity)
                resize();
            data[spot] = value;
            spot++;
        }
        
        /* Insert value after given index */
        void insertAt(int index, T value){
            if(index > spot || index < 0)
                throw out_of_range("index is out of range");
            if(spot == capacity)
                resize();
            for(int i = spot; i > index; i--){
                data[i] = data[i - 1];
            }
            data[index] = value;
            spot++;
        }

        /* Remove the element at index */
        void remove(int index){
            if(index < 0 || index >= spot)
                throw out_of_range("index is out of range");
            spot--;
            for(int i = index; i < spot;i++){
                data[i] = data[i + 1];
            }
        }
        
        T at(int index){
            if(index < 0 || index >= spot)
                throw out_of_range("index is out of range");
            return data[index];
        }

        int size(){
            return spot;
        }

        string toString(){
            stringstream ss;
            for(int i = 0; i < spot; i++){
                ss << data[i];
                if(i < spot - 1)
                    ss << ", ";
            }
            return ss.str();
        }

};