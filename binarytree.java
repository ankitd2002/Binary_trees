import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

public class BinaryTree {
    public static Node createTree(Scanner scanner) {
        System.out.println("Enter the value for Node:");
        int data = scanner.nextInt();

        if (data == -1) {
            return null;
        }

        Node root = new Node(data);
        root.left = createTree(scanner);
        root.right = createTree(scanner);
        return root;
    }

    public static void preOrderTraversal(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " ");
        preOrderTraversal(root.left);
        preOrderTraversal(root.right);
    }

    public static void inorderTraversal(Node root) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    public static void postOrderTraversal(Node root) {
        if (root == null) {
            return;
        }
        postOrderTraversal(root.left);
        postOrderTraversal(root.right);
        System.out.print(root.data + " ");
    }

    public static void levelOrderTraversal(Node root) {
        if (root == null) {
            return;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(null);

        while (!queue.isEmpty()) {
            Node front = queue.poll();

            if (front == null) {
                System.out.println();
                if (!queue.isEmpty()) {
                    queue.offer(null);
                }
            } else {
                System.out.print(front.data + " ");

                if (front.left != null) {
                    queue.offer(front.left);
                }
                if (front.right != null) {
                    queue.offer(front.right);
                }
            }
        }
    }

    public static int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(null);
        int count = 1;

        while (!queue.isEmpty()) {
            Node frontNode = queue.poll();

            if (frontNode == null) {
                if (!queue.isEmpty()) {
                    count++;
                    queue.offer(null);
                }
            } else {
                if (frontNode.left != null) {
                    queue.offer(frontNode.left);
                }
                if (frontNode.right != null) {
                    queue.offer(frontNode.right);
                }
            }
        }

        return count;
    }

    public static int height(Node root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = height(root.left);
        int rightHeight = height(root.right);
        int h = Math.max(leftHeight, rightHeight) + 1;

        return h;
    }

    public static int diameterOfBinaryTree(Node root) {
        if (root == null) {
            return 0;
        }

        int option1 = diameterOfBinaryTree(root.left);
        int option2 = diameterOfBinaryTree(root.right);
        int option3 = height(root.left) + height(root.right);
        int diameter = Math.max(option1, Math.max(option2, option3));

        return diameter;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node root = createTree(scanner);

        System.out.print("Printing Preorder: ");
        preOrderTraversal(root);
        System.out.println();

        System.out.print("Printing Inorder: ");
        inorderTraversal(root);
        System.out.println();

        System.out.print("Printing PostOrder: ");
        postOrderTraversal(root);
        System.out.println();

        System.out.print("Level Order : ");
        levelOrderTraversal(root);
        System.out.println();
    }
}
