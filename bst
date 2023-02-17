#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1;

void delete1();
void insert();
void delete();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);//search to insert
void search1(struct btnode *t,int data);//search to delete
int smallest(struct btnode *t);


void main()
{
    int ch;

printf("\nOPERATIONS ---");
printf("\n1 - Insert an element into tree\n");
printf("2 - Delete an element from the tree\n");
printf("3 - Inorder Traversal\n");
printf("4 - Exit\n");
while(1)
    {
printf("\nEnter your choice : ");
scanf("%d", &ch);
        switch (ch)
        {
        case 1:    
                          insert();
            break;
        case 2:    
                          delete();
            break;
        case 3:    
                           inorder(root);
            break;
        case 4:    
                           exit(0);
default :
                       printf("Wrong choice, Please enter correct choice  ");
            break;    
        }
    }
}

/* To insert a node in the tree */
void insert()
{
    create();  /*Call create function to create a node*/
    if (root == NULL) 
        root = temp;
    else    
        search(root);    
}

/* To create a node */
void create()
{
    int data;

   printf("Enter data of node to be inserted : ");
   scanf("%d", &data);
    temp = (struct btnode*)malloc(1*sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
}

/* Function to search for the appropriate position to insert the new node */
void search(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))      /* value more than root node value and right child not null */
        search(t->r);//move towards right subtree
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp; //if right child null, insert as right child
    else if ((temp->value < t->value) && (t->l != NULL))    /* value less than root node value and left child not null */
        search(t->l);// Move towards left subtree
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp; //if left child null, insert as left child
}

/* recursive function to perform inorder traversal of tree */
void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (t->l != NULL)    
      inorder(t->l);
      printf("%d -> ", t->value);
     if (t->r != NULL)    
       inorder(t->r);
}

/* Function to delete a node */
void delete()
{
    int data;

    if (root == NULL)
    {
printf("No elements in a tree to delete");
        return;
    }
printf("Enter the data to be deleted : ");
scanf("%d", &data);

    search1(root, data);
}


/* Search for the node to be deleted */
void search1(struct btnode *t, int data)
{
    if ((data>t->value))
    {
        t1 = t;// t1 is the parent
        search1(t->r, data);// Move towards right subtree
    }
    else if ((data < t->value))
    {
        t1 = t;
        search1(t->l, data);//Move towards left subtree
    }
    else if ((data==t->value))
    {
        delete1(t);
    }
}

/* To delete a node */
void delete1(struct btnode *t)
{
    int k;

    /* To delete leaf node */
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t) //check if it is the leftchild of parent t1
        {
            t1->l = NULL;
        }
        else // it is the rightchild of parent t1

        {
            t1->r = NULL;
        }
        t = NULL;
        free(t);
        return;
    }

/* To delete node having left child and no rightchild*/
    else if ((t->r == NULL))
    {
        if (t1 == t) //If the node to be deleted is the root
        {
            root = t->l;
            t1 = root;
        }
       else if (t1->l == t) //Else if parent’s left child is the node to be   deleted
        {
            t1->l = t->l; //Assign t’s(node to delete) left child as t1’s(parent) leftchild

        }
        Else //Else if parent’s rightchild is the node to be   deleted
        {
            t1->r = t->l; //Assign t’s(node to delete) left child as t1’s(parent) rightchild
        }
        t = NULL;
        free(t);
        return;
    }

  /* To delete node having right child and no leftchild*/
    else if (t->l == NULL)
    {
        if (t1 == t) //If the node to be deleted is the root
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t) //Else if parent’s right child is the node to be   deleted
            t1->r = t->r; //Assign t’s(node to delete) right child as t1’s(parent) rightchild
        else //Else if parent’s leftchild is the node to be   deleted
            t1->l = t->r; //Assign t’s(node to delete) right child as t1’s(parent) leftchild
        t == NULL;
        free(t);
        return;
    }

    /* To delete node having two child */
    else if ((t->l != NULL) && (t->r != NULL))  
    {
         k = smallest(t->r); //Move to right child and fetch the smallest value ‘k’ in the right subtree
        search1(root, k); //Search for the element to be deleted.
        t->value = k; //Replace that element with ‘k’
    }

}

/* To find the smallest element in the right sub tree */
int smallest(struct btnode *t)
{

    if (t->l != NULL)
    {

        return(smallest(t->l)); //move to the leftmost node(of right subtree)
    }
    else    
        return (t->value); //Return the value
}






































