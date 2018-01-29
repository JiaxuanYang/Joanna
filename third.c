#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>



//////////////////////////////////////////////
	 struct _Node{
        int data;
        struct _Node *next;};
        typedef struct _Node Node;
/////////////////////////////////////////////////////
 Node *newNode(int data){
                Node* newNode  = (Node*)malloc(sizeof(Node));
                if(newNode==NULL){printf("error\n");return NULL;}
		newNode -> data = data;
                newNode -> next = NULL;
                return newNode;
                }

//////////////////////////////////////////////
	
////////////////////////////////////////////////////////////
	static void search(Node *hashtable[], int num);
	static void insert (Node *hashtable[], int num);
	static void freeNode(Node *hashtable[],int*arr,int len);
	//static void freeLLNode(Node *head);
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

	
	//Node* ele = (Node*)malloc(sizeof(Node));
	Node *hashtable[10000];
	int r;
	for(r = 0;r<10000;r++){
		hashtable[r] = NULL;}

	
	int *snum = (int *)malloc(100*sizeof(int));
	char *ch = (char *)malloc(100*sizeof(char));
	if(ch==NULL){printf("error\n");return 1;}
	char ch1[10],ch2[10];
	ch1[0] = 'i';
	ch2[0] = 's';
	int num;
	int u = 0, dup = 0, tf = 0;
	//printf("here");
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
		//printf("snum[u] = %d\n",snum[u]);
			insert(hashtable, num);
		}
		if(ch[0] == ch2[0]){
			search(hashtable, num);
		}}

	//int len = sizeof(snum)/sizeof(snum[0]);

	//for(u=0;u<4;u++){printf("sum = %d\n",snum[u]);}


	free(ch);
//printf("here = %d\n",len);
	freeNode(hashtable, snum, u);
//printf("here\n");	
free(snum);
//printf("here\n");
	//free(ele);
	fclose(file);
//printf("here2\n");	
	return 0;
}

	void freeNode(Node *hashtable[], int*arr, int len){
	int i,index = 0,g = 0;
	Node *tmp;
	for(i = 0; i < len; i++){
		if(arr[i] < 0){
		g = -1*arr[i];
		index = g % 10000;}else{
		index = arr[i]%10000;}
//printf("arr[i] = |%d|, g = |%d|, index = |%d|, len = |%d|, i = |%d|\n", arr[i],g,index,len,i);
		tmp = hashtable[index];
		
		if(tmp->next != NULL && tmp != NULL){

		//freeLLNode(tmp);
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
/*
	void freeLLNode(Node* head){

        Node *tmp = head;
        while( head != NULL){
                tmp = head;       
                head = head->next;
                free(tmp);}
        }
*/

	void insert(Node *hashtable[], int num){
	
		int index;
		int g = 0;
		if(num < 0){
		g = -1*num;
		index = g%10000;}else{		
		index = num%10000;}
		//printf("insert index = %d\n",index);
		Node *ele = newNode(num);

		if(hashtable[index] == NULL){
		
			hashtable[index] = ele;
			//ele -> next = hashtable[index];
			//printf("hash data = %d\n",hashtable[index]->data);
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
		


	/*
		//printf("here1");	
			Node *tmp;
		//printf("here2");
			tmp = hashtable[index];
		//printf("here3");
			if(ele -> data < tmp -> data){
			ele -> next = tmp;
			hashtable[index] = ele;
			printf("inserted\n");
                        return;}
		//printf("here");
			Node *prv = NULL;
			while(tmp != NULL && ele -> data > tmp -> data){
			
			//printf("here");
			if(ele -> data == tmp -> data){
			printf("duplicate\n");
			return;}

			prv = tmp;
			tmp = tmp -> next;
			}
		
			if(tmp ->data < ele -> data && tmp -> next == NULL){
			tmp -> next = ele;
			printf("inserted\n");
                        return;}

			ele -> next = tmp;
			prv ->next = ele;

			printf("inserted\n"); 
	
*/

	}


	void search(Node *hashtable[], int num){
		int index;
		int g = 0;			
		 if(num < 0){ 
                g = -1*num; 
                index = g%10000;}else{

		index = num % 10000;}
		Node *tmp;
                tmp = hashtable[index];
	
	//printf("search data = %d  indexdata = %d\n",num,hashtable[index] -> data);	
		while(tmp != NULL){
			if(tmp -> data == num){
			printf("present\n");
			return;	}
			tmp = tmp -> next;
			}

		printf("absent\n");
	
	
}
