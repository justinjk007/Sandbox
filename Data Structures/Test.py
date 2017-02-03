from sort import Sort


def tester():
    print "Testinng started"
    unsorted = [54,545,6,547,547,87,547,0,-1,5,5,-78,-87,546]
    obj = Sort(unsorted)
    sortedData = obj.insertionSort()
    for val in sortedData:
        print val + ","
