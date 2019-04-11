#pragma once
#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElm
{
	Priority pr;
	HData data;
}HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap *ph);

#endif // !__SIMPLE_HEAP_H__
