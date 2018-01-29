#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>


	//create node
        struct _Node{
        int data;
        struct _Node * next;};
        typedef struct _Node Node;

	
	Node *newNode(int data){
		Node* newNode  = (Node*)malloc(100*sizeof(Node));
		if(newNode==NULL){printf("error\n");return NULL;}
		newNode -> data = data;
		newNode -> next = NULL;
		return newNode;
		}

	
static Node* insert(Node *head,  int data);
static Node* delete(Node *head, int data);
//static void freeNode(Node *head);

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
	printf("0\n");
	printf("\n");
	return 0; 
	}
	rewind(file);
	// check if empty

	Node *head = NULL;	
	
	char *str1 = (char *)malloc(100*sizeof(char));
	if(str1==NULL){printf("error\n");return 0;}
	char ch1[1],ch2[1];
	ch1[0] = 'i';
	ch2[0] = 'd'; 
	int str2;
	//int i = 0;
	while(fscanf(file, "%s\t%d", str1, &str2) != EOF){
		
	
	if((str1[0] != ch1[0] && str1[0] != ch2[0])&&(!isdigit(str2))){
		printf("error\n");
		return 0;}

///////////////////////////////////////////////////////////////////////////////////////////////
	//insert Node	

	if(str1[0] == ch1[0]){
	
	head = insert(head, str2);
	
	}
////////////////////////////////////////////////////////////////////////

	//delete node

	if(str1[0] == ch2[0]){
		
	head = delete(head, str2);}	
}
////////////////////////////////////////////////////////////////////////////////
	//tmp3 = (Node *) malloc(sizeof(Node));

	Node *tmp3 = head;
	int count = 0;

	if(tmp3 == NULL){
	printf("0\n");
	return 0;}

	while(tmp3 != NULL){
	count++; 
	tmp3 = tmp3 -> next;}

	printf("%d\n",count); 

	tmp3 = head;
	while(tmp3 != NULL){
        printf("%d\t",tmp3 -> data);  
        tmp3 = tmp3 -> next;}
	printf("\n");
	




	//free(head);
        free(str1); 
       // free(curr);
	//freeNode(head);	
	fclose(file);

	return 0;
}
//////////////////////////////////////////////////////
/*	void freeNode(Node* head){

	Node *tmp = head;
	while( head != NULL){
		tmp = head;
		head = head->next;	
		free(tmp);
	}
	
	}
*/
///////////////////////////////////////////////////////////

 Node* insert(Node *root, int key){

        if (root == NULL) return newNode(key);


    Node *tmp = root;
    Node *prev;   
    Node *curr = newNode(key);


    if(curr->data < tmp->data){
        curr->next = root;   
        root = curr;
    return root;}                      

    while(curr -> data > tmp -> data && tmp -> next != NULL){
        prev = tmp;  
        tmp = tmp -> next;}
	
    if(tmp -> data != curr -> data && tmp->data > curr->data){
		curr->next = tmp;
		prev->next = curr; 
		return root;   
		}
	if(tmp -> data != curr -> data && tmp->data < curr->data && tmp->next ==NULL){
		tmp->next = curr;
		return root;}
	
                         
return root;

}

/////////////////////////////////////////////////////////////////////////////////////

Node*delete(Node*head, int data){
    
        if(head == NULL){
                return NULL;}


     if(head != NULL){
                        Node * tmp2 = head;
                        Node *prv  = NULL;

                while(tmp2  != NULL){
                         if(head -> data == data && head -> next != NULL){
                        head = tmp2 -> next;
                        free(tmp2);
			// tmp2 -> next = NULL;
                        return head;
                        }

			if(head->data ==data && head-> next == NULL){
			free(head);
			//head = NULL;
			return NULL;}

                if(tmp2 -> data == data && tmp2 -> next  != NULL){
                prv -> next = tmp2 -> next;
                free(tmp2);
                    return head;}

		if(tmp2 -> data == data && tmp2 -> next == NULL){
		prv -> next = NULL;
		free(tmp2);
		//tmp2 -> next = NULL;
		return head;}

		prv = tmp2;
                tmp2  = tmp2 -> next;
                }

        return head;
}

return head;

}

/////////////////////////////////////////////////////////////////////////////////////
/*
	void delete(Node *head, int data){

	if(head == NULL){return NULL;}

	 if(head != NULL){

                        //tmp2 = (Node *) malloc(sizeof(Node));
                        Node * tmp2 = head;
                        Node *next = NULL;
                while(tmp2 -> next != NULL){
                         if(tmp2 == head && tmp2 -> data == data){
                        head = tmp2 -> next;
                        }

                        if(tmp2 -> next -> data == data && tmp2 -> next -> next != NULL){
                        next = tmp2 -> next;
                        tmp2 -> next = tmp2 -> next -> next;
                        next -> next = NULL;}

                        if(tmp2 -> next -> data == data && tmp2 -> next -> next == NULL){
                        tmp2 -> next = NULL;
                        break;}

                        tmp2 = tmp2 -> next;
                        next = tmp2 -> next;}
}

return;
        }
*/
