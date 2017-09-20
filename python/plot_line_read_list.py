import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)

def draw(xCords, yCords, filename, col):
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title(filename)
    plt.plot(xCords, yCords, '-o', color=col, markersize = 1, linewidth = 2)
    for xy in zip(xCords, yCords): # If you don't want the co-ordinates to show up delete this loop
        ax.annotate('(%s, %s)' % xy, xy=xy, textcoords='data')

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

def plotLines(data):
    "Pass list of points to this method, two consecutive points must be a line"
    newData = []
    line_x = []
    line_y = []
    file_name = "file"
    list_size = len(data)
    for i in range(0, list_size):    # Converting the string list to float
        newData.append([])          # Add a new sublsit every time
        for j in range(0, 2):       # Append converted data to the new list
            newData[i].append(float(data[i][j]))
    DataXandY = toXandY(newData)     # DataXandY -> [[Xs][Ys]]
    while len(DataXandY[0]) != 0:
        # Pop two points to form a line
        line_x.append(DataXandY[0].pop(0))
        line_y.append(DataXandY[1].pop(0))
        line_x.append(DataXandY[0].pop(0))
        line_y.append(DataXandY[1].pop(0))
        draw(line_x, line_y, file_name, "g")
        line_x[:] = []          # Delete the contents
        line_y[:] = []          # Delete the contents

    plt.gca().set_aspect('equal', adjustable='box')
    plt.show()

def main():
    data = [[5.09,5.80], [1.68,4.90],[1.68,4.90], [1.48,1.38],[1.48,1.38], [4.76,0.10],[4.76,0.10], [7.00,2.83],[7.00,2.83],[5.09,5.80]]
    plotLines(data)
    # Plot pentagon


if __name__ == "__main__":
    main()
