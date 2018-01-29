#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/*
typedef enum _boolean {FALSE, TRUE} boolean;
static boolean vertical(int *arr, int row, int col);
static boolean horizontal(int *arr, int row, int col);
static boolean diagonal(int *arr, int row, int col);
*/

int main(int argc, char *argv[]){

	/*int file = open("file.txt", O_RDONLY);

	int *buf = (int *) malloc(100*sizeof(int));
	int tf;
	do{
		tf = read(file, buf, 100*sizeof(buf));
	}while(tf != 0);
*/
	

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
        int arr1[i*i+1];
        int k = 0;
        while (!feof (file)){
      fscanf (file, "%d", &j);
       // printf ("%d\n", j);
                arr1[k] = j;
                k++;}


	int row = i;
	int col = i;
	int arr[i][i];
	int z = 0;

	int a, s;
	for(a = 0; a < row; a++){
		for(s = 0; s < col; s++){
			arr[a][s] = arr1[z];
			z++;
		//printf("%d\t",arr[a][s]);
		}//printf("\n");

	}

	//if(horizontal((int*)arr, row, col) == TRUE && vertical((int *)arr, row, col) == TRUE && diagonal((int*)arr,row, col) == TRUE){
		//printf("magic");}else{printf("not-magic");}
////////////////////////////////////////////////////////////////////


//check repeat

	int f,g;

	for(a = 0; a < row;a++){
		for(s = 0; s <col; s++){
	for(f = 0; f < row; f++){
		for(g = 0;g < col; g++){
		//if(f == a && g == s){g++;}
		//if(g >= col){break;}
		if(arr[a][s]==arr[f][g]){
		if(a != f && s != g){
		printf("not-magic\n");
		return 0;}}

	}
}	
			
	}
}









int magicNumber = 0;
int h;
for(h = 0; h < row; h++){
	magicNumber += arr[0][h];
	//printf("%d\n",arr[0][h]);
}
//printf("magic num is %d, i = %d",magicNumber,i);






//horizontal

int sum = 0;

        //int f, g;
        for(f = 0; f < row; f++){
                for(g = 0; g < col; g++){
                        sum += arr[f][g];
                }
                if(sum == magicNumber){
                        sum = 0;}
                else{ printf("not-magic\n");
			return 0;}
        }
        
	
//vertical

 	sum = 0;

        f=0;
	g=0;
        for(f = 0; f < col; f++){
                for(g = 0; g < row; g++){
                        sum += arr[g][f];
                }    
                if(sum == magicNumber){
                        sum = 0;}
                else{printf("not-magic\n");
			return 0;}

        }        

	

//diagonals

 	sum = 0;             

        //left to right                  
         f = 0;	g = 0;    
        for(f = 0, g = 0; f < row && g < col; f++, g++){
                sum += arr[f][g];
        }
        if(sum != magicNumber){
                printf("not-magic\n");
		return 0;}


        //right to left
        int sum2 = 0;
        int r, x;
        for(r = 0, x = col-1; r < row && x >= 0; r++, x--){
                sum2 += arr[r][x];  
		
        }           
        if(sum2 != magicNumber){
                printf("not magic\t");
		return 0;}


	printf("magic\n");
//////////////////////////////////////////////////////////////////////	
	fclose(file);

	return 0;
}


/*boolean horizontal(int *arr, int row, int col){

	//int row = sizeof(arr)/sizeof(arr[0]);
	//int col = sizeof(arr[0]);
	int sum = 0;

	int i, j;
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			sum += arr[i][j];	
		}
		if(sum == 15){
			sum = 0;}
		else{ return FALSE;}
	}
	return TRUE;
}



boolean vertical(int **arr, int row, int col){

	//int row = sizeof(arr)/sizeof(arr[0]);
	//int col = sizeof(arr[0]);
	int sum = 0;

	int i, j;
	for(j = 0; j < col; j++){
		for(i = 0; i < row; i++){
			sum += arr[i][j];
		}
		if(sum == 15){
			sum = 0;}
		else{return FALSE;}

	}

	return TRUE;
}
boolean diagonal(int **arr, int row, int col){

	//int row = sizeof(arr)/sizeof(arr[0]);
	//int col = sizeof(arr[0]);
	int sum = 0;

	//left to right
	int i, j;
	for(i = 0, j = 0; i < row && j < col; i++, j++){
		sum += arr[i][j];
	}
	if(sum != 15){
		return FALSE;}


	//right to left
	int sum2 = 0;
	int z, x;
	for(z = 0, x = col-1; z < row && x >= 0; z++, x--){
		sum += arr[z][x];
	}
	if(sum2 != 15){
		return FALSE;}


	return TRUE;
}
*/
