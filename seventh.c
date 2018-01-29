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
		strcpy(curr, argv[i]);
		clen = strlen(curr);
		len = strlen(res);
		if(len != 0){
		res[len] = curr[clen-1];	
			}else{res[0] = curr[clen-1];}
	}
	
	
	printf("%s\n",res);

	free(curr);
	free(res);
	return 0;	
}
