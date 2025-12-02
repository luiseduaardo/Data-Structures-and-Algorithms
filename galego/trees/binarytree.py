class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert_recursive(data, self.root)

    def _insert_recursive(self, data, node):
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._insert_recursive(data, node.left)
        else:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert_recursive(data, node.right)

    def search(self, data):
        return self._search_recursive(self.root, data)
    
    def _search_recursive(self, node, data):
        if node is None:
            return False
        
        if node.data == data:
            return True
        elif data < node.data:
            return self._search_recursive(node.left, data)
        else:
            return self._search_recursive(node.right, data)
        
    def preorder_traversal(self):
        result = []

        self._preorder_recursive(self.root, result)

        return result
    
    def _preorder_recursive(self, node, result):
        if not node:
            return

        result.append(node.data)
        self._preorder_recursive(node.left, result)
        self._preorder_recursive(node.right, result)

    def postorder_traversal(self):
        result = []

        self._postorder_recursive(self.root, result)

        return result
    
    def _postorder_recursive(self, node, result):
        if not node:
            return

        self._postorder_recursive(node.left, result)
        self._postorder_recursive(node.right, result)
        result.append(node.data)

    def inorder_traversal(self):
        result = []

        self._inorder_recursive(self.root, result)

        return result
    
    def _inorder_recursive(self, node, result):
        if not node:
            return

        self._inorder_recursive(node.left, result)
        result.append(node.data)
        self._inorder_recursive(node.right, result)

tree = BinaryTree()
tree.insert(5)
tree.insert(3)
tree.insert(1)
tree.insert(10)
tree.insert(15)
tree.insert(7)

print("Search 4:", tree.search(4)) # Expected: True
print("Search 6:", tree.search(6)) # Expected: False

print()

print("Preorder traversal: ", tree.preorder_traversal())   # Expected: [5, 3, 1, 10, 7, 15]
print("Postorder traversal:", tree.postorder_traversal())  # Expected: [1, 3, 7, 15, 10, 5]
print("Inorder traversal:  ", tree.inorder_traversal())    # Expected: [1, 3, 5, 7, 10, 15]