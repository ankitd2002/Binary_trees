from queue import Queue

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def create_tree():
    print("Enter the value for Node:")
    data = int(input())

    if data == -1:
        return None

    root = Node(data)
    root.left = create_tree()
    root.right = create_tree()
    return root

def pre_order_traversal(root):
    if root is None:
        return
    print(root.data, end=" ")
    pre_order_traversal(root.left)
    pre_order_traversal(root.right)

def in_order_traversal(root):
    if root is None:
        return
    in_order_traversal(root.left)
    print(root.data, end=" ")
    in_order_traversal(root.right)

def post_order_traversal(root):
    if root is None:
        return
    post_order_traversal(root.left)
    post_order_traversal(root.right)
    print(root.data, end=" ")

def level_order_traversal(root):
    if root is None:
        return

    queue = Queue()
    queue.put(root)
    queue.put(None)

    while not queue.empty():
        front = queue.get()

        if front is None:
            print()
            if not queue.empty():
                queue.put(None)
        else:
            print(front.data, end=" ")

            if front.left is not None:
                queue.put(front.left)
            if front.right is not None:
                queue.put(front.right)

def max_depth(root):
    if root is None:
        return 0

    queue = Queue()
    queue.put(root)
    queue.put(None)
    count = 1

    while not queue.empty():
        front_node = queue.get()

        if front_node is None:
            if not queue.empty():
                count += 1
                queue.put(None)
        else:
            if front_node.left is not None:
                queue.put(front_node.left)
            if front_node.right is not None:
                queue.put(front_node.right)

    return count

def height(root):
    if root is None:
        return 0

    left_height = height(root.left)
    right_height = height(root.right)
    h = max(left_height, right_height) + 1

    return h

def diameter_of_binary_tree(root):
    if root is None:
        return 0

    option1 = diameter_of_binary_tree(root.left)
    option2 = diameter_of_binary_tree(root.right)
    option3 = height(root.left) + height(root.right)
    diameter = max(option1, max(option2, option3))

    return diameter

if __name__ == "__main__":
    root = create_tree()

    print("Printing Preorder:", end=" ")
    pre_order_traversal(root)
    print()

    print("Printing Inorder:", end=" ")
    in_order_traversal(root)
    print()

    print("Printing PostOrder:", end=" ")
    post_order_traversal(root)
    print()

    print("Level Order:", end=" ")
    level_order_traversal(root)
    print()
