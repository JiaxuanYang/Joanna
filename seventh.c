#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>


        int main(int argc, char *argv[]){

	if(argc == 1){printf("error\n");return 0;}       

	int size = argc - 1;
	char *curr = (char *)malloc(100*sizeof(char));
	char *res = (char *)malloc(100*sizeof(char));

	if(curr == NULL||res==NULL){printf("error\n");return 0;}

	int i,len, clen;
	for(i = 1; i <= size; i++){	
		strcpy(curr, argv[i]);	//copy inout word by word
		clen = strlen(curr);	//length of current word
		len = strlen(res);	//lenght of result string
		if(len != 0){
		res[len] = curr[clen-1];	//copy letter at the last index of current selected word
			}else{res[0] = curr[clen-1];}
	}
	
	
	printf("%s\n",res);

	free(curr);
	free(res);
	return 0;	
}
