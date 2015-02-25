#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    struct node *next;
    struct node *prev;
    char name[60];
    char number[10];
}node;


int findChance(char arr1[], char arr2[])
{
    int i = 0;
    for (i = 0; arr1[i]!= '\0' && arr2[i]!= '\0' ; )
    {
        char a = tolower(arr1[i]);
        char b = tolower(arr2[i]);

        if (a<=b)
        {
            i++;
            return 1;
        }

        else
        {
            return 0;
        }

    }
    if (arr2[i] == '\0')
        return 0;

    if (arr1[i] == '\0')
        return 1;
}

void insert(node **root)
{
    node * temp = *root, *previous;
    node *newNode = (node *) malloc(sizeof(node));
    int ch;
    printf("Enter name");
    scanf("%s", newNode -> name);

    //printf("%s",newNode -> name);

    printf("Enter Number");
    scanf("%s", newNode -> number);

    //printf("%s: %d", newNode->name, newNode->number);
    //printf("hello \n");
    newNode -> prev = NULL;
    newNode -> next = NULL;
    //printf ("hello ");


    if (!(*root))
    {
        *root = newNode;
    }

    else
    {
        while(temp)
        {
            if ( ch = findChance(temp -> name, newNode -> name))
            {
                previous = temp;
                temp = temp -> next;
            }
            else break ;
        }

         //printf("%d", ch);

        if (!temp)  // When we traversed complete list
        {
            previous -> next = newNode;
            newNode -> prev = previous;
        }

        if ( ch == 0 )
        {
            newNode -> next = temp;
            if (temp -> prev)
            {
              newNode -> prev = temp -> prev;
              temp -> prev -> next = newNode;
            }
            if (!temp -> prev)
                *root = newNode ;
            temp -> prev = newNode;
        }

    }
}

void display(node *root)
{
    while(root)
    {
        printf("%s %s\n", root -> name, root -> number);
        root = root -> next;
    }
}

void Delete(node **root)
{
    if (*root)
    {
        printf("contact is empty");
        return;
    }
    node *temp = *root ;
    char contactName[60];
    printf("Enter contact to be deleted");
    scanf("%s", contactName);
    while ( temp )
    {
        if (strcmp(temp -> name, contactName) == 0)
        {

            if ( temp == *root)
            {
                *root = temp -> next;
                (*root) -> prev = NULL;
            }

            else
            {
                temp -> prev -> next = temp -> next;
                if (temp -> next)
                    temp -> next -> prev = temp -> prev;
            }

            free(temp) ;
            return ;
        }
        temp = temp -> next;
    }

    if (!temp)
        printf("Contact not found");

}

void search(node *root)
{
    if (!root)
    {
        printf("contact is empty");
        return;
    }
    char contactName[60];
    printf("Enter name to be searched and It is case sensitive");
    scanf("%s", contactName);

    node *temp = root;

    while(temp)
    {
        if (strcmp(contactName, temp -> name) == 0)
        {
            printf("%s : %s", contactName, temp -> number);
            return;
        }
        temp = temp -> next;
    }

    printf("contact is not in list");
}
int main()
{
    node *dir = NULL;
    int ch, y = 9 ;

    printf("Enter 1. for insertion \n 2. for search \n 3. for display \n 4.for Deletion");
    scanf("%d", &ch);

    switch(ch)
    {

        case 1 : {
					while (y==9)
					{
						insert(&dir);
						printf("press 9 to insert again else any number other than 9");
						scanf("%d", &y);
					}
					break;
				}

        case 2: search(dir);
            break;

        case 3: display(dir);
            break;

        case 4: Delete(&dir);
            break;

    }

    //display(dir);

   // printf("\n\n\n%s %d", dir -> name, dir -> number);
}
