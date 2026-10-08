#ifndef ARRAYLIBRARY_H
#define ARRAYLIBRARY_H

class Array {
    int Size;
    int length;
    int* ArrayItems;
public:
    Array(int newSize = 5);
    int getlength();
    int getSize();
    void append(int newItem);
    void sort();
    void display(int start = 0, int stop = 0, int step = 1);
    void Delete(int start = 0, int stop = 0, int step = 1);
    void replace(int newItem, int wantedIndex);
    void insert(int newItem, int wantedIndex);
    void reverseShift(int startShiftIndex);
    void shift(int startShiftIndex);
    int search(int WantedItem);
    void push(int newItem);
    void enLarge(int newSize);
    void merge(Array secondArray);
    void append();
    void pop();
    void fill(int NumberOfItems = -1);
    bool isEmpty();
    bool isFull();
    ~Array();
};
#endif // !ARRAY_H
