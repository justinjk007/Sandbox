import collections
compare = lambda x,y: collections.Counter(x) == collections.Counter(y)

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
    
def HeapSort(data):
    "Implements Heapsort"
    #TODO


def main():
    "This is the main method and the beginning of the program"
    print ""
    unsorted = [54, 587, 5, -545, 545, 47, 2, -54, 0, 0, 1, 2]
    print("Unsorted array: "),
    for val in unsorted:
        print(str(val) + ","),
    sortedData = insertionSort(unsorted)
    print("\n ======> Lenth of the array is: "+str(len(sortedData)))
    print("Sorted array: "),
    for val in sortedData:
        print(str(val) + ","),
        # The comma on the end of the line 26 makes the printing at the same line

    if(compare(sortedData, [54, 587, 5, -545, 545, 47, 2, -54, 0, 0, 1, 2])):
        print "\n ======> Sorting was successful"
    else:
        print "\n ======> SORTING FAILED!!"


if __name__ == "__main__":
    main()
