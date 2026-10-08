#include <iostream>
#include "ArrayLibrary.h"
using namespace std;
//  Array.h   // 1.5.3

// constructor

Array::Array(int newSize) {
    Size = newSize;
    ArrayItems = new int[newSize];
}

// getlength  , getSize

int Array::getlength() { return length; }
int Array::getSize() { return Size; }

// fill

void Array::fill(int NumberOfItems) {
    if (NumberOfItems == -1) { NumberOfItems = Size; }
    if (NumberOfItems < 0 || NumberOfItems > Size) { return; }
    for (int item = 0; item < NumberOfItems; item++) {
        cin >> ArrayItems[item];
        length++;
    }
}

// display

void Array::display(int start, int stop, int step) {
    {
        // Validation

        if (step < 0) { cout << "Parameter 'Step' must be greater than 0 ..!?"; return; }
        if (start > length) { while (start > length) { start -= length; } }
        if (stop > length) { while (stop > length) { stop -= length; } }
        if (start < 0) { while (start < 0) { start += length; } }
        if (stop < 0) { while (stop < 0) { stop += length; } }

        // show all items

        if (start == 0 && stop == 0) {
            for (int item = start; item < length; item += step) {
                cout << ArrayItems[item] << endl;
            }
        }
        // show range of items reversliy .

        else if (start > stop && stop > 0) {
            for (int item = start; item >= stop; item -= step) {
                cout << ArrayItems[item] << endl;
            }
        }

        // show range of items.

        else if (start != 0 && stop != 0) {
            for (int item = start; item <= stop; item += step) {
                cout << ArrayItems[item] << endl;
            }
        }

        // show one item.

        else if (start != 0) { cout << ArrayItems[start] << endl; }

        else { cout << "Invalid Input\n"; return; }
    }
}

// Delete

void Array::Delete(int start, int stop, int step) {

    // Validation

    if (step < 0) { cout << "Parameter 'Step' must be greater than 0 ..!?"; return; }
    if (start > length) { while (start > length) { start -= length; } }
    if (stop > length) { while (stop > length) { stop -= length; } }
    if (start < 0) { while (start < 0) { start += length; } }
    if (stop < 0) { while (stop < 0) { stop += length; } }

    // delete all items.

    if (start == 0 && stop == 0) {
        for (int item = start; item < length; item += step) {
            ArrayItems[item] = 0;
        }
        length = 0;
    }


    // delete range of items.

    else if (start != 0 && stop != 0) {
        for (int item = stop; item >= start; item -= step) {
            reverseShift(start);
            length--;
        }
    }

    // delete one item.

    else if (start != 0 && stop == 0) {
        reverseShift(start);
        length--;
    }

    else {
        cout << "Invalid Input ..!?\n";
    }
}

// push

void Array::push(int item) {
    if (isFull()) { int size = Size++;  enLarge(size); }
    ArrayItems[length++] = item;
}

// shift

void Array::shift(int Index) {
    if (isFull()) { return; }
    for (int item = length; item > Index; item--) {
        ArrayItems[item] = ArrayItems[item - 1];
    }
    length++;
}

// reverseShift

void Array::reverseShift(int Index) {
    if (isFull()) { return; }
    for (int item = Index; item < length; item++) {
        ArrayItems[item] = ArrayItems[item + 1];
    }
    length--;
}

// islEmpty

bool Array::isEmpty() { return length == 0; }

// isFull

bool Array::isFull() { return length == Size; }

// enlarge 

void Array::enLarge(int size) {
    int* old = new int[Size];
    for (int i = 0; i < Size; i++) {
        old[i] = ArrayItems[i];
    }

    ArrayItems = new int[size];

    for (int i = 0; i < size; i++) {
        ArrayItems[i] = old[i];
    }


    delete[] old;
    Size = size;
}

// replace

void Array::replace(int item, int index) {
    ArrayItems[index] = item;
}

// search

int Array::search(int wantedItem) {
    int Index = -1;
    for (int item = 0; item < length; item++) {
        if (ArrayItems[item] == wantedItem) { Index = item; }
    }
    return Index;
}

// insert

void Array::insert(int newItem, int wantedIndex) {
    int search = Array::search(wantedIndex);
    if (wantedIndex > length || wantedIndex < (length * -1)) { return; }
    if (wantedIndex < 0) { wantedIndex += length; }
    if (search == -1) { return; }
    Array::shift(wantedIndex);
    ArrayItems[wantedIndex] = newItem;
}

// merge

void Array::merge(Array secondArray) {

    int newSize = Size + secondArray.getSize();
    int newLength = length + secondArray.getlength();
    enLarge(newSize);
    for (int item = length; item < newLength; item++) {
        ArrayItems[item] = secondArray.ArrayItems[item - length];
    }
    length = newLength;
}