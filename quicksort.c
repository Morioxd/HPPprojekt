#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
//include <omp.h>

int *median_pivot(int *list){
    if(len(list) == 1){
      return list;
    }
    else{
      int list_length = len(list);
      int median = (list_length/2)-1;
      int *new_list_smaller = malloc(list_length-1 * sizeof(int)); // Will at most be as big as previous list - 1
      int *new_list_bigger = malloc(list_length-1 * sizeof(int));
      int small_size = list_length-1 * sizeof(int);
      int big_size = list_length-1 * sizeof(int);
      int pivot = list[median]; // Take the length/2 and subtract 1 to get the median element inside that list
      for(int i = 0; i < list_length; i++){
          if (list[i] < pivot){
            new_list_smaller[list_length-1 * sizeof(int) - small_size] = list[i];
            small_size--;
          }
          else if(list[i] > pivot){
            new_list_bigger[list_length-1 * sizeof(int) - big_size] = list[i];
            big_size--;
          }          
      }
      int *result_small = median_pivot(new_list_bigger);
      int *result_big = median_pivot(new_list_smaller);
      

    }
}

int main(int argc, char* argv[]) {
if(argc != 3) {
    printf("Please give 2 arguments: N (number of elements to sort) and nThreads.\n");
    return -1;
  }
  int N = atoi(argv[1]);
  int nThreads = atoi(argv[2]);
  printf("N = %d, Threads = %d\n", N, nThreads);
  if(N < 1 || nThreads < 1) {
    printf("Error: (N < 1 or nThreads < 1).\n");
    return -1;
  }

  int* list_to_sort = (int*)malloc(N * sizeof(int));
  for(int i = 0; i < N; i++)
    list_to_sort[i] = rand() % 100;

}

