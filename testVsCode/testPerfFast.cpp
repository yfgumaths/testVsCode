#include "testPerfFast.h"

SPerfNode FindPerfNode(string& strName)
{
	SPerfNode retNode;
	auto it = mapPerfNode.find(strName);
	if (it != mapPerfNode.end())
		retNode = it->second;
	return retNode;
}