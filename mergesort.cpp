#include<stdio.h>

int arr[8]={8, 7, 6, 5, 4, 3, 2, 1};

int merge(int arr[], int l, int m, int h)
{
    int arr1[10], arr2[10];
    int n1, n2, i, j, k;
    n1 = m - l + 1;
    n2 = h - m;

    for(i = 0; i < n1; i++)
        arr1[i] = arr[l + i];

    for(j = 0; j < n2; j++)
        arr2[j] = arr[m + j + 1];

    arr1[i] = 9999;
    arr2[j] = 9999;

    i = 0;
    j = 0;
//laco que realiza a fusao das partes do vetor
    for(k = l; k <= h; k++)
    {
        if(arr1[i] <= arr2[j])
            arr[k] = arr1[i++];
        else
            arr[k] = arr2[j++];
    }

    return 0;
}
//funcao que realiza a divisao do vetor
int merge_sort(int arr[],int low,int high)
{

    int mid; //variavel que guarda a metade do vetor

    if(low < high) 
    {
        mid = (low + high) / 2;

        // Dividir e conquistar
        merge_sort(arr, low, mid); //inicio ate o meio

        merge_sort(arr, mid + 1, high); //meio mais um ate o fim

        // Combinar
        merge(arr, low, mid, high); //vetor, menor valor, meio, maior valor
    }

    return 0;
}

int main()
{
    int i;
    printf("Vetor desordenado: ");
    for(i=0;i<8;i++){
    	printf("%d", arr[i]);
	}
	
	merge_sort(arr, 0, 7); //funcao de ordenacao: vetor, valores minimo e maximo

    printf("\n\nVetor ordenado...: ");

    for(i = 0; i < 8; i++)
        printf("%d", arr[i]);

    return 0;
}
