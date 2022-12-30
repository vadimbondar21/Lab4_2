#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Опис функцій
void print_array( int **A, int **B, int rows, int col);
void max_min(int **A,int rows,int col);
void trans_B(int **B,int **T,int rows,int col);
void dobutok_arrays(int **A,int **B,int **Prod,int rows,int col);
void sort_A(int **A,int rows,int col);
void sum_of_arrays(int **A,int **B,int rows,int col);

//========================================================

int main()
{
    int entering_the_matrix,task_selection,rows,col,Exit;
    int **A = NULL;
    int **B=NULL;
    int **Dobutok=NULL;
    int **T=NULL;

    printf("\nEnter the matrix size:");//Задаємо розмір матриці
    printf("\nRows:");
    scanf("%d", &rows);
    printf("\nColumns:");
    scanf("%d", &col);
    system("cls");

    A=(int**) malloc(rows * sizeof(int));//Виділяємо пам'ять
     if( A == NULL )
    {
        printf("Error memory was not allocated");//Якщо пам'ять не виділена, то виводимо про це повідомлення
        exit(0);
    }
    for(int i=0;i<rows;i++){
        A[i]=(int*) malloc(col * sizeof(int));
        if(A[i]==NULL)
        {
            printf("Error memory was not allocated");
            exit(0);
        }
    }

    B=(int**) malloc(col * sizeof(int));
     if( B == NULL )
    {
        printf("Error memory was not allocated");
        exit(0);
    }
    Dobutok=(int**) malloc(col * sizeof(int));
     if( Dobutok == NULL )
    {
        printf("Error memory was not allocated");
        exit(0);
    }
    T=(int**) malloc(rows * sizeof(int));
     if( T == NULL )
    {
        printf("Error memory was not allocated");
        exit(0);
    }

    for(int i=0;i<col;i++){
        B[i]=(int*) malloc(rows* sizeof(int));
        if(B[i]==NULL)
        {
            printf("Error memory was not allocated");
            exit(0);
        }
        Dobutok[i]=(int*) malloc(rows* sizeof(int));
        if(Dobutok[i]==NULL)
        {
            printf("Error memory was not allocated");
            exit(0);
        }
        T[i]=(int*) malloc(col * sizeof(int));
        if(T[i]==NULL)
        {
            printf("Error memory was not allocated");
            exit(0);
        }
    }

    do{
    printf("Choose a method");
    printf("\n\n1.Randomly\n2.Manually\n");//Вибираємо метод задання матриці
    scanf("%d",&entering_the_matrix);
    }while(entering_the_matrix != 1 && entering_the_matrix != 2);
    system("cls");
    if(entering_the_matrix==1){
   srand(time(NULL));
        for (int i=0;i<rows;i++){
            for (int j=0;j<rows;j++){
                A[i][j]= rand()%11;
            }
        }
        for (int i=0;i<rows;i++){
            for (int j=0;j<col;j++){
                B[i][j]= rand()%11;
            }
        }

    }
    else{
            printf("Matrix A:\n");
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<col;j++){
            printf("A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
            }
        }
    printf("Matrix B:\n");
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<col;j++){
            printf("B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
            }
        }
    }

    system("cls");
    print_array(A, B, rows, col);
//Вибираємо завдання для матриці
   do{
    do{
        printf("\n\nSelect a task:\n1.The maximum of the matrix A \n2.Transposed matrix B\n3.Product AxB\n4.Sorted matrix A\n5.The sum of matrices \n6. Exit\n");
        scanf("%d",&task_selection);
    }while(task_selection != 1 && task_selection != 2 && task_selection != 3 && task_selection != 4 && task_selection != 5 && task_selection != 6);
    system("cls");

    switch (task_selection){
    case 1:
        max_min(A,rows,col);
    break;

    case 2:
        trans_B(B,T,rows,col);
    break;

    case 3:
       dobutok_arrays(A,B,Dobutok,rows,col);
    break;

    case 4:
        sort_A(A,rows,col);
    break;

    case 5:
        sum_of_arrays(A,B,rows,col);
    break;

    case 6:
        {
   Exit = 1;
  }
}
}while(Exit == 0);

