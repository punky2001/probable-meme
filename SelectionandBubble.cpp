#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubblesort(int vetor[], int tam){
  int aux;
  for(int i =0; i <tam;i++){
    for(int j = 0; j < tam - 1 - i;j++){
      if(vetor[j+1]<vetor[j]){
        aux = vetor[j];
        vetor[j]=vetor[j+1];
        vetor[j+1]=aux;
      }
    }
  }
}

void selectionSort(int vetor[], int tam){
  int min, aux;
  for(int i =0; i<(tam-1);i++){
    min = i;
    for(int j = (i+1);j<tam;j++){
      if(vetor[j] < vetor[min])
        min = j;
    }
  }

}




int main() {
    int tini, tfim,tms;
    int n, aux, *vet1,*vet2;

    cout << "entre com o valor de n:";
    cin>>n;

    vet1 = new int[n];
    vet2 = new int[n];

    for(int i = 0; i <n;i++){
      aux = rand()%1000;
      vet1[i]=aux;
      vet2[i]=aux;
     }

    tini = (int)clock();
    selectionSort(vet1, n);
    tfim=(int)clock();

    tms = ((tfim-tini)*1000/CLOCKS_PER_SEC);
    cout << "Tempo total:" << tms << endl;
    tini = (int)clock();
    bubblesort(vet2,n);
    tfim=(int)clock();
    tms = ((tfim-tini)*1000/CLOCKS_PER_SEC);
    cout << "Tempo total:" << tms << endl;



  return 0;
}
