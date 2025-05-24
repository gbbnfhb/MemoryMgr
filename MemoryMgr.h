
#ifndef MEMORYMGR_H_
#define MEMORYMGR_H_

#include<stdio.h>
#include<stdlib.h>
#include "HeapFactory.h"
//#include <cstddef>
#define NULL 0


void * operator new (size_t size);
//void * operator new [](size_t size);
void * operator new (size_t size, Heap * pHeap);
void* operator new(size_t size,const char* file,int line);
//void * operator new (size_t size, void * pHeap);
//void * operator new [](size_t size, Heap * pHeap);
void operator delete (void * pMem, size_t size); 
//void operator delete [](void * pMem, size_t size); 
void operator delete (void * pMem); 
//void operator delete [] (void * pMem); 


/*
#define DECLARE_HEAP \
    public: \
        static void * operator new(size_t size); \
        static void operator delete(void * p, size_t size); \
    private: \
        static Heap * s_pHeap; 


#define DEFINE_HEAP(className,heapName) \
    Heap * className::s_pHeap = NULL; \
    void * className::operator new(size_t size) { \
        if (s_pHeap==NULL)  \
            s_pHeap = HeapFactory::CreateHeap(heapName); \
        return ::operator new(size, s_pHeap);  \
    } \
    void className::operator delete(void * p, size_t size) { \
        ::operator delete(p); \
    }


#define DEFINE_HIERARCHICALHEAP(className,heapName,parentName) \
    Heap * className::s_pHeap = NULL; \
    void * className::operator new(size_t size) { \
        if (s_pHeap==NULL)  \
            s_pHeap = HeapFactory::CreateHeap(heapName,parentName); \
        return ::operator new(size, s_pHeap);  \
    } \
    void className::operator delete(void * p, size_t size) { \
        ::operator delete(p); \
    }
*/

// --- new 演算子を置き換えるマクロ (デバッグ時のみ有効など) ---
#ifdef ENABLE_MEMORY_DEBUGGING // 仮のプリプロセッサ定義
#define new new(__FILE__, __LINE__)
#endif


#endif