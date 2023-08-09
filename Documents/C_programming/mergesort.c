#if 0
gcc -o $0.out $0 && ./$0.out
rm $0.out > /dev/null
exit
#endif

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define type char*
#define tp(x) _Generic((x), \
    int: "%d ", \
    char: "%c ", \
    float: "%f ", \
    double: "%f ", \
    char*: "%s ", \
    default: "Unknown format" \
)

typedef type my_type;

void mergehai(my_type A[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    my_type L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
      {
     //if (L[i] =< R[j])
     if (strcmp(L[i], R[j]) <= 0)   // Use strcmp for string comparison
          {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(my_type A[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        mergehai(A, l, m, r);
    }
}


void printArray(my_type A[], int size) {
    for (int i = 0; i < size; i++)
        printf(tp(A[i]) , A[i]);
    printf("\n\n");
}





int main(){
  //type A[]={23,4,343,221,1,5,6,1};
//  type A[]={42, 17, 99, 23, 8, 56, 73, 31, 61, 4, 88, 12, 7, 53, 29, 77, 6, 45, 92, 19, \
            37, 70, 3, 68, 11, 87, 50, 65, 14, 83, 97, 26, 9, 41, 72, 35, 59, 21, 79, 1 , \
            49, 16, 81, 33, 64, 22, 55, 93, 39, 75, 34, 66, 38, 84, 27, 74, 58, 24, 5, 91, \
            46, 15, 82, 67, 10, 89, 52, 20, 78, 2, 48, 18, 85, 63, 28, 76, 43, 69, 32, 60, \
            44, 13, 90, 25, 80, 57, 36, 98, 62, 30, 51, 86, 40, 71, 54, 95, 47, 100, 102};
// type A[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', \
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',   \
   'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd',   \
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'};

 my_type A[]={"azeza","azeckp", "java","zebra","abcd", "sata", "mango", "fruits", "hello",              \
    "world", "openai", "programming", "language", "computer",     \
    "science", "learning", "knowledge", "array", "example",       \
    "internet", "technology", "development", "experience", "challenge",  \
    "solution", "innovation", "creative", "problem", "solution",         \
    "inspiration", "imagination", "opportunity", "future", "success"};



  int arr_size=sizeof(A)/sizeof(A[0]);
  printf("Given array is \n ");
  printArray(A,arr_size);
  mergeSort(A,0,arr_size-1);
  printf("The sorted array form is ");
  printArray(A,arr_size);
  return 0;
}
