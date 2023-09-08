#pragma once

// CUSTOM FILES INCLUDES
#include "STDOutputManager.h"
#include "Lab1.h"

class LabManager
{
private:
	/*												*/
	/*		PRIVATE VARIABLES		*/
	/*												*/			

	// SINGLETON
	static LabManager* p_instance;

	// STD IOSTREAM MANAGER
	STDOutputManager* om = nullptr;

	/*												*/
	/*		PRIVATE METHODS		*/
	/*												*/

	// CONSTRUCTOR
	[[noreturn]]  LabManager();

	// UNIVERSAL 2-TASK LAB OUTPUTTER
	[[noreturn]] void _OutLab_();
public:
	/*												*/
	/*		PUBLIC VARIABLES		*/
	/*												*/

	/*												*/
	/*		PUBLIC METHODS			*/
	/*												*/

	// SINGLETON CONSTRUCTOR
	static LabManager* GetInstance();

	// LAB METHODS
	[[noreturn]] void Lab1();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab2();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab3();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab4();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab5();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab6();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab7();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab8();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab9();
	[[deprecated("Has no implementation")]] [[noreturn]] void Lab10();
};