<pre>
元ネタ　https://www.amazon.co.jp/exec/obidos/ASIN/4797366761/
　　　　についてくるサンプルのMemoryMgrがこのままだと、どこでメモリーリークしたか分からない(素だとaddressしか出ない)ので、
    　　分かるように改造したもの


----------------------------------------------------
#include "MemoryMgr.h"
#include "HeapFactory.h"
int main()
{
	int bookmark = HeapFactory::GetMemoryBookmark();
   :
   :
   :
   :
 	HeapFactory::ReportMemoryLeaks(bookmark);
  return 0;
}
----------------------------------------
メモリーリークをチェックしたいファイルの場合
#define ENABLE_MEMORY_DEBUGGING <--これをつける
#include "MemoryMgr.h" 
</pre>
