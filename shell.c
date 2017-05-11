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

int i, j, incr, tmp, n, max;

    printf("Podaj liczbę elementów: ");
    scanf("%d",&n);
    printf("Podaj max. wartość zbioru: ");
    scanf("%d",&max );
    elements_array = malloc(sizeof(int)*n);
    random_range(n, max);

    for(incr = n/2; incr > 0; incr /= 2)
    {
        for(i = incr; i < n; i++)
        {
            tmp = elements_array[i];
            for(j = i; j >= incr; j -= incr)
            {
                if(tmp < elements_array[j-incr])
                    elements_array[j] = elements_array[j-incr];
                else
                    break;
            }
            elements_array[j] = tmp;
        }
    }
    printf("\nElementy posortowane:  ");
    for(i = 0; i < n; i++)
        printf("%d  ",elements_array[i]);
    printf("\n");
    free(elements_array);
    return 0;
}
