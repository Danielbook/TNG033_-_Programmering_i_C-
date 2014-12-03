/***************************************************************************
* TNG033, Lesson 2                                                         *
* Source file set.cpp                                                      *
* **************************************************************************/

#include "set.h"

Set::Set(int n){

    if(n <= 0){
        capacity = DEFAULT_SIZE;
    }
    else{
        capacity = n;
    }

    V = new (nothrow) bool[capacity + 1];

    if(!V)
    {
        capacity = 0;
    }
    
    for(int i = 0; i <= capacity; i++)
    {
        V[i] = false;
    }
    
    V[n] = true;
}

Set::Set(){
    
}

//ADD implementation od Set member functions



