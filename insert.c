#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *elements_array = NULL;

void random_range(int n, int max) {
  int r, i;
  int N = 1,
      M = max;
  srand (time(NULL));


  for(i=0; i < n ; i++){
     r = M + rand() / (RAND_MAX / (N - M + 1) + 1);
     elements_array[i] = r;
  }
  printf("Elementy zbioru: ");
  for(i=0; i < n ; i++){
     printf("%d,", elements_array[i]);
  }

}
int main(){

int i, j, tmp, n, max;

    printf("Podaj liczbę elementów: ");
    scanf("%d",&n);
    printf("Podaj max. wartość zbioru: ");
    scanf("%d",&max );  
    elements_array = malloc(sizeof(int)*n);
    random_range(n, max);

    for(i=1;i<n;i++){
      tmp=elements_array[i];
      j=i-1;
      while((tmp<elements_array[j])&&(j>=0)){
      elements_array[j+1]=elements_array[j];
          j=j-1;
      }
      elements_array[j+1]=tmp;
    }
    printf("\nElementy posortowane:  ");
    for(i = 0; i < n; i++)
        printf("%d  ",elements_array[i]);
    printf("\n");
    free(elements_array);
    return 0;
}
