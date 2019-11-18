#pragma once
#include "Macro.h"

typedef struct _tagUIButton
{
	unsigned int L, R, B, T;
	unsigned int iButtonNumber;
	unsigned int iClickedCount;

	_tagUIButton() :
		L(0),
		R(0),
		B(0),
		T(0),
		iButtonNumber(0),
		iClickedCount(0)
	{
	}
}UIButton, *PUIButton;

typedef struct _tagClickPos
{
	unsigned int X, Y;

	_tagClickPos() :
		X(0),
		Y(0)
	{
	}
}ClickPos, *PClickPos;

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
};

