#include "..\..\Core\stdafx.h"
#include "Window.h"
#include "..\..\Core\CoreMath.h"

class HanningWindow : public Window
{
public:
	void ApplyFilter(UniqueDataSet& data) override;
};