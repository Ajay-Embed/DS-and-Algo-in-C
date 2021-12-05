#include <stdio.h>
#include <stdlib.h> 

#define ESC 	  "\033"
#define ESC_RESET "\033[00m"

/*******************************************
 * 
 * Just some terminal colours, do you mind? 
 *
 ******************************************/

#define bRED 	 "[1;31;40m"
#define bGREEN   "[1;32;40m"
#define bYELLOW  "[1;33;40m"
#define bBLUE 	 "[1;34;40m"
#define bMAGENTA "[1;35;40m"
#define bCYAN 	 "[1;36;40m"
#define bWHITE 	 "[1;37;40m"

/* This file implements the Linked List representation of a Binary Tree. 
 * It implements functions that create a binary tree and print all three 
 * traversals possible on a binary tree, i.e. Preorder, Inorder & Postorder.
 *
 * This implementation extensively uses recursion, as it's a litte elegant.
 * However, if you're someone who works with small chips with tiny amounts
 * of RAM on them, & wish to implement a tree for your application, we'd 
 * recommend using the iterative implementation for the same. If you are
 * required to comply with MISRA, it doesn't allow recursion.  
 *
 * If you're here to learn for some interview! Welcome, we hope you enjoy!
 *
 */


/* The Main skeletal structure for our binary tree 
 *          _______________________
 *         |      |       |        |
 *         |      | Value |        |
 *         | Left |       | Right  |
 *         | Child|       | Child  |
 *         |______|_______|________|
 *             |                \___________________
 *             |                                    |
 *   __________|____________               _________|____________
 *  |      |       |        |             |      |       |       |
 *  |      | Value |        |             |      | Value |       |
 *  | Left |       | Right  |             | Left |       | Right |
 *  | Child|       | Child  |             | Child|       | Child |
 *  |______|_______|________|             |______|_______|_______|
 *
 */

typedef struct Tree
{
    struct Tree *left; 
    int data; 
    struct Tree *right;
    
} binary_tree_t;

/**********************************************
 *           Function Prototypes
 *********************************************/

binary_tree_t* plant_binary_tree(void);
void display_preorder(binary_tree_t* tree);
void display_inorder(binary_tree_t* tree);
void display_postorder(binary_tree_t* tree);

/*********************************************
 *           One of My Mains
 ********************************************/

int main(void)
{
    printf(ESC bGREEN"\r\n----------------Generate a Binary Tree--------------------\r\n"ESC_RESET);
    printf(ESC bRED"Please fill in a negative value to avoid creation of a node\r\n"ESC_RESET);
    printf("Visualize your tree first, before blaming the program\r\n(and report if there's a real bug :p)\r\n"); 
    printf("Let's plant your tree! Enter the value of Root Node \r\n"); 

    int choice=0; 
    binary_tree_t* tree = plant_binary_tree(); 

    if(tree == NULL)
    {
        printf("\r\nTree Not created!");
    }

    else
    {
        printf(ESC bGREEN"\r\nWe planted your tree!! How do you wish to see it??"ESC_RESET);
        printf("\r\nType in your choice:\r\n1. Pre-Order\r\n2. In-Order\r\n3. Post-Order\r\n4. Print All\r\n"); 
        
        scanf("%d",&choice); 
        switch(choice)
        {
            case 1 : display_preorder(tree); 
                     break; 

            case 2 : display_inorder(tree);
                     break;

            case 3 : display_postorder(tree); 
                     break;

            case 4 : printf("\r\nPre-Order: ");
                     display_preorder(tree); 
                     
                     printf("\r\nIn-Order: ");
                     display_inorder(tree); 
                     
                     printf("\r\nPost-Order: ");
                     display_postorder(tree);
                   
                     break;

            default : printf("Invalid Selection!\r\n");  
                      break;
        } 

     }
}

/* 
 * Generating a Binary Tree 
 *
 * This function generates the Binary Tree using recursion. The implementation is simple if you're aware of recursion. 
 * We first fill in the value for a particular node, and then fill it's left child first. Once the left child of a node
 * has been filled, we go and insert the right child for the node. Entering a negative value means the node wasn't created. 
 * After calling malloc(), we check if the memory was allocated for the node, if not **"NEVER DEREFERENCE A NULL POINTER"** 
 * We return NULL in case the value entered was negative or if malloc() failed to allocate the required memory. 
 * We are reading the value in pre-order fashion, as it is intuitive for most people.
 *
 */ 

binary_tree_t* plant_binary_tree(void)
{
    int value; 
    printf("\r\nEnter the value= ") ; 
    scanf("%d",&value); 
    
    if (value < 0)
        return NULL; 
    
    binary_tree_t* node = malloc(sizeof(binary_tree_t)); 
    if(node)
    {
        node->data=value; 
        
        printf("\r\nEnter the value of Left Child of %d", value);
        node->left = plant_binary_tree(); 

        printf("\r\nEnter the value of Right Child of %d", value); 
        node->right = plant_binary_tree(); 
    }
    
    return (node != NULL) ? node : NULL ; 
}

/* 
 * Print the Preorder Traversal of the Binary Tree 
 * This function uses recursion to print the preorder traversal of the binary tree. 
 */

void display_preorder(binary_tree_t* tree)
{
    if(tree)
    {
        printf("%d ", tree->data); 
        
        /* 
         * Basic Heuristics- Avoid calls for NULL children
         * If there are 'n' nodes in a tree, there are 'n+1'
         * NULL children, by the following check, we save 
         * n+1 useless recursive calls.
         */
 
        if(tree->left)
            display_preorder(tree->left); 
        
        if(tree->right)
            display_preorder(tree->right); 
    }
}

/* 
 * Print the Inorder Traversal of the Binary Tree 
 * This function uses recursion to print the Inorder traversal of the binary tree.  
 */

void display_inorder(binary_tree_t* tree)
{
    if(tree)
    {
        /* 
         * Basic Heuristics- Avoid calls for NULL children
         * If there are 'n' nodes in a tree, there are 'n+1'
         * NULL children, by the following check, we save 
         * n+1 useless recursive calls.
         */

        if(tree->left)
            display_inorder(tree->left); 
        
        printf("%d ", tree->data); 
        
        if(tree->right)
            display_inorder(tree->right); 
    }
}


/* 
 * Print the Postorder Traversal of the Binary Tree 
 * This function uses recursion to print the Postorder traversal of the binary tree.  
 */

void display_postorder(binary_tree_t* tree)
{
    if(tree)
    {
        /* 
         * Basic Heuristics- Avoid calls for NULL children
         * If there are 'n' nodes in a tree, there are 'n+1'
         * NULL children, by the following check, we save 
         * n+1 useless recursive calls.
         */
 
        if(tree->left)
            display_postorder(tree->left); 

        if(tree->right)
            display_postorder(tree->right);
        
        printf("%d ", tree->data); 

    }
}


