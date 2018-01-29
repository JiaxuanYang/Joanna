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
//check if file is empty

          int i = 0;
        int j = 0;
        fscanf (file, "%d", &i);
        int arr1[i*i+1];
        int k = 0;
        while (!feof (file)){
      fscanf (file, "%d", &j);

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
		
		}

	}

	


//check repeat

	int f,g;

	for(a = 0; a < row;a++){
		for(s = 0; s <col; s++){
	for(f = 0; f < row; f++){
		for(g = 0;g < col; g++){
		
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
	
}






//check horizontal

int sum = 0;

       
        for(f = 0; f < row; f++){
                for(g = 0; g < col; g++){
                        sum += arr[f][g];
                }
                if(sum == magicNumber){
                        sum = 0;}
                else{ printf("not-magic\n");
			return 0;}
        }
        
	
//check vertical

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

	

//check diagonals

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


