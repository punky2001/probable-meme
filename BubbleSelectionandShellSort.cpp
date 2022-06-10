#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

void bubblesort( string vetor[], int tam){
  string aux;
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

void selectionSort(string vetor[], int tam){
  int min, aux;
  for(int i =0; i<(tam-1);i++){
    min = i;
    for(int j = (i+1);j<tam;j++){
      if(vetor[j] < vetor[min])
        min = j;
    }
  }

}

void shell(string *vet, int n ){
  int aux, j, h;
  h = n/2;

  while(h>=1){
    for(int i =1;i < n;i++){
      aux = vet[i];

      for(j = i-h;(j>=0) && (vet[j] > aux);j=j-h){
        vet[j+h]=vet[j];
      }
      vet[j+h] = aux;
    }
    h = h/2;
  }
}



int main(){
    fstream arquivo;
    int n,tini, tfim,tms;
    string *vet1,*vet2, *vet3;
    string aux,linha;


    arquivo.open("aurelio40000.txt",fstream::in|fstream::out|fstream::app);

    cout << "entre com o valor de n:";
    cin>>n;
    while(n < 40000){
        vet1 = new string[n];
        vet2 = new string[n];
        vet3 = new string[n];


        for(int i=0; i<n ;i++){
            arquivo.open("aurelio40000.txt",fstream::in);
                if (arquivo.is_open()){
                    while(getline(arquivo,linha)){
                        vet1[i] = linha;
                        vet2[i] = linha;
                        vet3[i] = linha;

                    }
                }   
        }
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



}
