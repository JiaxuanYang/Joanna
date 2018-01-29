#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "learn.h"



void mxv(double **arr,double *vec, double * w,int r, int c);
void transpose(double **arr,double **xt,int row, int col);
void inverse(double **arr,double **inv, int row, int col);
void multiply(double **arr,double **arr2,double **ans, int row1, int col1, int r2, int c2);




int main(int argc, char*argv[]){



	FILE * file = fopen(argv[1], "r");
	FILE * file2 = fopen(argv[2], "r");
	int end = 0;
	int row, col;

	fscanf(file,"%d",&col); 
	col = col +1;
	fscanf(file,"%d",&row); 
	row = row;


	double train[row][col];
	double str[row*col+1];
	double num;
	

	int a, b, c;


	/*store training data to str*/

	do{

		end = fscanf(file,"%lf,",&num);
		if(end == -1){break;}
		str[a] = num;
		a++;
	}while(end != -1);


	/*pass data to 2D array 'train'*/
	
	c = 0;
	for(a = 0; a < row; a++){
		for(b = 0; b < col;b++){
			train[a][b] = str[c];
			c++;


		}
	
}

	/* for equation 'x*w = y', separate train to 'x' and 'y' */

 
	double **x = (double**)malloc(row*sizeof(double*));
         for(a = 0; a < row; a++){
                x[a] = (double*)malloc((col)*sizeof(double));}		//x = [row][col];
 


	double *y = (double*)malloc(row*10*sizeof( double));		//y = [row];



	// for x

	for(a = 0; a < row;a++){

	x[a][0] = 1;
}
	
	for(a = 0; a < row; a++){
		for(b = 1, c = 0; b < col && c < col-1;b++,c++){		
			
			x[a][b] = train[a][c];
			
	
		}
	
	}


	for(a = 0,b = col-1; a < row; a++){
		y[a] = train[a][b];

	}
	//start math : W = (X^T * X)^-1 * X^T * Y


	// for (X^T)

	double **xt = (double **)malloc((col)*sizeof(double*));		//[col][row]; 	

	for(a = 0; a < col; a++){
                xt[a] = (double*)malloc(row*sizeof(double));
}	

	transpose((double**)x,(double**)xt,row,col);


	// for (X^T * X)

        double **multi = (double **)malloc((col)*sizeof(double*)); 	//[col][col];
	for(a = 0; a < col; a++){
                multi[a] = (double*)malloc((col)*sizeof(double));}

	multiply((double**)xt,(double**)x,(double **)multi,col,row,row,col);

	// for (X^T * X)^-1

	double **inv = (double **)malloc((col)*sizeof(double*)); 	//[col][col];
	for(a = 0; a < col; a++){
                inv[a] = (double*)malloc((col)*sizeof(double));}

	inverse((double**)multi,(double **)inv, col,col);


	// for (X^T * X)^-1 * X^T

	double **mul2 = (double **)malloc((col)*sizeof(double*));	//[col][row];
	for(a = 0; a < col; a++){
                mul2[a] = (double*)malloc(row*sizeof(double));}

	multiply((double**)inv,(double**)xt,(double **)mul2, col,col,col,row);


	// for (X^T * X)^-1 * X^T * Y
	
	double *w = (double *)malloc(row*10*sizeof(double)); 					//[col]; 


	mxv((double**)mul2,(double*)y,(double *)w, col,row);



	/* store test data */

	int row2, col2; 
	fscanf(file2,"%d",&row2);
	col2 = col-1;
	double str2[row2*col2+1];
	double num2;	

	end = 0;
	a = 0;
	do{

		end = fscanf(file2,"%lf,",&num2);
		if(end == -1){break;}
		str2[a] = num2;	
		a++;

	}while(end != -1);



	//store info of test data to array, test = w for 'x * w = y'

	double **test = (double**) malloc(row2*sizeof(double*));				//[row2][col2];

	for(a = 0; a < row2; a++){
                test[a] = (double*)malloc((col2+1)*sizeof(double));}

	for(a = 0; a < row2; a++){
	test[a][0] = 1;
}
	c = 0;
	for(a = 0; a < row2; a++){
		for(b = 1; b < col2+1;b++){
			test[a][b] = str2[c];
			c++;
		
		}
	}


	double *final = (double *)malloc(row2*10*sizeof(double));		 		//[row2];

	// x * w = y

	mxv((double**)test,(double*)w, (double *)final, row2,col2+1);



	//print final result

	for(a = 0; a < row2; a++){

		printf("%0.0lf\n",final[a]);		

	}


 for(a = 0; a < row; a++){
            free(x[a]);}

for(a = 0; a < col-1; a++){
	 free(xt[a]);                
        free(multi[a]);            
        free(inv[a]);  
        free(mul2[a]);}

 for(a = 0; a < row2; a++){
        free(test[a]);
}



	free(x);
	free(y);
	free(xt);
	free(multi);
	free(inv);
	free(mul2);
	free(w);
	free(test);
	free(final);

	fclose(file);
	fclose(file2);

	return 0;
}






