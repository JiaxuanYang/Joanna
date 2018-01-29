#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


///////////////////////////////////////
static void sort(int arr[], int l, int r);
static void merge(int arr[], int lo, int mi, int hi);
///////////////////////////////////////////////////////


        int main(int argc, char *argv[]){

//printf("error");
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
  	int arr[i];
  	int k = 0;
  	while (!feof (file)){
      fscanf (file, "%d", &j);
       // printf ("j = |%d|\n", j);
                arr[k] = j;
                k++;}
/*
	int y;
	for(y = 0; y < i; y ++){printf("here array = %d end\t",arr[y]);}
	printf("\n");
*/

	sort(arr,0,i-1);
	

	int b;
	for(b = 0; b < i; b++){
 		printf("%d\t", arr[b]);
	}
	printf("\n");


	//free(buf);
	fclose(file);	

	return 0;
}
	
	void merge(int arr[], int lo,int mi, int hi){



	int lhalf[mi-lo+1];
	int rhalf[hi-mi];
	
	int a,b;
	for(a = 0; a < (mi-lo+1); a++){
		lhalf[a] = arr[lo+a];}
	for(b = 0; b < (hi-mi); b++){
		rhalf[b] = arr[mi+b+1];}

	int i = 0, j = 0, k = lo;

	while(j < (mi-lo+1) && i< (hi-mi)){
		if(lhalf[j] <= rhalf[i]){
			arr[k] = lhalf[j];j++;k++;}
		else{arr[k] = rhalf[i]; i++; k++;}
		}

	while(j < (mi-lo+1)){arr[k] = lhalf[j]; k++; j++;}
	while(i < (hi-mi)){arr[k] = rhalf[i];k++;i++;}

	}


	void sort(int arr[],int l, int r){
/*
	 int c;
        for(c = l; c < r; c++){
        printf("%d\t",arr[c]);}
	printf("\n");
*/

	int mid;

	if(l < r){
	mid = (l+r)/2;
	sort(arr,l,mid);
	sort(arr,mid+1,r);
	merge(arr,l,mid,r);
	}else{return;}


	}
