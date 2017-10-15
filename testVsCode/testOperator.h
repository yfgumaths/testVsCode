#ifndef __TEST__OPERATOR__H__
#define __TEST__OPERATOR__H__
extern SEloMatchNode;

inline SEloMatchNode operator + (SEloMatchNode& a, SEloMatchNode& b)
{
	static SEloMatchNode retNode;
	retNode.Reset();
	retNode.SetValue(a.nNodeScore + b.nNodeScore, a.dwMatchStatus | b.dwMatchStatus);
	return retNode;
}

#endif //!__TEST__OPERATOR__H__