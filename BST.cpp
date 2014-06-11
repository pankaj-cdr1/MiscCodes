#include <stdio.h>
#include <stdlib.h>
#include <stack>
#define N 100
typedef struct node {
        int x;
        struct node *l, *r;
} node;
node *insert(node *root, int num)
{
     if(!root) {
             node *tmp = (node *)malloc(sizeof(node));
             tmp->x = num;
             tmp->l = tmp->r = NULL;
             return tmp;
     } else if(root->x > num) {
             root->l = insert(root->l, num);
             return root;
     } else {
            root->r = insert(root->r, num);
            return root;
     }
} 
void inorder(node *root)
{
     if(!root) return;
     inorder(root->l);
     printf("%d ", root->x);
     inorder(root->r);
}
void loopinorder(node *root)
{
     std::stack<node *> S;
     S.push(root);
     int done = 0;
     while (!S.empty()) {
           root = S.top();
           root = root->l;
           while (root) {
                 S.push(root);
                 root = root->l;
           }
           root = S.top();
           S.pop();
           printf("%d ",root->x);
           root = root->r;
           while (!root) {
                 if (S.empty()) {
                    done = 1;
                    break;
                 }
                 root = S.top();
                 S.pop();
                 printf("%d ", root->x);
                 root = root->r;
           }
           if(done) break;
           S.push(root);
     }
}
int main()
{
    node *root = NULL;
    int i;
    int num;
    for(i = 0; i < N; i++) {
          num = rand()%100;
          printf("Inserting %d...\n", num);
          root = insert(root, num);
    }
    inorder(root);
    puts("\n");
    loopinorder(root);
    scanf("%d", &i);
    return 0;
}
