/* Queue.c
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinarySearchTree.h"

void destroyTreeNode(TreeNode *root){
    TreeNode *node;
    if (root != NULL) {
        node = root;
        destroyTreeNode((TreeNode *)(root->left));
        destroyTreeNode((TreeNode *)(root->right));
        free(node);
        node = NULL;
    }
}

void insert(TreeNode **root, int (*compare)(void *, void *), void *data) {
    *root = _insert(*root, compare, data);
}

TreeNode *_insert(TreeNode *root, int (*compare)(void *, void *), void *data) {
    if (root == NULL) {
        root = malloc(sizeof(TreeNode));
        if (root == NULL) {
            printf("out of memory");
            return NULL;
        }
        root->data = data;
        root->left = root->right = NULL;
    } else
    if (compare(root->data, data) > 0) {
        root->left = _insert(root->left, compare, data);
    } else if (compare(root->data, data) < 0) {
        root->right = _insert(root->right, compare, data);
    }
    return root;
}

void delete(TreeNode **root, int (*compare)(void *, void *), void *data) {
    *root = _delete(*root, compare, data);
}

TreeNode *_delete(TreeNode *root, int (*compare)(void *, void *), void *data) {
    TreeNode *tmp = (TreeNode *)malloc(sizeof(TreeNode));

    if (root == NULL) { /* element not found */
        return root;
    } else if (compare(root->data, data) > 0) {
        root->left = _delete(root->left, compare, data);
    } else if (compare(root->data, data) < 0) {
        root->right = _delete(root->left, compare, data);
    } else /* found element to be deleted */ if (root->left && root->right) { /* one or zero children */
        tmp = findMin(root->right);
        root->data = tmp->data;
        root->right = _delete(root->right, compare, root->data);
    } else { /* one or zero children */
        tmp = root;
        if (root->left == NULL) {
            root = root->right;
        } else if (root->right == NULL) {
            root = root->left;
        }
        free(tmp);
    }
    return root;
}

TreeNode *find(TreeNode *root, int (*compare)(void *, void *), void *data) {
    if (root == NULL) {
       return NULL;
    }

    if (compare(root->data, data) > 0) {
        return find(root->left, compare, data);
    } else if (compare(root->data, data) < 0) {
        return find(root->right, compare, data);
    } else {
        return root;
    }
}

TreeNode *findMin(TreeNode *root) {
    if (root == NULL) {
       return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return findMin(root->left);
    }
}

TreeNode *findMax(TreeNode *root) {
    if (root != NULL) {
        while (root->right != NULL) {
            root = root->right;
        }
    }
    return root;
}

void prevOrder(TreeNode *root, void (*display)(void *)) {
    if (root != NULL) {
        display(root->data);
        prevOrder((TreeNode *)(root->left), display);
        prevOrder((TreeNode *)(root->right), display);
    }
}

void inOrder(TreeNode *root, void (*display)(void *)) {
    if (root != NULL) {
        inOrder((TreeNode *)(root->left), display);
        display(root->data);
        inOrder((TreeNode *)(root->right), display);
    }
}

void postOrder(TreeNode *root, void (*display)(void *)) {
    if (root != NULL) {
        postOrder((TreeNode *)(root->left), display);
        postOrder((TreeNode *)(root->right), display);
        display(root->data);
    }
}

