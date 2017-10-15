#ifndef __TEST__PERF__FAST__H__
#define __TEST__PERF__FAST__H__

#include "testDefine.h"
#include <string>
#include <map>
#include <ctime>
#include "testTemplate.h"
using namespace std;

struct SPerfNode
{
	SPerfNode(string strName = NULL)
	{
		m_strName = strName;
		m_dwBeginTimeMS = clock();
		m_dwEndTimeMS = 0;
	}
	void Reset()
	{
		m_dwBeginTimeMS = clock();
		m_dwEndTimeMS = 0;
	}

	void EndPerfTick()
	{
		m_dwEndTimeMS = clock();
		TOutput_E("PERFFAST ", m_strName, "TickTimeMS", m_dwEndTimeMS - m_dwBeginTimeMS);
	}

	string m_strName;
	DWORD m_dwBeginTimeMS;
	DWORD m_dwEndTimeMS;
};

#define PERFFAST_BEGIN(strName)								\
do															\
{															\
	auto it = mapPerfNode.find(strName);					\
	if(it == mapPerfNode.end())								\
	{														\
		SPerfNode newNode(strName);							\
		mapPerfNode.insert(make_pair(strName, newNode));	\
	}														\
	else													\
	{														\
		SPerfNode& nowNode = it->second;					\
		nowNode.Reset();									\
	}														\
}while(false);

#define PERFFAST_END(strName)												\
do																			\
{																			\
	auto it = mapPerfNode.find(strName);									\
	if(it == mapPerfNode.end())												\
	{																		\
		TOutput_E("PERFFAST_END_ERROR ",__FILE__,__LINE__,__FUNCTION__);	\
	}																		\
	else																	\
	{																		\
		SPerfNode& nowNode = it->second;									\
		nowNode.EndPerfTick();												\
	}																		\
}while(false);

static map<string,SPerfNode> mapPerfNode;
SPerfNode FindPerfNode(string& strName);

#endif //!__TEST__PERF__FAST__H__
