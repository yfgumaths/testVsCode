#ifndef __TEST__VECTOR__H__
#define __TEST__VECTOR__H__

#include <vector>


template<typename T1>
void TOutputVector(std::vector<T1>& vecOutput)
{
	if (vecOutput.empty())
	{
		printf("Output Vector Empty! File : %s , Line : %d , Function : %s", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	std::cout << "vector : ";
	for (auto it = vecOutput.begin(); it != vecOutput.end(); ++it)
		std::cout << *it << " ";
};

template<typename T1>
void TOutputVector_E(std::vector<T1>& vecOutput)
{
	TOutputVector(vecOutput);
	std::cout << endl;
};
#endif
