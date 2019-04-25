#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define list_entry(ptr, type, member) \
 ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))
//list_entry�� �̿��Ͽ� ���� ����ü�� �����(a,b,c,d,x,y,z)�� �̿��� 
//����ü�� ù �ּҸ� ����ϴ� main�Լ��� �ϼ��Ͻÿ�

//
//*list_entry - get the struct for this entry
//* @ptr: the &struct list_head pointer.
//* @type: the type of the struct this is embedded in.
//* @member: the name of the list_struct within the struct.
//-------------------------------------------------------------------------- - */
struct engine
{
	char a[5];
	double b;
	int c[3];
};

struct car
{
	 char x[10];
	int y;
	struct engine z;
};
void main()
{
	struct car bm ;
	
	printf("&bm : [ %x ]\n", &bm) ;
	printf("&bm : [ %x ]\n", list_entry(&bm.x, struct car, x)); 
	printf("&bm : [ %x ]\n", list_entry(&bm.z.b, struct car, z.b));


}
