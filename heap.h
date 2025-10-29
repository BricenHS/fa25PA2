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
        upheap(idx, weightArr);
        //make size up
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index

        //check for smallest index
        int minIdx = data[0];
        //make size smaller
        size--;
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

        while (pos > 0) {
            // def the parent and child values
            int parent = (pos - 1) / 2;
            int child = 2*pos + 1;

            // check to see if child is smaller than parent, if so then swap
            if (weightArr[child] < weightArr[parent]) {
                swap(weightArr[child], weightArr[parent]);
            }
        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child

        //basically same thing for downheap as upheap
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            int child = 2*pos + 1;

            if (weightArr[child] > weightArr[parent]) {
                swap(weightArr[child], weightArr[parent]);
            }
        }

    }
};

#endif