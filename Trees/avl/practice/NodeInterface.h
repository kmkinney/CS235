#pragma once

class NodeInterface{
    public:
        NodeInterface(){}
        virtual ~NodeInterface(){}
        virtual int getData() const = 0;
        virtual NodeInterface * getLeft() const = 0;
        virtual NodeInterface * getRight() const = 0;
};