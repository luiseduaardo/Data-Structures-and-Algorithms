class Node:
    def __init__(self, value = 0, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

def BinaryTreeInit():
    n3 = Node(3)
    n7 = Node(7)
    n15 = Node(15)

    n13 = Node(13, None, n15)
    n5 = Node(5, n3, n7)
    n11 = Node(11, None, n13)

    n9 = Node(9, n5, n11)

    return n9;

def visit(root, level = 0):
    print("    "*level, end='')
    print(root.value)

def preorder(root, level = 0):
    if root == None:
        return
    
    visit(root, level)
    preorder(root.left, level+1)
    preorder(root.right, level+1)

def postorder(root, level = 0):
    if root == None:
        return
    
    preorder(root.left, level+1)
    preorder(root.right, level+1)
    visit(root, level)

def inorder(root, level = 0):
    if root == None:
        return
    
    preorder(root.left, level+1)
    visit(root, level)
    preorder(root.right, level+1)

def height(root):
    if root == None:
        return 0
    
    leftHeight = height(root.left)
    rightHeight = height(root.right)

    return 1 + max(leftHeight, rightHeight)

def diameter(root):
    if root == None:
        return 0
    
    leftHeight = height(root.left)
    rightHeight = height(root.right)

    leftDiameter = diameter(root.left)
    rightDiameter = diameter(root.right)

    return max(leftDiameter, rightDiameter, leftHeight+rightHeight)

def countnodes(root):
    if root == None:
        return 0
    
    return 1 + countnodes(root.left) + countnodes(root.right)

bintree_root = BinaryTreeInit()

print("[PRE]:")
preorder(bintree_root)

print("\n[POS]:")
postorder(bintree_root)

print("\n[IN]:")
inorder(bintree_root)

print(f"\nThere are {countnodes(bintree_root)} in this tree")
print(f"The height of this tree is {height(bintree_root)}")
print(f"The diameter of this tree is {diameter(bintree_root)}")