//
// Created by František Gič on 07/04/2020.
//

#include <stdio.h>
#include <stdlib.h>

#define left_height(node) (node->left ? node->left->height : 0)
#define right_height(node) (node->right ? node->right->height : 0)
#define balance(node) (left_height(node) - right_height(node))
#define height(node) ((right_height(node) > left_height(node) ? right_height(node) : left_height(node))+1)

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
    int height;
} Node;

Node *rot_ll (Node *node) {
    return NULL;
};

Node *rot_lr (Node *node) {
    return NULL;
};

Node *rot_rl (Node *node) {
    return NULL;
};

Node *rot_rr (Node *node) {
    return NULL;
};


Node *insert (Node *node, int data) {
    
    // Inserting a new element
    if (node == NULL) {
        
        node = (Node *) malloc(sizeof(Node));
        node->data = data;
        node->height = 1;
        node->left = NULL;
        node->right = NULL;
        
        return node;
    }
    
    // Recursively insert left or right depending on value of data
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    
    // Update the height - maximum height of its children increased by 1
    node->height = height(node);
    
    // Check the imbalance in the tree and perform rotations
    if (balance(node) == 2) {
        if (balance(node->left) == 1)
            return rot_ll(node);
        else if (balance(node->left) == -1)
            return rot_lr(node);
    }
    if (balance(node) == -2) {
        if (balance(node->left) == 1)
            return rot_rl(node);
        else if (balance(node->left) == -1)
            return rot_rr(node);
    }
    
    return node;
};

void search (Node *tree, int data) {};

void free_node (Node *node) {
    if (!node) return;
    free_node(node->left);
    free_node(node->right);
    free(node);
}

int main () {
    Node *tree = NULL;
    
    tree = insert(tree, 50);
    tree = insert(tree, 10);
    tree = insert(tree, 20);
    
    free_node(tree);
    return 0;
}

