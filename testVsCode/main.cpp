#include "testHead.h"
#include <ctime>
int testNewEloMatch(int nUserCount)
{
	int nResult = false;
	int nRetCode = false;
	CEloMatch* pEloMatch = NULL;

	pEloMatch = new CEloMatch();
	LOG_PROCESS_ERROR(pEloMatch);
	
	nRetCode = pEloMatch->InitVector(nUserCount);
	LOG_PROCESS_ERROR(nRetCode);
	
	PERFFAST_BEGIN("ALLOCTEAM");
	pEloMatch->AllocTeam();
	PERFFAST_END("ALLOCTEAM");

//Exit1:
	nResult = true;
Exit0:
	if (pEloMatch)
		delete pEloMatch;
	TOutput_E("");
	return nResult;
}

void testEloMatch()
{
	int nUserCount20 = 20;
	int nUserCount10 = 10;
	int nUserCount14 = 14;
	testNewEloMatch(nUserCount20);
	testNewEloMatch(nUserCount20);
	testNewEloMatch(nUserCount20);
	testNewEloMatch(nUserCount20);
	testNewEloMatch(nUserCount20);


}

int main()
{
	PERFFAST_BEGIN("testEloMatch");
	testEloMatch();
	PERFFAST_END("testEloMatch");

	system("pause");
	return 0;
}