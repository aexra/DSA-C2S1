#pragma once

// BUILT-IN INCLUSIONS
#include <string>

// CUSTOM FILES INCLUSIONS
#include "STDOutputManager.h"
#include "Lab.h"

// LABS INCLUSIONS
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"

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
	LabManager();

	// UNIVERSAL 2-TASK LAB OUTPUTTER
	[[noreturn]] void _OutLab_(Lab* lab, unsigned short int num = 0, unsigned short int t = 0);
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
	[[noreturn]] void ExecuteLab(unsigned short int num, unsigned short int t = 0);
	[[deprecated("Has no implementation")]] [[noreturn]] void ExecuteLab1();
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