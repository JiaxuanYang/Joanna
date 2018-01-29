#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>




	 struct _Node{
        int data;
        struct _Node *next;};
        typedef struct _Node Node;


//create new node
 Node *newNode(int data){
                Node* newNode  = (Node*)malloc(sizeof(Node));
                if(newNode==NULL){printf("error\n");return NULL;}
		newNode -> data = data;
                newNode -> next = NULL;
                return newNode;
                }

	
////////////////////////////////////////////////////////////
	static void search(Node *hashtable[], int num);
	static void insert (Node *hashtable[], int num);
	static void freeNode(Node *hashtable[],int*arr,int len);
	
////////////////////////////////////////////////////////



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
        printf("0");
	printf("\n");
        return 0; 
        }
        rewind(file);

	
	Node *hashtable[10000];
	int r;
	for(r = 0;r<10000;r++){
		hashtable[r] = NULL;}

	
	int *snum = (int *)malloc(100*sizeof(int));
	char *ch = (char *)malloc(100*sizeof(char));
	if(ch==NULL){printf("error\n");return 1;}
	char ch1[10],ch2[10];
	ch1[0] = 'i';	//instruction - insert
	ch2[0] = 's';	//instruction - search
	int num;
	int u = 0, dup = 0, tf = 0;
	
		 //scan the input file
	while(fscanf(file, "%s\t%d", ch, &num) != EOF){
		if(ch[0] == ch1[0]){
		for(dup = 0; dup < u; dup++){
			if(snum[dup] == num){
			    tf = -1;
			}
		
		}
			if(tf != -1){
			snum[u] = num;
			u++;}
		
			insert(hashtable, num);
		}
		if(ch[0] == ch2[0]){
			search(hashtable, num);
		}}

	

	free(ch);
	freeNode(hashtable, snum, u);
	free(snum);
	fclose(file);
	
	return 0;
}

//free all nodes in the hash table
	void freeNode(Node *hashtable[], int*arr, int len){
	int i,index = 0,g = 0;
	Node *tmp;
	for(i = 0; i < len; i++){
		if(arr[i] < 0){
		g = -1*arr[i];
		index = g % 10000;}else{
		index = arr[i]%10000;}

		tmp = hashtable[index];
		
		if(tmp->next != NULL && tmp != NULL){
		hashtable[index] = tmp->next;
		free(tmp);

		}else{

		if(tmp ->next == NULL && tmp != NULL){
		free(tmp);
		hashtable[index] = NULL;}
			}


		if(tmp ==NULL){
		 if(tmp == NULL && i+1 >= len){
             		return;
		   }else{                 
             
                if(tmp == NULL && i+1 <len){
                        continue;}
		}
			}


}	
	}


	void insert(Node *hashtable[], int num){
	
		int index;
		int g = 0;
		if(num < 0){
		g = -1*num;	//if input is negative, turn to positive index
		index = g%10000;}else{		
		index = num%10000;}
		Node *ele = newNode(num);

		if(hashtable[index] == NULL){
		
			hashtable[index] = ele;
			printf("inserted\n");
			return;} 

		Node *tmp = hashtable[index];
		while(tmp != NULL){
			if(tmp ->data == num){
				printf("duplicate\n");
			return;}
			if(tmp -> next ==NULL){
			tmp -> next = ele;
			ele -> next = NULL;
			printf("inserted\n");
			return;}
			tmp = tmp -> next;	}
		


	

	}


	void search(Node *hashtable[], int num){
		int index;
		int g = 0;			
	
		//find index
		if(num < 0){ 
                g = -1*num; 
                index = g%10000;}else{

		index = num % 10000;}
		Node *tmp;
                tmp = hashtable[index];
	
		
		while(tmp != NULL){
			if(tmp -> data == num){
			printf("present\n");
			return;	}
			tmp = tmp -> next;
			}

		printf("absent\n");
	
	
}
