#pragma once



class LabManager
{
private:
	static LabManager* p_instance;
	
	LabManager();
public:

	static LabManager* GetInstance();
};