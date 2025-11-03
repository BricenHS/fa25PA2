//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        //size index at end
        data[size] = idx;
        //restore order
        upheap(size, weightArr);
        //make size up
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index

        if (size == 0) return -1;
        //check for smallest index
        int minIdx = data[0];
        //make size smaller
        size--;
        //data[0] is or at least should be the root and then once it is replaced downheap is called
        if (size >0) {
            data[0] = data[size];
            downheap(0, weightArr);
        }
        return minIdx;
        // Replace root with last element, then call downheap()
        // return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        //define the parent position and then check the postition, if it is smaller
        //than the parent than swap them
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            } else break;        }

    }


    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        //I needed to check to make sure that any children mean left and right ones, that the parent has is smaller than it
        //and if the parent is larger than to swap it
        while (true) {
            int left = 2*pos+1;
            int right = 2*pos+2;
            int smallest = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
                smallest = left;
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
                smallest = right;

            if (smallest != pos) {
                swap(data[pos], data[smallest]);
                pos = smallest;
                } else break;
            }


        }
};

#endif