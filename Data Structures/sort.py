class Sort(object):

    def __init__(self, unsortedData=[]):
        self.data = unsortedData

    def insertionSort(self):
        print "sorting started"
        size = len(self.data)
        for i in range(0, size):
            print "sorting"
            cur = self.data[i]
            j = i-1
            while j >= 0 and self.data[j] > cur:
                self.data[j+1] = self.data[j]
                j = j-1
            self.data[j+1] = cur
        return self.data


# def tester():
print "Testing started"
unsorted = [54,545,6,547,547,87,547,0,-1,5,5,-78,-87,546]
obj = Sort(unsorted)
sortedData = obj.insertionSort()
for val in sortedData:
    print (str(val), ",")
