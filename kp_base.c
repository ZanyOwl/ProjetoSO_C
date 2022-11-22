#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
    //n Define o numero de items que podem ser postos dentro da mala
    int num_items;
    //weight é o peso maximo que a mala pode levar
    int weight;
    //A matriz values vai ser do tamanho do numere de items e vai guarda as combinações de pares
    //que vem no ficheiro de texto  
    int values[50];
    int weights[50];

    //Vai criar a memoria partilhada
    int size = 64;
    int protection = PROT_READ | PROT_WRITE;
    int visibility = MAP_ANONYMOUS | MAP_SHARED;
    void *shmem = mmap(NULL, size, protection, visibility, 0, 0);



    return 0;
}

//Resolve o problema e devolve um valor para cada processo depois comparar com a solução do ficheiro
//e puder colocar em memória partilhada
int sol_kp(int weight, int weights[], int values[], int num_items){
    if (num_items == 0 || weight == 0){
        return 0;
    }

    if(weights[num_items - 1] > weight){
        return sol_kp(weight, weights, values, num_items - 1);
    }
    else {
        return max(values[num_items - 1] + sol_kp(weight - weights[num_items - 1], weight, values, num_items - 1), sol_kp(weight, weights, values, num_items - 1));
    }
}

int max(int x, int y){return (x > y) ? x : y;}