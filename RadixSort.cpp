#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define SIZE 200 // tamanho do vetor
#define LENGTH 3 // comprimento dos números (100 a 999)
#define MAX_VALUE 10 // valor máximo de cada dígito + 1 (0 a 9)

// possui complexidade O(n+k)
// trocar vet[i] por (vet[i]/div)%10, para pegar apenas o dígito específico.
void counting_sort(int* vet, int div) {

  int aux[MAX_VALUE];
  for(int i =0; i<MAX_VALUE; i++){
    aux[i] = 0;
  }

  for(int i =0; i< SIZE; i++){
    aux[(vet[i]/div)%10]+=1;
  }

  for(int i =1; i <MAX_VALUE;i++){
    aux[i] += aux[i-1];
  }

  int out[SIZE];
  for(int i = SIZE-1; i>=0;i--){
    out[aux[(vet[i]/div)%10]-1] = vet[i];
    aux[(vet[i]/div)%10]-=1;
  }

  for(int i =0; i <SIZE;i++){
    vet[i] = out[i];
  }
}

// encontra maior valor - compelxidade O(n)
int max_value(int *vet) {
  int m = vet[0];
  for(int i = 0; i < SIZE; i++)
    if (m < vet[i]) m = vet[i];
  return m;
}

// possui complexidade O(d*(n+k))
void radix_sort(int* vet) {
    int maior =max_value(vet);
    for(int div = 1; maior/div > 0; div *= 10 ){
      counting_sort(vet, div);
    }
}

int main() {
  int vet1[SIZE];

  for(int i = 0; i < SIZE; i++)
    vet1[i] = 100 + rand() % ((int)pow(10, LENGTH)-100); // sorteia (100 a 999)

  for(int i = 0; i < SIZE; i++)
    cout << vet1[i] << " ";

  cout << "\nVetor ordenado: " << endl;
  radix_sort(vet1);
  for(int i = 0; i < SIZE; i++)
    cout << vet1[i] << " ";

    return 0;
}
