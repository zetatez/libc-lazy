/* Queue.h
 *
 *
 * */
typedef struct _node{
    void *data;
    struct _node *next;
} Node;

typedef struct _tree{
    void *data;
    struct _tree *left;
    struct _tree *right;
} TreeNode;

/* typedef TreeNode BinaryTree; */

void destroyTreeNode(TreeNode *root);
TreeNode *_insert(TreeNode *root, int (*compare)(void *, void *), void *data);
void insert(TreeNode **root, int (*compare)(void *, void *), void *data);
TreeNode *_delete(TreeNode *root, int (*compare)(void *, void *), void *data);
void delete(TreeNode **root, int (*compare)(void *, void *), void *data);
TreeNode *find(TreeNode *root, int (*compare)(void *, void *), void *data);
TreeNode *findMin(TreeNode *root);
TreeNode *findMax(TreeNode *root);
void prevOrder(TreeNode *root, void (*display)(void *));
void inOrder(TreeNode *root, void (*display)(void *));
void postOrder(TreeNode *root, void (*display)(void *));

