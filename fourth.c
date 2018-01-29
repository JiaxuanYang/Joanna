/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>




         int main(int argc, char *argv[]){
        
	FILE* file = fopen (argv[1], "r");

	 if(file == NULL){
        printf("error\n");
        return 0;
        }
        // check if exist


        fseek(file,0,SEEK_END);
        int size = ftell(file);
        if (size == 0){
        printf("0\n");
        return 0; 
        }
        rewind(file);


          int i = 0;
        int j = 0;
        fscanf (file, "%d", &i);
        int arr[i*i+1];
        int k = 0;
        while (!feof (file)){
      fscanf (file, "%d", &j);
        //printf ("%d\n", j);
                arr[k] = j;
                k++;}

	int arr1[i][i];
	int arr2[i][i];
	int arr3[i][i];

        int q = 0;
	int w, e;

        for(w = 0; w < i; w++){  
                for(e = 0; e < i; e++){
			arr2[w][e] = arr[q];  
                        arr1[w][e] = arr[q];
                        q++;
		//printf("%d\t",arr1[w][e]);
                        }	//printf("\n");
		}
	
	int exp = arr[i*i];
	int con = 1;
	int u, y, o, a, b;
	while(con < exp){
	for(u = 0; u < i; u++){ 
        for(y = 0; y < i; y++){	
		arr3[u][y] = 0;		//clear index
	for(o = 0; o < i; o++){
		arr3[u][y] += arr2[u][o]*arr1[o][y];
		}
			}
	}
	//memcpy(arr2,arr3,sizeof(arr2));
	for(a = 0; a < i; a++){
		for(b = 0; b < i; b++){
		arr2[a][b] = arr3[a][b];}
	
	}
	con++;
}

		int z, x;
		for(z = 0; z <i; z++){
			for(x = 0; x < i; x++){
				printf("%d\t", arr3[z][x]);
			}
				printf("\n");
		}

//free(buf);
//free(arr1);
//free(arr2);
//free(arr3);
fclose(file);

return 0;
}
*/




#include<stdio.h>
#include<stdlib.h>
#include <math.h>




void mxv(float **arr, float *vec, float * w,int r, int c);
void transpose(float **arr,float **xt,int row, int col);
void inverse(float **arr, float **inv, int row, int col);
void multiply(float **arr,float **arr2, float **ans, int row1, int col1, int r2, int c2);




int main(int argc, char*argv[]){


        FILE * file = fopen(argv[1], "r");
        //FILE * file2 = fopen(argv[2], "r");
        int end = 0;
        int row, col;

        fscanf(file,"%d",&col); 
        col = col +1;
        fscanf(file,"%d",&row); 
        row = row;


        float train[row][col];
        float str;
	float str1[row*col];



	int co = 0;
	
        /*store training data to str*/

        do{

                end = fscanf(file,"%f,",&str);
		str1[co] = str;
		co++;
                if(end == -1){break;}

        }while(end != -1);


        /*pass data to 2D array 'train'*/

        int a,b,c;
        c = 0;
        for(a = 0; a < row; a++){
                for(b = 0; b < col;b++){
                        train[a][b] = str1[c];
                        c++;
                }
        }


        /* for equation 'x*w = y', separate train to 'x' and 'y' */

        float x[row][col-1];
        float y[row];

        // for x

        for(a = 0; a < row; a++){
                for(b = 0; b < col-1;b++){
                        x[a][b] = train[a][b];
                }
        }

        //for y

        for(a = 0,b = col-1; a < row; a++){
                y[a] = train[a][b];
        }





        //start math : W = (X^T * X)-1 * X^T * Y


        float **xt = (float **)malloc(100*sizeof(float));                               //[col-1][row]; 
        transpose((float**)x,(float**)xt,row,col-1);


	for(a = 0;a < col-1;a++){
		for(b= 0; b < row;b++){
		printf("%f\t",xt[a][b]);
}
		printf("\n");
}
	




fclose(file);
return 0;
}

void transpose(float **arr, float **xt, int row, int col){

        //float arr2[col][row];

        int i,j;
        for(i = 0; i < row; i ++){
                for(j = 0; j < col; j++){

                        xt[j][i] = arr[i][j];
                }
        }

        //return  (float**)arr2;

}
