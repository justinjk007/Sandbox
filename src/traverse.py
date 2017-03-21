#!/usr/bin/env python2.7

# Author : Justin Kaipada
# Data   : 21-03-2017
# Purpose: Traversal reversal and constructing all other traversal

result = []
tempData = []


def preOrder(data, node):
    "This method prints the pre-order traversal of the binary tree"
    if node <= len(data) - 1:
        print data[node],            # Print the element at the node
        preOrder(data, left(node))   # Traverse the left subtree
        preOrder(data, right(node))  # Traverse the right subtree


def postOrder(data, node):
    "This method prints the post-order traversal of the binary tree"
    if node <= len(data) - 1:
        postOrder(data, left(node))   # Traverse the left subtree
        postOrder(data, right(node))  # Traverse the right subtree
        print data[node],             # Print the element at the node


def inOrder(data, node):
    "This method prints the in-order traversal of the binary tree"
    if node <= len(data) - 1:
        inOrder(data, left(node))    # Traverse the left subtree
        print data[node],            # Print the element at the node
        inOrder(data, right(node))   # Traverse the right subtree


def preOrderToArray(data, node):
    "This method returns original array of the passed preorder traversal"
    global tempData  # Stores the same array as a copy
    global result    # Stores the result of the reversal of given traversal
    if node <= len(data)-1:
        # Pop the 1st element of the array and add it to visited node in result
        result[node] = tempData.pop(0)
        preOrderToArray(data, left(node))
        preOrderToArray(data, right(node))


def postOrderToArray(data, node):
    "This method returns original array of the passed post-order traversal"
    global tempData  # Stores the same array as a copy
    global result    # Stores the result of the reversal of given traversal
    if node <= len(data) - 1:
        postOrderToArray(data, left(node))
        postOrderToArray(data, right(node))
        # Pop the 1st element of the array and add it to visited node in result
        result[node] = tempData.pop(0)


def inOrderToArray(data, node):
    "This method returns original array of the passed in-order traversal"
    global tempData  # Stores the same array as a copy
    global result    # Stores the result of the reversal of given traversal
    if node <= len(data) - 1:
        inOrderToArray(data, left(node))
        # Pop the 1st element of the array and add it to visited node in result
        result[node] = tempData.pop(0)
        inOrderToArray(data, right(node))


def left(i):
    "Returns the index of the left element of the parent node at i"
    return 2*i


def right(i):
    "Returns the index of the right element of the parent node at i"
    return (2*i)+1


def main():
    "This is the main method and the beginning of the program"
    print ""
    global result    # Stores the result of reversed array
    global tempData  # Stores the main array temporarily for reconstructing
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    tempData = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    # tempData = list(data)
    print "We have this array as our input"
    print data
    data = [None] + data  # Make the given array into a workable tree
    result = [None] * len(data)
    print "Please select the order of the above array by entering the corresponding number"
    print "1. pre-order"
    print "2. post-order"
    print "3. in-order"
    option = input()
    if option == 1:
        preOrderToArray(data, 1)
        print "The post-order of the array is: ",
        postOrder(result, 1)
        print ""
        print "The in-order of the array is: ",
        inOrder(result, 1)
    elif option == 2:
        postOrderToArray(data, 1)
        print "The in-order of the array is: ",
        inOrder(result, 1)
        print ""
        print "The pre-order of the array is: ",
        preOrder(result, 1)
    elif option == 3:
        inOrderToArray(data, 1)
        print "The pre-order of the array is: ",
        preOrder(result, 1)
        print ""
        print "The post-order of the array is: ",
        postOrder(result, 1)
    else:
        print "Incorrect inputs.."


if __name__ == "__main__":
    main()
