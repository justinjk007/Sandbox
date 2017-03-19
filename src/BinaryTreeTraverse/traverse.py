#!/usr/bin/env python2.7
import math
# Instead of making many methods to convert back and forth
# from everything make a method to covert to pre-order first, this way
# you only have to write four methods, post to pre, in to pre, pre to
# post, pre to in

# Unless we assume we have a complete binary tree we have no way of approaching this


def preOrder(data, order):
    "This method returns the pre-order traversal of the binary tree"

    def postToPre(data):
        pass

    def inToPre(data):
        pass

    if order == 'post-order':
        postToPre(data)
    elif order == 'in-order':
        inToPre(data)
    else:
        print "Unexpected inputs"


def postOrder(data, root=1):
    "This method returns the post-order traversal of the binary tree"
    size = len(data)
    if(root > size):
        return


def inOrder(data):
    "This method returns the in-order traversal of the binary tree"
    #TODO


def parent(i):
    "Returns the index of the parent element of the child node at i"
    return math.floor(i/2)


def left(i):
    "Returns the index of the left element of the parent node at i"
    return 2*i


def right(i):
    "Returns the index of the right element of the parent node at i"
    return (2*i)+1


def swap(data, i, j):
    "This method swaps the two points i and j in the list data"
    data[i], data[j] = data[j], data[i]  # do THE swap
    return data


def main(data, order):
    "This is the main method and the beginning of the program"
    null = None
    data = [null] + data  # Make the given array into a workable tree
    if order == "pre-order":
        inOrder(data, order)
        postOrder(data, order)
    elif order == "post-order":
        inOrder(data, order)
        preOrder(data, order)
    elif order == "in-order":
        postOrder(data, order)
        preOrder(data, order)
    else:
        print "Incorrect inputs.."


testList = [1, 2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12]
if __name__ == "__main__":
    main(testList, "pre-order")