//Звільнюємо виділену під масиви пам'ять

    for (int i = 0; i < rows; i++)
    {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < rows; i++)
    {
        free(B[i]);
    }
    free(B);

 return 0;
}

//===================================================================================================
// описуємо виведення матриці
void print_array( int **A, int **B, int rows, int col){

printf("Matrix A:\n");

for (int i=0;i<rows;i++){
    for (int j=0;j<rows;j++)
    {
        printf("%3d ", A[i][j]);
    }
    printf("\n");
}

printf("\nMatrix B:\n");

for (int i=0;i<rows;i++){
    for (int j=0;j<col;j++){
        printf("%3d ", B[i][j]);
    }
    printf("\n");
}

}

//=========================================================================================================
// описуємо пошук мінімального та максимального значення над головною діагоналлю
void max_min ( int ** A, int rows, int col)
{
   int max_element;
   int min_element;
    max_element = A[1][2];
    min_element = A[1][2];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(j>i)
            {
                if(max_element<A[i][j])
                {
                max_element = A[i][j];
                }
                else if(min_element>A[i][j])
                {
                min_element = A[i][j];
                }
            }
        }
    }
         printf("\n max_element =   %d  ",max_element);
         printf("\n min_element =   %d  ",min_element);
}

//===========================================================================================================
//описуємо транспонування матриці В
void trans_B(int **B,int **T,int rows,int col){
    for (int i=0;i<rows;i++){
        for (int j=0;j<col;j++){
            T[j][i] = B[i][j];
        }
    }
printf("\nTransposition of B:\n");
    for (int i=0;i<col;i++){
        for (int j=0;j<rows;j++){
            printf("%3d ", T[i][j]);
        }
    printf("\n");
    }
}

//============================================================================================================
//описуємо добуток матриць
void dobutok_arrays(int **A,int **B,int **Prod,int rows,int col){
     for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                Prod[i][j]=0;
                for(int p=0;p<rows;p++){
                    Prod[i][j] += A[i][p] * B[p][j];
                }
            }
        }
        printf("AxB\n");
        for (int i=0;i<rows;i++){
            for (int j=0;j<col;j++)
            {
                printf("%3d ", Prod[i][j]);
            }
        printf("\n");
        }
}

//=============================================================================================================
//описуємо сортування матриці А методом бульбашки
void sort_A(int **A,int rows,int col){//again

int variant;
int temp;


    do{
        printf("\nSort:\n1.Matrix\n2.Line\n");
        scanf("%d", &variant);
    }while(variant!=1 && variant!=2);
    system("cls");
    if (variant == 1){
        for(int k = 0; k < rows; k++){
        for(int s = 0; s < col; s++){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < col; j++){
                    if(A[k][s] <A[i][j]){
                        temp = A[k][s];
                        A[k][s] = A[i][j];
                        A[i][j] = temp;
                    }
                }
            }
        }
    }
printf("\nSorted matrix A:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    }



if(variant == 2){
int sort = 0;

printf("\nEnter the line to sort: ");
scanf("%d",&sort);
    for(int pass=1;pass<rows;pass++)
    {
        for(int j=0;j<rows-pass;j++){
            if(A[sort][j]>A[sort][j+1]){
                temp = A[sort][j];
                A[sort][j] = A[sort][j+1];
                A[sort][j+1] = temp;
            }
        }
    }

    for(int j=0;j<rows;j++){
        printf("%3d ",A[sort][j]);
    }
}
}

//===============================================================================================================
//описуємо пошук суми матриць
void sum_of_arrays(int **A,int **B,int rows,int col){

int sum;

    for(int i=0;i<rows;i++){
    sum=0;
        for(int j=0;j<col;j++){
            sum = sum + A[i][j];
        }
    printf("\nRow sum:%d  A=%3d",i,sum);
    }

    for(int j=0;j<col;j++){
        sum=0;
            for(int i=0;i<rows;i++){
                sum = sum + B[i][j];
            }
    printf("\nSum column:%d  B=%3d",j,sum);
    }
}
