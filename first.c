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

	//create new node
	Node *CreatenewNode(int data){
		Node* newNode  = (Node*)malloc(100*sizeof(Node));
		if(newNode==NULL){printf("error\n");return NULL;}
		newNode -> data = data;
		newNode -> next = NULL;
		return newNode;
		}

	
static Node* insert(Node *head,  int data);
static Node* delete(Node *head, int data);

	int main(int argc, char *argv[]){
	  
	FILE * file = fopen(argv[1],"r");
	
	if(file == NULL){
	printf("error\n");
	return 0;
	}
	// check if file does exist

	fseek(file,0,SEEK_END);
	int size = ftell(file);
	if (size == 0){
	printf("0\n");
	printf("\n");
	return 0; 
	}
	rewind(file);
	// check if file is empty

	Node *head = NULL;	
	
	char *str1 = (char *)malloc(100*sizeof(char));
	if(str1==NULL){printf("error\n");return 0;}
	char ch1[1],ch2[1];
	ch1[0] = 'i';	//instruction - insert
	ch2[0] = 'd'; 	//iinstruction - delete
	int str2;
	//begin scan file, inputs are in format "[char][tab][int]"
	while(fscanf(file, "%s\t%d", str1, &str2) != EOF){
		
	//return error for wrong input format
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
	

	Node *tmp3 = head;
	int count = 0;

	//empty list
	if(tmp3 == NULL){
	printf("0\n");
	return 0;}

	//find lenthg of list
	while(tmp3 != NULL){
	count++; 
	tmp3 = tmp3 -> next;}

	printf("%d\n",count); 

	tmp3 = head;
	while(tmp3 != NULL){	//print list
        printf("%d\t",tmp3 -> data);  
        tmp3 = tmp3 -> next;}
	printf("\n");
	



        free(str1); 	
	fclose(file);

	return 0;
}
//////////////////////////////////////////////////////
//free whole list
void freeNode(Node* head){

	Node *tmp = head;
	while( head != NULL){
		tmp = head;
		head = head->next;	
		free(tmp);
	}
	
	}

///////////////////////////////////////////////////////////

 Node* insert(Node *root, int key){

        if (root == NULL) return CreatenewNode(key);


    Node *tmp = root;
    Node *prev;   
    Node *curr = CreatenewNode(key);

//if new node is smallest, then change head
    if(curr->data < root->data){
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
		return head;}

		prv = tmp2;
                tmp2  = tmp2 -> next;
                }

        return head;
}

return head;

}

/////////////////////////////////////////////////////////////////////////////////////
