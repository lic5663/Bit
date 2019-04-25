#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  
#define loop(v, lo, hi) for((v)=(lo); (v)<(hi); (v)++)

int sum(int a, int b)  { return a+b; }
int sub(int a, int b)  { return a-b; }
int multi(int a, int b){ return a*b; }
int divv(int a, int b) { return a/b; }
int mod(int a, int b)  { return a%b; }

// calculator3�� typedef_calculator3�� ������ ������ �ϵ��� FP, FPP�� typedef�� �̿��Ͽ� �ۼ��ϼ���.
typedef int(F)(int, int);
typedef F *FP;
typedef FP *FPP;	// int (**FPP)(int,int);
//typedef FP(calculator3)(FPP,int);


// calculator3��  �Լ� ������ �迭�� �Ű������� �ް� �Լ� �����͸� ��ȯ�ϴ� �Լ� 
// typedef_calculator3�� ������ ������ �ǵ��� calculator3�� ��� �κ��� �ۼ��մϴ�.
// typedef ������

//FP calculator3 (FPP fp, int arr_size)

int (*calculator3(int(**fp)(int,int) , int arr_size) )(int,int)
{
      int low = 0;
      int high = arr_size-1; 
      int random_Num = rand()%(high-low) + low; //���� �߻������� low���� high �������� ��µǴ� �ڵ�
      return fp[random_Num];
}

FP typedef_calculator3(FPP fp, int arr_size) {      
   return calculator3(fp, arr_size);
}

// calculator2�� �Լ� ������ �迭�� �Ű����� �޴� �Լ�
//    calculator2 �Լ��� arr_size �������� �����߻�
//    ��Ģ������ ���� �ǿ����ڴ� 11,7�� ����
//    ������ ���� �Լ� ���� �� ���
//    ����� �Լ� �����͸� ��ȯ�� 


int calculator2 (int(**fp)(int, int) , char* optor, int arr_size)
{
    int random_Num;
	int fir=11,sec=7;
    int low = 0;
    int high = arr_size-1; 
    
    printf("���� �߻� ���� %d ~ %d\n", low, high);
     
    random_Num = rand() % high + low; //���� �߻������� low���� high �������� ��µǴ� �ڵ�
    printf("���� : %d\n", random_Num);
    printf("�Լ� ���� : %d %c %d = %d\n", fir, optor[random_Num], sec, fp[random_Num](fir, sec) );
    return random_Num; 
}   

int typedef_calculator2 (FPP fp, char* optor, int arr_size) {
    return calculator2(fp, optor, arr_size);
} 
  
//calculator�� �Լ� ������ �迭�� �μ��� �޴� �Լ� 
//fir��sec������ ��� ��Ģ������ ���� ����Ͻÿ�
int calculator(int(**fpa)(int,int) , int arr_size){
    int dx;
    int fir=11,sec=7;

	for (dx = 0; dx < arr_size; dx++)
	{
		printf("%d \n", fpa[dx](fir, sec));
	}
    puts("");
}

int typedef_calculator(FPP fp, int arr_size) {
    return calculator(fp, arr_size);
}

int main(void){
    int (*fpa[])(int,int) = {sum, sub, multi, divv, mod};  // 1. fpa�� �Լ� ������ �迭 
    char optor[] = {'+', '-', '*', '/', '%'}; 
    int dx;

	srand(time(NULL));

    // typedef �� ������� ���� �Լ� ȣ�� 
    calculator(fpa, sizeof(fpa)/sizeof(fpa[0]));
    
    calculator2(fpa, optor, sizeof(fpa)/sizeof(fpa[0]));

    loop(dx,0,5)
    {
        Sleep(300);    
        printf("random RUN!! : %d\n", calculator3(fpa, sizeof(fpa)/sizeof(fpa[0]))(10,3) );
    }

    // typedef �� ����� �Լ� ȣ��     
    typedef_calculator(fpa, sizeof(fpa)/sizeof(fpa[0]));
   
    typedef_calculator2(fpa, optor, sizeof(fpa)/sizeof(fpa[0]));
     loop(dx,0,5) 
    {
        Sleep(300);     
        printf("random RUN!! : %d\n", typedef_calculator3(fpa, sizeof(fpa)/sizeof(fpa[0]))(10,3) );
    }
}