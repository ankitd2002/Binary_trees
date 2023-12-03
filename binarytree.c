#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createTree() {
    printf("Enter the value for Node: ");
    int data;
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = data;
    root->left = createTree();
    root->right = createTree();
    return root;
}

void preOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int front = -1, rear = -1;

    queue[++rear] = root;
    queue[++rear] = NULL;

    while (front < rear) {
        struct Node* frontNode = queue[++front];

        if (frontNode == NULL) {
            printf("\n");
            if (front < rear) {
                queue[++rear] = NULL;
            }
        } else {
            printf("%d ", frontNode->data);

            if (frontNode->left != NULL) {
                queue[++rear] = frontNode->left;
            }
            if (frontNode->right != NULL) {
                queue[++rear] = frontNode->right;
            }
        }
    }

    free(queue);
}

int maxDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int front = -1, rear = -1;

    queue[++rear] = root;
    queue[++rear] = NULL;
    int count = 1;

    while (front < rear) {
        struct Node* frontNode = queue[++front];

        if (frontNode == NULL) {
            if (front < rear) {
                count++;
                queue[++rear] = NULL;
            }
        } else {
            if (frontNode->left != NULL) {
                queue[++rear] = frontNode->left;
            }
            if (frontNode->right != NULL) {
                queue[++rear] = frontNode->right;
            }
        }
    }

    free(queue);
    return count;
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int h = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    return h;
}

int diameterOfBinaryTree(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int option1 = diameterOfBinaryTree(root->left);
    int option2 = diameterOfBinaryTree(root->right);
    int option3 = height(root->left) + height(root->right);
    int diameter = (option1 > (option2 > option3 ? option2 : option3) ? option1 : (option2 > option3 ? option2 : option3));

    return diameter;
}

int main() {
    struct Node* root = createTree();

    printf("Printing Preorder: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Printing Inorder: ");
    inorderTraversal(root);
    printf("\n");

    printf("Printing PostOrder: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Level Order : ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
