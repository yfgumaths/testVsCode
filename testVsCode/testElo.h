#ifndef __TEST__ELO__H__
#define __TEST__ELO__H__

#include "testDefine.h"
#include "testVector.h"

#define MAX_ELO_TEAM_COUNT 50
#define MAX_ELO_SCORE 100
#define MIN_ELO_SCORE 0
#define MAX_TEAM_ELO_SCORE_SUM MAX_ELO_TEAM_COUNT*MAX_ELO_SCORE


struct SEloMatchNode
{
	SEloMatchNode()
	{
		bValid = false;
		nNodeScore = 0;
		dwMatchStatus = 0;
	};

	void Reset()
	{
		bValid = false;
		nNodeScore = 0;
		dwMatchStatus = 0;
	}

	bool IsValid() { return bValid;}

	void SetValue(int nScore, DWORD dwStatus)
	{
		Reset();
		nNodeScore = nScore;
		dwMatchStatus = dwStatus;
		bValid = true;
	}

	void Output()
	{
		TOutput_E("EloNode IsValid? ", IsValid()?"true":"false");
		TOutput_E("EloNode nNodeScore =", nNodeScore);
		TOutput("EloNode Status:");
		TOutputHex_E(dwMatchStatus);
	}

	int nNodeScore;
	bool bValid;
	DWORD dwMatchStatus;
};

struct SEloMatchProcess
{
	SEloMatchProcess()
	{
		Reset();
	}

	void Reset()
	{
		for (int i = 0; i < MAX_ELO_TEAM_COUNT; ++i)
			for (int j = 0; j < MAX_TEAM_ELO_SCORE_SUM; ++j)
				data[i][j].Reset();
	}

	SEloMatchNode data[MAX_ELO_TEAM_COUNT][MAX_TEAM_ELO_SCORE_SUM];
};

class CEloMatch
{
public:
	int Init();
	int InitVector(int nCount, WORD min = MIN_ELO_SCORE, WORD max = MAX_ELO_SCORE);
	int AllocTeam();
	friend ostream& operator<<(ostream& os, const CEloMatch* cEloMatch);
private:
	int GetRandomVector(int nCount, WORD min = MIN_ELO_SCORE, WORD max = MAX_ELO_SCORE);
	int GetTotalEloScore();
	std::vector<WORD> vecData;
};



#endif // #ifndef __TEST_ELO__H__
