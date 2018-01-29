#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

        int main(int argc, char *argv[]){


                if(argc >= 3 || argc == 1){
                printf("error\n");
                return 0;}

		int *res = (int *)malloc(100*sizeof(int));
                char *result = (char *)malloc(100*sizeof(char));
                if(result==NULL){printf("error\n");return 1;}
                 int count = 1;


                int len = strlen(argv[1]);

                char *curr = (char *) malloc(100*sizeof(char));
                if(curr==NULL){printf("error\n");return 0;}

                //char curr[len];

                strcpy(curr,argv[1]);
                int i;
                if(len == 1){
                printf("%s\n",argv[1]);
                return 0;}

                for(i = 0; i < len; i++){if(isdigit(curr[i])){printf("error\n");return 0;}}


                for(i = 0; i <= len-1; i++){
                        while(curr[i] == curr[i+1] && i +1 <= len-1){
                        i++;
                        count++;}

                        int tplen = strlen(result);
                        if(tplen != 0){
                        result[tplen] = curr[i];
        	              
					
			res[tplen] = count;

		//  result[tplen+1] = count + '0';
                }else{result[0] = curr[i];

			res[0] = count;
                       // result[1] = count +'0';
                        }
                        count = 1;

                        }





        int orlen = strlen(argv[1]); 
        //sizeof(argv[1])/sizeof(char);
        int reslen = strlen(result)*2;
        //sizeof(result)/sizeof(result[0]);
        //printf("%d  %d\n", reslen, orlen);


        if(reslen > orlen){
	printf("%s\n",curr);
       // printf("%s\n", result);
        }
        else{
         int v;
        for(v = 0; v < reslen/2;v++){  
                printf("%c",result[v]);                   
                printf("%d",res[v]);
                }
        printf("\n");

}
        free(curr);
        free(result);
	free(res);
        return 0;
}

