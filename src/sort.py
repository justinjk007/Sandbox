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
    "Implements Heapsort for min heap"


    def minHeapify(i):  # O(log n)
        "This method maintains the Heap property of the heap from root i"
        l = left(i)
        r = right(i)
        if l < len(heap) and heap[l] < heap[i]:
            small = l
        else:
            small = i
        if r < len(heap) and heap[i] < heap[small]:
            small = r
        if small != i:
            swap(heap, i, small)
            minHeapify(small)   # minheapify from node = small

    def buildHeap():  # O(n)
        ArraySize = len(heap)
        start = int(math.floor(ArraySize/2))
        for i in range(start, 1, -1):
            minHeapify(i)

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
        # print i, j
        data[i], data[j] = data[j], data[i]  # do THE swap
        return data

    heap = [None] + heap
    buildHeap()
    heapSize = len(heap) - 1
    for i in range (heapSize, 2, -1):
        swap(heap, 1, i)
    minHeapify(1)
    heap.pop(0)
    return heap


def compare(list1, list2):
    if(len(list1) == len(list2)):
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
