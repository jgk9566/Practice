#pragma once
#include <vector>

typedef struct _tagRectangle
{
	unsigned int L;
	unsigned int R;
	unsigned int B;
	unsigned int T;
}Rectangle, *PRectangle;


class CSmilegateAlgorithm
{
public:
	CSmilegateAlgorithm();
	~CSmilegateAlgorithm();

public:
	bool Brackets();
	void CellExpansion();
	void Triangle();
	void UIEvent();

private:
	char* StrTok(char * string, const char * change, char **context);

	


};

