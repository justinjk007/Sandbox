#!/usr/bin/env python2.7
import collections
import math


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
    "Implements Heapsort for max heap, sorting in ascending order"

    def maxHeapify(heap, i, size):  # O(log n)
        "This method maintains the Heap property of the heap from root i"
        l = left(i)
        r = right(i)
        if l <= size and heap[l] > heap[i]:
            large = l
        else:
            large = i
        if r <= size and heap[r] > heap[large]:
            large = r
        if large != i:
            swap(heap, i, large)
            maxHeapify(heap, large, size)   # minheapify from node = large

    def buildHeap(heap):  # O(n)
        "This method builds a min heap, with largest element at index 1/root"
        ArraySize = len(heap)-1
        start = int(math.floor(ArraySize/2))
        for i in range(start, 0, -1):
            maxHeapify(heap, i, ArraySize)

    def left(i):
        "Returns the index of the left element of the parent node i"
        return 2*i

    def right(i):
        "Returns the index of the right element of the parent node i"
        return (2*i)+1

    def swap(data, i, j):
        "This method swaps the two points i and j in the list data"
        data[i], data[j] = data[j], data[i]  # do THE swap
        return data

    heap = [None] + heap
    buildHeap(heap)
    heapSize = len(heap)-1
    # Here we are reducing the heapsize until to zero, removing the
    # sorted value from the heap each time
    for i in range(heapSize, 1, -1):
        swap(heap, 1, i)
        heapSize -= 1
        maxHeapify(heap, 1, heapSize)
    heap.pop(0)          # Remove the None value that was added for ordering
    return heap


def compare(list1, list2):
    if len(list1) == len(list2):
        pass
    else:
        return False
    for i in range(0, len(list1)):
        if(list1[i] == list2[i]):
            pass
        else:
            return False
    return True


def main():  # Tester
    "This is the main method and the beginning of the program"
    print ""
    unsorted = [54, 587, 5, -545, 545, 47, 2, -54, 0, 0, 1, 2]
    print "======> Lenth of the array is: "+str(len(unsorted))
    print "Unsorted array:",
    print unsorted

    sortedData = heapSort(unsorted)    # Change the sorting here

    print "Expected output:[-545, -54, 0, 0, 1, 2, 2, 5, 47, 54, 545, 587]"
    print ("Sorted array:  "),
    print sortedData
    if compare(sortedData, [-545, -54, 0, 0, 1, 2, 2, 5, 47, 54, 545, 587]):
        print "======> Sorting was SUCCESSFUL"
    else:
        print "======> Sorting FAILED!!"


if __name__ == "__main__":
    main()
