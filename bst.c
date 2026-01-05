#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

struct node* createNode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void insert() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct node *newnode = createNode(value);
    if (root == NULL) {
        root = newnode;
        return;
    }

    struct node *temp = root, *parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (value < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;
}

void search() {
    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct node *temp = root;

    while (temp != NULL) {
        if (key == temp->data) {
            printf("Value FOUND!\n");
            return;
        }
        else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Value NOT FOUND!\n");
}

struct node* deleteNode(struct node *root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *succ = root->right;
        while (succ->left != NULL)
            succ = succ->left;

        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

void delete() {
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void display() {
    printf("\nInorder   : ");
    inorder(root);
    printf("\nPreorder  : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
    printf("\n");
}

/* -------------------- MAIN MENU -------------------- */

int main() {
    int choice;
    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Traversals\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: delete(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
