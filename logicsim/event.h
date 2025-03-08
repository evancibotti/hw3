#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(const Event* left, const Event* right){
          // return true if left is greater than right and false if not
            return left->time > right->time; 
        }
} EventLess;
	
#endif
