#include "ConsoleDialogManager.h"
using namespace SpecialFunctionsForLabs;

void ConsoleDialogManager::init(Page* main)
{
	std::cout << "��� ������������ ������ ������� �� ����.\n";
	while (true) {
		char key = input<char>("����������? [y/n]: ");
		if (key == 'n' || key == 'N') {
			break;
		} else {
			main->init();
		}
	}
	std::cout << "�������, ��� ��������� ���! - ������ ������� �� ����.";
}

CDMPage* ConsoleDialogManager::createPage(std::string title)
{
	return new CDMPage(title);
}

void ConsoleDialogManager::Page::init()
{

}

void ConsoleDialogManager::Page::addOption(std::string title, Page* page)
{

}

void ConsoleDialogManager::Page::addOption(std::string title, OptionProc& optProc)
{

}
