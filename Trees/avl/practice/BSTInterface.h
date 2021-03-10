#pragma once
#include "NodeInterface.h"

class BSTInterface{
    public:
        BSTInterface(){}
        virtual ~BSTInterface(){}

        virtual bool add(int value) = 0;

        virtual bool remove(int value) = 0;

        virtual NodeInterface * getRoot() const = 0;

        virtual int getHeight() const = 0;

};
