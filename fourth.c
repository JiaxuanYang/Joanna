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
        int arr[i*i+1];
        int k = 0;
        while (!feof (file)){
      fscanf (file, "%d", &j);
        
                arr[k] = j;
                k++;}

        int arr1[i][i];
        int arr2[i][i];
        int arr3[i][i];

        int q = 0;
        int w, e;

        for(w = 0; w < i; w++){  
                for(e = 0; e < i; e++){
                        arr2[w][e] = arr[q];  	//copy information two two matrix
                        arr1[w][e] = arr[q];
                        q++;
                
                        }       
                }

        int exp = arr[i*i];
        int con = 1;
        int u, y, o, a, b;
        while(con < exp){
        for(u = 0; u < i; u++){ 	//doing math: matrix^2
        for(y = 0; y < i; y++){
                arr3[u][y] = 0;         //clear index[u][y]
        for(o = 0; o < i; o++){
                arr3[u][y] += arr2[u][o]*arr1[o][y];
                }
                        }
        }
        
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

fclose(file);

return 0;
}

