#include <stdio.h>
#include <malloc.h>

typedef struct MyStruct
{
    struct MyStruct *left_Node;
    struct MyStruct *right_Node;
    int data;
}TreeNode;

void Recursion(TreeNode *TwoTree)
{
    if(TwoTree != NULL)
    {
        printf("%d\n", TwoTree->data);
        Recursion(TwoTree->left_Node);
        Recursion(TwoTree->right_Node);
    }


}
int main()
{
    TreeNode *Node1 =(TreeNode*) malloc(sizeof(TreeNode));
    TreeNode *Node2 =(TreeNode*) malloc(sizeof(TreeNode));
    TreeNode *Node3 =(TreeNode*) malloc(sizeof(TreeNode));
    TreeNode *Node4 =(TreeNode*) malloc(sizeof(TreeNode));
    TreeNode *Node5 =(TreeNode*) malloc(sizeof(TreeNode));

    Node1->left_Node = Node2;
    Node1->right_Node = Node3;
    Node1->data = 1;
    Node2->data = 2;
    Node2->left_Node = NULL;
    Node2->right_Node = NULL;
    Node3->data = 3;

    Node3->left_Node = Node4;
    Node3->right_Node = Node5;
    Node4->data = 4;
    Node5->data = 5;

    Node4->left_Node = NULL;
    Node4->right_Node = NULL;
    Node5->left_Node = NULL;
    Node5->right_Node = NULL;

    Recursion(Node1);
}