/*Devam Desai
OS Threads Assignment Program 2 */



#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>



#define N 3
int int_arr1[N][N],int_arr2[N][N];
int** ans;
int cur_row=0;
void * multiply (void * p){
    int** vec=(int **)p;
    int k=cur_row++;

    for(int i=0;i<N;i++){
        int sum=0;
        for(int j=0;j<N;j++){
            sum+=int_arr1[k][j]*int_arr2[j][i];
        }
        vec[k][i]=sum;
    }
    pthread_exit(NULL);
}
int main(){
	

	clock_t t;
    t = clock();
    // code 
    // Declare integer array [1,2,3,4,5,6,7,8,9,10]:
    
    int val=0;
    ans=(int **) malloc( sizeof(int *)*N);
    for(int i = 0; i < N; i++){
        ans[i]=(int * )malloc(sizeof(int)*N);
       for(int j=0;j<N;j++){
            int_arr1[i][j]=val++;
            printf("%d ",int_arr1[i][j]);
       }
       printf("\n");
    }
    printf("  X     \n");
    for(int i = 0; i < N; i++){
       for(int j=0;j<N;j++){
            int_arr2[i][j]=val--;
            printf("%d ",int_arr2[i][j]);
       }
       printf("\n");
    }
    
    // data thread_data[N];
//     for(int i=0;i<4;i++){


//     thread_data[i].thread_num = i;
//     thread_data[i].arr = int_arr;
// }
    
    printf("\n\n\n");
    pthread_t tid[N];
    
    for(int i=0;i<N;i++){
//        int vec[N];
        pthread_create(&tid[i], NULL, multiply, ans);
    }
    
    
    // Declare space for sum:
  //  int** sums[N];
   
    
    // Retrieve sum of threads:
    for(int i=0;i<N;i++)
    pthread_join(tid[i], NULL);
    
   
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }    




    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nTime taken= %.6lf",time_taken);

	return 0;
}
