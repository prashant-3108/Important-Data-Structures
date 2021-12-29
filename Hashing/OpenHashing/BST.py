
# Binary Search Tree Node class
# This class would have the Key Stored in it and will point to its left and right children
# if there.


class BSTNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

# Binary Search Tree class
# This class would have the tree stored in the root node which is initially None
# Members -
#       root - root Node of the Tree
#       N - number of the nodes in the Tree


class BST:
    # constructor for the Class initialising root to None and N be 0
    # Time Complexity - O(1)
    def __init__(self):
        self.root = None
        self.N = 0

    # Recursive (private) Helper function to insert a node in the Tree if its not there.
    # parameters -
    #       localRoot - current Root of the Tree to be added
    #       key - key to be added
    #       isAdded - list having a False Value is set to True if node is added
    # returns -
    #       the localRoot with the new node added to it if it key was not present
    #
    # Worst Time Complexity - O(N) - if its a skewed tree 
    # Average Time Complexity - O(log(N)) - in average closer to being a complete Binary tree
    # Best Time Complexity - O(1) - root is None
    def __insert(self, localRoot, key, isAdded):
        if localRoot is None:
            self.N += 1
            isAdded[0] = True
            return BSTNode(key)
        else:
            if localRoot.val == key:
                return localRoot
            elif localRoot.val < key:
                localRoot.right = self.__insert(localRoot.right, key, isAdded)
            else:
                localRoot.left = self.__insert(localRoot.left, key, isAdded)
        return localRoot

    # Method (public) to add a key Node in the Tree
    # parameters -
    #       key - key to be added
    # returns -
    #       True if the node with key is added else False
    #
    # Uses Helper insert function so Has a similar Time Complexity - O(logN) - average
    def add(self, key):
        isAdded = [False]
        self.root = self.__insert(self.root, key, isAdded)
        return isAdded[0]

    # Recursive (private) Helper function to search a node in the Tree if its not there.
    # parameters -
    #       localRoot - the tree root in which the key is to be searched
    #       key - key to be searched
    # returns -
    #       the node of the tree which has the key value to be searched else None
    #
    # Worst Time Complexity - O(N)
    # Average Time Complexity - O(log(N))
    # Best Time Complexity - O(1) - root is has the key value
    def __search(self, localRoot, key):
        if localRoot is None or localRoot.val == key:
            return localRoot

        if localRoot.val < key:
            return self.__search(localRoot.right, key)

        return self.__search(localRoot.left, key)

    # Method (public) to search a key Node in the Tree
    # parameters -
    #       key - key to be searched
    # returns -
    #       True if the node with key is found else False
    #
    # Uses Helper Search function so Has a similar Time Complexity - O(logN) - average
    def contains(self, key):
        foundNode = self.__search(self.root, key)
        if foundNode is not None:
            return True
        else:
            return False

    # Recursive (private) Helper function to get the maximum node in the Tree .
    # parameters -
    #       localRoot - the tree root whose maximum node
    # returns -
    #       the node with the maximum Value
    #
    # Worst Time Complexity - O(N)
    # Average Time Complexity - O(log(N))
    # Best Time Complexity - O(1)
    def __getMaximumNode(self, localRoot):
        while localRoot.right is not None:
            localRoot = localRoot.right
        return localRoot

    # Method (public) to get Maximum Value in the tree
    # returns -
    #       the vaue of the key which is the maximum value in the tree or None if tree is null
    #
    # Uses Helper getMaxValue function so Has a similar Time Complexity - O(logN) - average
    def maximumValue(self):
        if self.root == None:
            return None
        else:
            return self.__getMaximumNode(self.root).val

    # Recursive (private) Helper function to get the depth of the Tree .
    # parameters -
    #       localRoot - the tree root
    # returns -
    #       integer value of the depth starting from 0 as the rootNode
    #
    # Time Complexity - O(N) - As we go to each Tree's left and right subtree and eventually we reach Every
    # node and add upto the depth and take maximum we are having currently
    def __getDepth(self, localRoot):
        if localRoot is None:
            return -1

        else:
            lTreeDepth = self.__getDepth(localRoot.left)
            rTreeDepth = self.__getDepth(localRoot.right)

            if (lTreeDepth > rTreeDepth):
                return lTreeDepth + 1
            else:
                return rTreeDepth + 1

    # Method (public) to search the depth of the tree
    # returns -
    #       integer Value being the depth of tree
    #
    # Uses Helper __getDepth function so Has a similar Time Complexity - O(N) - average
    def depth(self):
        return self.__getDepth(self.root)

    # Recursive (private) Helper function to get inorder traversal of BST
    # parameters -
    #       localRoot - tree root to get inorder traversal
    # returns -
    #       void but prints the Inorder Traversal of the tree passed
    #
    # Time Complexity - O(N) as we need to traverse all the nodes to get the Traversal
    def __inOrderTraversal(self, localRoot):
        if localRoot == None:
            return

        self.__inOrderTraversal(localRoot.left)
        print(localRoot.val, end=" ")
        self.__inOrderTraversal(localRoot.right)

    # Method (public) to print Inorder Traversal of BST should be a sorted (ascending) array
    # Uses Helper __getDepth function so Has a similar Time Complexity - O(N) - average
    def printInorderTraversal(self):
        self.__inOrderTraversal(self.root)


# Main Function to Test the BST
def main():
    tree = BST()
    for i in range(0, 10):
        tree.add(i)
    print('\nInorder Traversal of the Tree is : ')
    tree.printInorderTraversal()
    print('\n\n')
    print('Depth of the Tree : ' + str(tree.depth()))
    print('Maximum Value of the Tree : ' + str(tree.maximumValue()))
    print()
    for i in range(5, 7):
        print(f'Tree contains {i} : ' + str(tree.contains(i)))
    for i in range(15, 17):
        print(f'Tree contains {i} : ' + str(tree.contains(i)))

    print('\nThank you!\n')


if __name__ == "__main__":
    main()
