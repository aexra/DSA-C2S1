#pragma once

#include <iostream>
#include <string>

class STDOutputManager
{
private:
	static STDOutputManager* p_instance;

	STDOutputManager();
public:

	static STDOutputManager* GetInstance();
};

