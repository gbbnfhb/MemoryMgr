
#ifndef HEAP_H_
#define HEAP_H_

//typedef unsigned long size_t;

struct AllocHeader;

extern char gMark[128];
#define _Mark(s) strcpy(gMark,s);
#define _unMark(s) strcpy(gMark,"");

class Heap
{
public:
    void Initialize();

    void * Allocate(size_t bytes);
    void * Allocate(size_t bytes,const char* file,int line);
    static void Deallocate (void * pMem);

    void Activate (const char * name);
    void Deactivate ();

    void AttachTo (Heap * pParent);

    bool IsActive () const { return m_bActive; }
    const char * GetName() const;

    void PrintTreeInfo (int indentLevel = 0) const;
    void PrintInfo (int indentLevel = 0) const;

    int ReportMemoryLeaks (int nBookmark1, int nBookmark2);

    static int GetMemoryBookmark ();

private:
    void Deallocate(AllocHeader * pHeader);
    void GetTreeStats (size_t & totalBytes, size_t & totalPeak, int & totalInstances) const;

    enum { NAMELENGTH = 128 };

    bool   m_bActive;
    char   m_name[NAMELENGTH];
    size_t m_bytesAllocated;
    size_t m_bytesPeak;
    int    m_nInstances;

    char   m_file_name[NAMELENGTH];
    int    m_line;

    AllocHeader * m_pHeadAlloc;

    Heap * m_pParent;
    Heap * m_pFirstChild;
    Heap * m_pNextSibling;
    Heap * m_pPrevSibling;

    static int s_nNextAllocNum;
};


#endif