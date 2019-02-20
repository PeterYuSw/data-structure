#include"SqList.h"
#define LIST_INIT_SIZE 100
int InitaList(SqList &L)
{
	L.base = new int();
	if (!L.base)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = 100;
	return OK;
}