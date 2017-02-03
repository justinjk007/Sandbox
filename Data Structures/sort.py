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
