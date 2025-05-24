#include <string.h>

#include "MemoryMgr.h"
#include "Heap.h"
#include "HeapFactory.h"
#include <assert.h>





void* operator new (size_t size)
{
    return operator new (size,HeapFactory::GetDefaultHeap());
}

void* operator new (size_t size,const char* file,int line)
{
    Heap* pHeap = HeapFactory::GetDefaultHeap();
    assert(pHeap != NULL);
    return pHeap->Allocate(size,file,line);
}

void* operator new (size_t size,Heap* pHeap)
{
    assert(pHeap != NULL);
    return pHeap->Allocate(size);
}


void operator delete (void* pMem)
{
    if(pMem != NULL)
        Heap::Deallocate(pMem);
}
