#pragma once

#include <iostream>
#include <string>
#include "UltraCoolNamespace.h"
#include "List.h"

class ConsoleDialogManager
{
private:
	ConsoleDialogManager* p_instance = nullptr;
	std::string exitcode = "CDMSTOP";
	ConsoleDialogManager() {};
public:
	ConsoleDialogManager* getInstance() {
		return p_instance ? p_instance : p_instance = new ConsoleDialogManager();
	}

	class Page
	{
	private:
		typedef void (*OptionProc)();
		std::string title;
		struct Option
		{
			std::string title;
			OptionProc& proc;
		};
		List<Option> optList;
	public:
		Page(std::string title) : title(title) {}
		void init();
		void addOption(std::string title, Page* page);
		void addOption(std::string title, OptionProc& optProc);
	};

	void init(Page* main);
	Page* createPage(std::string title);
};

typedef ConsoleDialogManager::Page CDMPage;