// Multiply matrix with vector 'y' 

void mxv(double **arr, double *vec, double * w, int r, int c){


	//float w[r];
	int i,j;
	for(i = 0; i < r; i++){
		w[i] = 0;
		for(j = 0; j < c; j++){
		
			w[i] += arr[i][j] * vec[j];

		}
	}

	

}//finish mxv







// Find transpose of a matrix 

void transpose(double **arr, double **xt, int row, int col){

	

	int i,j;
	for(i = 0; i < row; i ++){
		for(j = 0; j < col; j++){

			xt[j][i] = arr[i][j];
		}
	}

	

}//finish transpose





// Find inverse of a matrix 

void inverse( double **arr, double **result, int row, int col){

	
	double arr2[row][col*2];
	int i,j;




	//set all entries to 0

	for(i = 0; i < row; i++){
		for(j = 0; j < col*2; j++){
			arr2[i][j] = 0;
		}
	}




	//copy arr to left side of arr2

	for(i = 0; i < row; i++){		
		for(j = 0; j < col; j++){
			arr2[i][j] = arr[i][j];

		}
	}


	//place 1's on the right diagonal

	for(i = 0,j = col; i < row && j < col*2; i++, j++){
		arr2[i][j] = 1;
	}



	// start gauss-jordan elimination


	//make all pivots on diagonal = 1, divide whole row by  pivot 

	int k, z, h;
	double tmp,mul;
	for(i = 0, j = 0; j < col*2 && i < row; i++, j++){

		if(fabs(arr2[i][j] -1) > 0.000000001){




			if(fabs(arr2[i][j] - 0) < 0.0000000001){
				if(i+1<row){for(k = i+1; k <row;k++){
					if(fabs(arr2[k][j]-0) > 0.0000000001){
						for(h = 0; h < col*2;h++){
							arr2[i][h] += arr2[k][h];   
						}
						break;
					}
				}}
				i = 0; j = 0;
			}



			tmp = arr2[i][j];
			for(h = 0; h < col*2; h++){

				arr2[i][h] = arr2[i][h]/tmp;}
		}
		tmp = arr2[i][h];	





		//set other numbers in pivot col = 0

		


		for(k = 0; k < row; k++){

			if(k != i){
				if(fabs(arr2[k][j] - 0) > 0.000000001){
					
					mul = arr2[k][j];
					
					for(z = j; z < col*2;z++){

						arr2[k][z] = arr2[k][z] - mul*arr2[i][z];
					}

				}
			}

		}


	}




	//pass inverse to result array

	int f,g, b;
	for(f = 0; f < row; f++){
		for(b = 0, g = col; g < col*2 && b < col; g++,b++){

			result[f][b] = arr2[f][g];}

	}



	

}//finish inverse




//Multiply 2 matrices 

void multiply(double **arr,double **arr2,double **arr3, int r1,int c1,int r2,int c2){

	
	int i, j, k;


	for(k = 0; k < r1; k++){

		for(i = 0; i < c2; i++){
			arr3[k][i] = 0;
			for(j =0; j < r2; j++){
				arr3[k][i] += arr[k][j] * arr2[j][i];
				
			}
		}
	}

	

}//finish multiply


