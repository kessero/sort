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

int i, j, ch, tmp, n, max;

    printf("Podaj liczbę elementów: ");
    scanf("%d",&n);
    printf("Podaj max. wartość zbioru: ");
    scanf("%d",&max );
    printf("Podaj 1 jeśli rosnąco, 2 malejąco: ");
    scanf("%d", &ch);
    elements_array = malloc(sizeof(int)*n);
    random_range(n, max);

    for(j=0;j<n-1;j++)
    for(i=0;i<n-j-1;i++)
    {
      if(ch == 1){
        if(elements_array[i]>elements_array[i+1])
        {
            tmp=elements_array[i];
            elements_array[i]=elements_array[i+1];
            elements_array[i+1]=tmp;
        }
      }
      if(ch == 2){
        if(elements_array[i]<elements_array[i+1])
        {
            tmp=elements_array[i];
            elements_array[i]=elements_array[i+1];
            elements_array[i+1]=tmp;
        }
      }
    }
    printf("\nElementy posortowane:  ");
    for(i = 0; i < n; i++)
        printf("%d  ",elements_array[i]);
    printf("\n");
    free(elements_array);
    return 0;
}
