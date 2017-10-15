#ifndef __TEST__DEFINE__H__
#define __TEST__DEFINE__H__
#include <ctime>

#ifndef DWORD
#define DWORD unsigned long int
#endif

#ifndef WORD
#define WORD unsigned short int
#endif

#define ULL unsigned long long 

#define LOG_PROCESS_ERROR(condition)															\
if(!condition)																					\
{																								\
	printf("FILE : %s , LINE : %d , Function : %s\n", __FILE__, __LINE__, __FUNCTION__);		\
	goto Exit0;																					\
}																								

#define EV_PROCESS_ERROR(condition)																\
if(!condition)																					\
{																								\
	goto Exit0;																					\
}																								

#define EV_PROCESS_SUCCESS(condition)															\
if(condition)																					\
{																								\
	goto Exit1;																					\
}																								

#endif
