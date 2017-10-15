#include "testHead.h"

#include <ctime>

int CEloMatch::Init()
{
	int nResult = false;
	int nRetCode = false;

	vecData.clear();
	LOG_PROCESS_ERROR(vecData.size() == 0);

//Exit1:
	nResult = true;
Exit0:
	return nResult;
}

int CEloMatch::AllocTeam()
{
	int nResult = false;
	int nRetCode = false;

	SEloMatchProcess nowProcess;
	SEloMatchProcess preProcess;
	
	int nUserCount = vecData.size();
	int nTeamUserCount = nUserCount / 2;
	int nAllocScoreUpperLimit = GetTotalEloScore() / 2;
	bool bFindAns = false;
	SEloMatchNode nowSingleNode;

	LOG_PROCESS_ERROR(nUserCount > MAX_ELO_TEAM_COUNT * 2);

	for (int i = 0; i < nUserCount; ++i)
	{
		preProcess = nowProcess;
		int nowData = vecData[i];
		int nowAddStatus = 1 << i;
		if (nowData > nAllocScoreUpperLimit)
			continue;
		
		nowSingleNode.SetValue(nowData, nowAddStatus);
		nowProcess.data[1][nowData] = nowSingleNode;
		for (int j = 1; j <= nTeamUserCount; ++j)
		{
			for (int k = 0; k <= nAllocScoreUpperLimit - nowData; ++k)
			{
				if (preProcess.data[j][k].IsValid() && !nowProcess.data[j + 1][k + nowData].IsValid())
				{
					nowProcess.data[j + 1][k + nowData] = nowSingleNode + preProcess.data[j][k];
				}
			}
		}
	}
	
	for (int i = nAllocScoreUpperLimit; i >= 0; i--)
	{
		SEloMatchNode& checkData = nowProcess.data[nTeamUserCount][i];
		if (checkData.IsValid())
		{
			//checkData.Output();
			TOutput_E("EloMatch OtherTeamScore =", GetTotalEloScore() - checkData.nNodeScore);
			bFindAns = true;
			break;
		}
	}

	if (!bFindAns)
	{
		TOutput("EloMatchFindAns Fail! Vector = \n");
		TOutputVector(vecData);
		EV_PROCESS_SUCCESS(true);
	}

Exit1:
	nResult = true;
Exit0:
	return nResult;
}

int CEloMatch::GetRandomVector(int nCount, WORD min, WORD max)
{
	int nResult = false;
	int nRetCode = false;

	vecData.clear();
	srand(time(0));
	for (int i = 0; i < nCount; ++i)
	{
		WORD wData = (WORD)(min + (max - min)*rand() / (RAND_MAX*1.0));
		vecData.push_back(wData);
	}
	LOG_PROCESS_ERROR(vecData.size() == nCount);

	TOutput_E("GetRandomVector = ");
	TOutputVector_E(vecData);
	TOutput_E("Total Score = ", GetTotalEloScore());

//Exit1:
	nResult = true;
Exit0:
	return nResult;
}

int CEloMatch::GetTotalEloScore()
{
	int nReturn = 0;
	for (auto it = vecData.begin(); it != vecData.end(); ++it)
		nReturn += *it;
	return nReturn;
}

int CEloMatch::InitVector(int nCount, WORD min, WORD max)
{
	int nResult = false;
	int nRetCode = false;

	nRetCode = GetRandomVector(nCount, min, max);
	LOG_PROCESS_ERROR(nRetCode);

//Exit1:
	nResult = true;
Exit0:
	return nResult;
}