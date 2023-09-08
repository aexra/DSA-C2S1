#pragma once

// BUILT-IN INCLUDES
#include <string>

// CUSTOM FILES INCLUDES
#include "STDOutputManager.h"
#include "Lab.h"
#include "Lab1.h"

class LabManager
{
private:
	/*												*/
	/*		PRIVATE VARIABLES		*/
	/*												*/			

	// SINGLETON
	static LabManager* p_instance;

	// TITLE TEXT
	static string title;

	/*												*/
	/*		PRIVATE METHODS		*/
	/*												*/

	// CONSTRUCTOR
	[[noreturn]]  LabManager();

	// UNIVERSAL 2-TASK LAB OUTPUTTER
	[[noreturn]] void _OutLab_(Lab* lab);
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
	[[noreturn]] void ExecuteLab1();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab2();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab3();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab4();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab5();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab6();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab7();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab8();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab9();
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab10();
};