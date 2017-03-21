#!/usr/bin/env python2.7
import collections
import math
compare = lambda x, y: collections.Counter(x) == collections.Counter(y)


def insertionSort(data):
    "Implements Insertion sort"
    size = len(data)
    for i in range(0, size):
        CurrentItem = data[i]
        # j is the divider of the sorted and unsorted portion
        j = i-1
        while j >= 0 and data[j] > CurrentItem:
            data[j+1] = data[j]  # Swap happens here.
            j = j-1  # incrementing the divider because we swapped values
            data[j+1] = CurrentItem
        return data  # Method ends here


def heapSort(heap):  # O(n log n)
    "Implements Heapsort for min heap"

    heap.append(0)

    def minHeapify(heap, i):  # O(log n)
        "This method maintains the Heap property of the heap from root i"
        l = left(i)
        r = right(i)
        if l < len(heap) and heap[l] > heap[i]:
            large = l
        else:
            large = i
        if r < len(heap) and heap[i] > heap[large]:
            large = r
        if large != i:
            swap(heap, i, large)
            minHeapify(heap, large)

    def buildHeap(Array):  # O(n)
        ArraySize = len(Array)
        for i in range(ArraySize/2, 1, -1):
            minHeapify(Array, i)
        return Array

    def parent(i):
        "Returns the index of the parent element of the child node i"
        return math.floor(i/2)

    def left(i):
        "Returns the index of the left element of the parent node i"
        return 2*i

    def right(i):
        "Returns the index of the right element of the parent node i"
        return (2*i)+1

    def swap(data, i, j):
        "This method swaps the two points i and j in the list data"
        print i, j
        data[i], data[j] = data[j], data[i]  # do THE swap
        return data

    heap = buildHeap(heap)
    heapSize = len(heap)
    for i in range (heapSize, 2, -1):
        swap(heap, 1, i)
    heap = minHeapify(heap, 1)
    return heap


def main():  # Tester
    "This is the main method and the beginning of the program"
    print ""
    print "Unsorted array: ",
    unsorted = [54, 587, 5, -545, 545, 47, 2, -54, 0, 0, 1, 2]
    print unsorted

    sortedData = heapSort(unsorted)

    print "======> Lenth of the array is: "+str(len(sortedData))
    print("Sorted array: "),
    print sortedData
    if compare(sortedData, [54, 587, 5, -545, 545, 47, 2, -54, 0, 0, 1, 2]):
        print "======> Sorting was successful"
    else:
        print "======> SORTING FAILED!!"


if __name__ == "__main__":
    main()
