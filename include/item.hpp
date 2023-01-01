#include<string>

#ifndef ITEM_H
#define ITEM_H

class Item {
    protected:
        int key;
    public:
        Item();
        ~Item();
        int getKey();
        virtual void generate(int val);
        void setKey(int val);
        void gentest(int val);
};



#endif