#!/usr/bin/env python2.7
import collections
import math

def insertionSort(data, base):
    '''
    This method sorts the array using insertion sort, the sort is special
    because it sorts the data based on the given base, not the data itself.
    Here it sorts the data based on the slope array passed as the base
     '''
    size = len(base)
    for i in range(1, size):
        CurrentItem = base[i]
        # j is the divider of the sorted and unsorted portion
        j = i-1
        while j >= 0 and base[j] > CurrentItem:
            base[j+1] = base[j]  # Swap base array
            swap(data, j+1, j)   # Swap data array
            j = j-1  # incrementing the divider because we swapped values
            base[j+1] = CurrentItem
    return data, base  # Method ends here


def heapSort(heap, base):  # O(n log n)
    "Implements Heapsort for max heap, sorting in ascending order"

    def maxHeapify(heap, base, i, size):  # O(log n)
        "This method maintains the Heap property of the heap from root i"
        l = left(i)
        r = right(i)
        if l <= size and base[l] > base[i]:
            large = l
        else:
            large = i
        if r <= size and base[r] > base[large]:
            large = r
        if large != i:
            swap(base, i, large)
            swap(heap, i, large)
            maxHeapify(heap, base, large, size)   # maxheapify from node = large

    def buildHeap(heap, base):  # O(n)
        "This method builds a min heap, with largest element at index 1/root"
        ArraySize = len(base)-1
        start = int(math.floor(ArraySize/2))
        for i in range(start, 0, -1):
            maxHeapify(heap, base, i, ArraySize)

    def left(i):
        "Returns the index of the left element of the parent node i"
        return 2*i

    def right(i):
        "Returns the index of the right element of the parent node i"
        return (2*i)+1


    heap = [None] + heap
    base = [None] + base
    buildHeap(heap, base)
    heapSize = len(base)-1
    # Here we are reducing the heapsize until to zero, removing the
    # sorted value from the heap each time
    for i in range(heapSize, 1, -1):
        swap(base, 1, i)
        swap(heap, 1, i)
        heapSize -= 1
        maxHeapify(heap, base, 1, heapSize)
    heap.pop(0)          # Remove the None value that was added for ordering
    base.pop(0)          # Remove the None value that was added for ordering
    return heap, base


def swap(data, i, j):
        "This method swaps the two points i and j in the list data"
        data[i], data[j] = data[j], data[i]  # do THE swap
        return data

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
    base = [1, 3, 4, 5, 7, 6, 8, 9, 11, 10, 12, 2]
    print "======> Lenth of the array is: "+str(len(unsorted))
    print "======> Lenth of the base is: "+str(len(base))
    print "Unsorted array:",
    print unsorted
    print "Unsorted base: ",
    print base

    sortedData, sortedBase = heapSort(unsorted, base)    # Change the sorting here

    print "Expected output:[54, 2, 587, 5, -545, 47, 545, 2, -54, 0, 0, 1]"
    print ("Sorted array:  "),
    print sortedData
    print ("Sorted Base:   "),
    print sortedBase
    if compare(sortedBase, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]):
        print "======> Sorting was SUCCESSFUL"
    else:
        print "======> Sorting FAILED!!"


if __name__ == "__main__":
    main()
