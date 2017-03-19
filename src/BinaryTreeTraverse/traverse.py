#!/usr/bin/env python2.7
import math


def preOrder(data, order):
    "This method returns the pre-order traversal of the binary tree"
    #TODO


def postOrder(data, order):
    "This method returns the post-order traversal of the binary tree"
    #TODO


def inOrder(data, order):
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
