#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

         struct _Node{
        int data;
        struct _Node *left;
        struct _Node *right;};
        typedef struct _Node Node;



         Node* newNode(int data){

        Node* temp = (Node *)malloc(100*sizeof(Node));
        if(temp==NULL){printf("error\n");return NULL;}
        temp -> data = data;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
                }

        static Node * insert(Node *head, int num);
        static void search(Node *head, int num);
        static Node * delete(Node *head, int num);
        static int height(Node *head, int num);
	static Node* freeNode(Node* head);

         int main(int argc, char *argv[]){

        FILE * file = fopen(argv[1],"r");
       

         if(file == NULL){
        printf("error\n");
        return 0;
        }
        // check if exist


        fseek(file,0,SEEK_END);
        int size = ftell(file);
        if (size == 0){
        printf("error\n");
        return 0; 
        }
        rewind(file);


        char *ch = (char *) malloc(100*sizeof(char));
        if(ch==NULL){printf("error\n");return 0;}
        char ch1[10],ch2[10],ch3[10];
        ch1[0] = 'i';	//instruction: i = insert, d = delete, s = search
        ch2[0] = 's';
        ch3[0] = 'd';
        int num;

        Node *head  = NULL;




	int ret;	//check if input is in format "[char][tab][int]"


        do{ ret = fscanf(file, "%s\t%d", ch, &num);

	if(ret == -1){break;}

        

                if((ch[0] != ch1[0] && ch[0] != ch2[0] && ch[0] != ch3[0]) || ret != 2){
                printf("error\n");
                return 0;}

                if(ch[0] == ch1[0]){
                
                head = insert(head, num);
        }

                if(ch[0] == ch2[0]){
                
                search(head, num);
                        }

                if(ch[0] == ch3[0]){
                        
                        head = delete(head, num);
                        }


                }while(ret != -1);

        free(ch);
	freeNode(head);
        fclose(file);
        return 0;
        }

//free the BST
Node*freeNode(Node* node){
       if(node->left == NULL && node->right==NULL){
              free(node);
              return NULL;} 
if(node->left != NULL){return node->left;}
return node->right;
}
	  

        Node* insert(Node* head, int num){

                int h = 0;

                Node *tmp = newNode(num);
                if(head == NULL){
                head = tmp;
                printf("inserted %d\n", 1);
                return head; }



                Node *cur = head;
                Node *prv = NULL;

                while(cur != NULL){


                        if(cur -> data == num){

                                printf("duplicate\n");
                                return head;}

                        prv = cur;
                        if(num < cur -> data){
                                cur = cur -> left;
                                }
                                else
                        if(num > cur -> data){
                                cur = cur -> right;
                                }
                }



                if(num < prv -> data){
                        prv -> left = tmp;
                        h = height(head,num);
                        printf("inserted %d\n", h);
                        return head;}
                else{
                        prv -> right = tmp;
                        h = height(head,num);
                        printf("inserted %d\n", h);
                        return head;    }
        return head;

        }



        void search( Node *head,int num){
                int h = 0;
                Node *tmp = head;

                while(tmp != NULL){
                        if(tmp -> data == num){
                        h = height(head,num);
                        printf("present %d\n", h);
                        return;}
                        if(num < tmp -> data){
                                tmp = tmp -> left;}
                        else
                        if(num > tmp -> data){
                                tmp = tmp -> right;}
                }

        printf("absent\n");

                }

        int height(Node * head,int num){

                if(head == NULL){
                return 0;}


                Node *tmp = head;
                int count = 1;
                while(tmp != NULL){
                        if(tmp->data == num){
                        break;}
                        if(tmp -> data > num){
                        tmp = tmp -> left;
                        count++;
                        }else{
                        tmp = tmp ->right;
                        count++;}
                }

                return count;

        }



        Node* delete(Node *head, int num){

                Node *tmp = head;
                Node *hold = NULL;
                Node *prv = NULL;

                if(head == NULL){
                        printf("fail\n");
                        return NULL;}

                //delete head
                if(head->data == num){

                        if(head ->left == NULL && head ->right == NULL){

                        head = NULL;
                        printf("success\n");
                        return NULL;}

                        if(head ->right == NULL && head ->left != NULL){
                                tmp = head->left;
                                free(head);
                                printf("succuee\n");
                                return tmp;}
                        if(head ->right != NULL && head ->left == NULL){
                                tmp = head -> right;
                                free(head);
                                printf("success\n");
                                return tmp;}

                         if(head -> left != NULL && head->right != NULL){
                                 hold = head -> right;
                        if(hold->left == NULL){prv = head;}
                        while(hold ->left != NULL){
                                prv = hold;
                                hold = hold-> left;}
                        head -> data = hold -> data;
                       
                        }



                head->right = delete(head->right,hold->data);
               
                return head;

                }

		


                while(tmp != NULL){
                        if(tmp -> data==num){	//find the correct node
                                break;}
                        prv = tmp;
                        if(num < tmp -> data){
                                tmp = tmp -> left;}
                        else{
                        if(num > tmp -> data){
                                tmp = tmp -> right;}}
                }

                if(tmp == NULL){
                        printf("fail\n");
                        return head;}

                //two or more child
                if(tmp ->left != NULL && tmp -> right != NULL){
                        hold = tmp -> right;
                        if(hold->left == NULL){prv = tmp;}
                        while(hold ->left != NULL){
                                prv = hold;
                                hold = hold-> left;}
                        tmp -> data = hold -> data;
                        tmp = hold;
                        }

                //no child
                if(tmp -> left == NULL && tmp -> right == NULL){
                        if(tmp == prv -> left){
                                free(tmp);
                                prv -> left = NULL;
                                printf("success\n");
                                return head;}
                        else{   free(tmp);
                                prv -> right = NULL;
                                 printf("success\n");
                                return head;}
                        }

                //one child
                if(tmp -> right != NULL && tmp -> left == NULL){
                if(tmp == prv -> left){
                prv -> left = tmp -> right;
                free(tmp);}else{
                prv -> right = tmp -> right;
                free(tmp);}      
                printf("success\n");
                return head;}

                if(tmp -> left != NULL && tmp -> right == NULL){
                if(tmp == prv->left){
                prv -> left = tmp -> left;
                free(tmp);}else{
                prv -> right = tmp->left;
                free(tmp);}      
                printf("success\n");
                return head;}

return head;
        }
