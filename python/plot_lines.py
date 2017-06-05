import sys
import csv
import math
import matplotlib.pyplot as plt


def parse(file_name):
    "Parses the data sets from the csv file we are given to work with"
    file = open(file_name)
    rawFile = csv.reader(file)    # Reading the csv file into a raw form
    rawData = list(rawFile)       # Converting the raw data into list from.
    file.close()
    return rawData

def draw(xCords, yCords, xLabel, yLabel, filename):
    plt.xlabel(xLabel)
    plt.ylabel(yLabel)
    plt.title("Pentagon - "+filename)
    plt.plot(xCords, yCords, '-o', color="r")

def toXandY(unorderedData):
    "This method converts seperates x and y co-ordinates for plotting"
    orderedData = []
    orderedData.append([])        # Add a new sublist every time
    orderedData.append([])        # Add a new sublist every time
    listSize = len(unorderedData)
    for x in range(0, listSize):
        orderedData[0].append(unorderedData[x][0])  # Seperates the x-cords
    for y in range(0, listSize):
        orderedData[1].append(unorderedData[y][1])  # Seperates the y-cords
    return orderedData

def main():
    newData = []
    file_name = "example.csv"
    data = parse(file_name)   # Calling the parse funtion we made
    labels = data.pop(0)            # Necessary evil
    listSize = len(data)
    for i in range(0, listSize):    # Converting the string list to float
        newData.append([])          # Add a new sublsit every time
        for j in range(0, 2):       # Append converted data to the new list
            newData[i].append(float(data[i][j]))
            # Finding the starting point P
    DataXandY = toXandY(newData)     # DataXandY -> [[Xs][Ys]]
    draw(DataXandY[0], DataXandY[1], labels[0], labels[1], file_name)
    plt.show()


if __name__ == "__main__":
    main()
