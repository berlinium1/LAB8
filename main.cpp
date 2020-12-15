
//
//  main.cpp
//  LAB8
//
//  Created by Берлинский Ярослав Владленович on 11.11.2020.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;
typedef float matrix[10][10];
int n;
void matrix_generation(matrix, int, int, int);
void matrix_output(matrix, int, int);
float abs_maximum(matrix, int*, int*);
void delete_row_and_column(matrix, int, int);
int main(){
    int begin, end, eps;
    float max;
    matrix A;
    int row, column;
    do{
        cout<<"Введіть розмірність квадратної матриці: "; cin>>n;
        cout<<"Нижня межа генерації: "; cin>>begin;
        cout<<"Верхня межа генерації: "; cin>>end;
        cout<<"Кількість розрядів після коми: "; cin>>eps;
    }
    while(eps<0 || begin>end || n<=0);
    matrix_generation(A, begin, end, eps);
    matrix_output(A, n, eps);
    max=abs_maximum(A, &row, &column);
    cout<<"Максимальний за модулем елемент: "<<max<<endl;
    cout<<"Фізичний номер: "<<"["<<row<<"]["<<column<<"] "<<endl;
    cout<<"Логічний номер: "<<"["<<row-1<<"]["<<column-1<<"] "<<endl;
    delete_row_and_column(A, row, column);
    matrix_output(A, n, eps);
}
float abs_maximum(matrix A, int *prow, int *pcol){
    float max_abs=A[0][0];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (fabs(A[i][j])>=fabs(max_abs)){
                max_abs=A[i][j];
                *prow=(i+1);
                *pcol=(j+1);
            }
        }
    }
    return max_abs;
};
void matrix_generation(matrix A, int begin, int end, int eps){
    srand(time(NULL));
    cout<<"Матриця: "<<endl;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            A[i][j]=begin+rand()%(end-begin)+(float)(rand()%((int)(pow(10,eps)))/pow(10,eps));
}
void matrix_output(matrix A, int n, int eps){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        cout<<fixed<<setprecision(eps)<<setw(4*eps)<<A[i][j];
        cout<<endl;
    }
}
void delete_row_and_column(matrix A, int k1, int k2){
    for (int i=k1-1; i<n-1; i++)
        for (int j=0; j<n; j++)
        A[i][j]=A[i+1][j];
    
    for (int i=k2-1; i<n-1; i++)
        for (int j=0; j<n; j++)
        A[j][i]=A[j][i+1];
    n--;
}
