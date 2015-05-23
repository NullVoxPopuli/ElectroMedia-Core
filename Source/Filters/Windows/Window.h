#include "..\..\Core\stdafx.h"
#include "..\Base\Filter.h"

class Window : public Filter
{
	virtual void ApplyFilter(UniqueDataSet& data);
};