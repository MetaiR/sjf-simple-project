#include<iostream>
using namespace std;
/*
 struct Times
 {
 int InputTime = NULL;
 int ProcessTime = NULL;
 }time[100];
 */
void quickSort(int [], int , int );
int lastestOutput(int[], int &);

//Times time[100];

int m = 0;
int InputTime[100];
int ProcessTime[100];
int main(){
    
    
    int waitingTime[100];
    
    cout << " please enter number of the programs:";
    cin >> m;
    cin.get();
    
    for (int i = 1; i <= m; i++)
    {
        cout << "InputTime[" << i << "]:";
        cin >> InputTime[i];
        cout << "ProcessTime[" << i << "]:";
        cin >> ProcessTime[i];
        
        
    }
    for (int i = 1; i <= m; i++){
        if (InputTime[i] == InputTime[1]){
            waitingTime[i] = lastestOutput(ProcessTime, i) - InputTime[i] - ProcessTime[i];
            cout << "\nwaiting Time[" << i << "]: " << waitingTime[i];
        }
        else
        {
            //quickSort(ProcessTime, i , m);
            quickSort(ProcessTime, ProcessTime[i], ProcessTime[m]);
            waitingTime[i] = lastestOutput(ProcessTime, i) - InputTime[i] - ProcessTime[i];
            cout << "\nwaiting Time[" << i << "]: " << waitingTime[i];
        }
    }
    cin.get();
    cin.get();
    return 0;
}
/*********************************************************************************/
int lastestOutput(int processTime[], int &m){
    int lastestOutput = 0;
    for (int i = 1; i <= m; i++)
    {
        if (InputTime[i] == InputTime[1])
        {
            lastestOutput = processTime[1];
        }
        
        else //if (processTime[i] < lastestOutput)
        {
            quickSort(processTime, processTime[i], processTime[m]);
            lastestOutput += processTime[i];
        }
    }
    
    return lastestOutput;
}
/*********************************************************************************/
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}