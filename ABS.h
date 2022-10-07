#ifndef STACKS_AND_QUEUES_ABS_H
#define STACKS_AND_QUEUES_ABS_H

#include <iostream>

using namespace std;

template<typename T>
struct ABS {
    ABS();

    ABS(int capacity);

    ABS(const ABS &d);

    ABS &operator=(const ABS &d);

    ~ABS();

    void push(T data);

    T pop();

    T peek();

    unsigned int getSize();

    unsigned int getMaxCapacity();

    T *getData();

    float *theArray;
    int _size = 0;
    int _capacity = 1;
    float value = 0.0f;
};

// Default Constructor
//Maximum capacity is set to 1, and current size set to 0.
template<typename T>
ABS<T>::ABS() {
    theArray = new float[_capacity];
    _size = 0;
}

// Constructor for an ABS with the specified starting maximum capacity.
template<typename T>
ABS<T>::ABS(int capacity) {
    _capacity = capacity;
    theArray = new float[_capacity];
    _size = 0;
}

// Copy Constructor
template<typename T>
ABS<T>::ABS(const ABS &d) {
    this->_capacity = d._capcity;
    this->_size = d._size;

    theArray = new float[_capacity];
    for (int i = 0; i < _size; i++) {
        theArray[i] = d.theArray[i];
    }

}

// Assignment operator
template<typename T>
ABS<T> &ABS<T>::operator=(const ABS &d) {
    delete[] theArray;
    this->_capacity = d._capcity;
    this->_size = d._size;
    theArray = new float[_capacity];
    for (int i = 0; i < _size; i++) {
        theArray[i] = d.theArray[i];
    }
    return *this;
}


// Destructor
template<typename T>
ABS<T>::~ABS() {
    delete[] theArray;
}

// Add a new item to the top of the stack and resize necessary
template<typename T>
void ABS<T>::push(T data) {
    if (_size == _capacity) {
        _capacity = _capacity * 2;
        float *newArray = new float[_capacity];
        for (int i = 0; i < _size; i++) {
            newArray[i] = theArray[i];
        }
        delete[] theArray;
        theArray = new float[_capacity];
        for(int i = 0; i < _size; i++) {
            theArray[i] = newArray[i];
        }
        delete[] newArray;
    }
    _size++;
    theArray[_size - 1] = data;

}

// Return the item at the top of the stack, resizes if necessary, and return the value removed.
// Throws a runtime_error if the stack is empty.
template<typename T>
T ABS<T>::pop() {
    if (_size == 0) {
        throw runtime_error("An error has occurred.");
    }
    value = theArray[(_size - 1)];
    _size--;
    if (((float)_size / (float)_capacity) < (1/2.0f)) {
        _capacity = _capacity / 2;
        float *newArray = new float[_capacity];
        for (int i = 0; i < _size; i++) {
            newArray[i] = theArray[i];
        }
        delete[] theArray;
        theArray = new float[_capacity];
        for(int i = 0; i < _size; i++) {
            theArray[i] = newArray[i];
        }
        delete[] newArray;
    }

    return value;

}

// Return the value of the item at the top of the stack, without removing it.
// Throws a runtime_error if the stack is empty.
template<typename T>
T ABS<T>::peek() {
    if (_size == 0) {
        throw runtime_error("An error has occurred.");
    }
    return theArray[_size - 1];
}

// Returns the current number of items in the ABS.
template<typename T>
unsigned int ABS<T>::getSize() {
    return _size;
}

// Returns the current max capacity of the ABS.
template<typename T>
unsigned int ABS<T>::getMaxCapacity() {
    return _capacity;
}

// Returns the array representing the stack.
template<typename T>
T *ABS<T>::getData() {
    return theArray;
}
#endif //STACKS_AND_QUEUES_ABS_H