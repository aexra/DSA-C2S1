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
	std::cout << title << std::endl;
	for (size_t i = 0; i < optList.count(); i++) {
		std::cout << i + 1 << ". " << optList[i]->title << std::endl;
	}
	size_t key;
	while (true) {
		key = input<unsigned int>("�������� �����: ");
		if (!(1 <= key && key <= optList.count())) continue;
		else break;
	}
	optList[key]->proc();
}

void ConsoleDialogManager::Page::addOption(std::string title, OptionProc& optProc)
{
	optList.push(new Option(title, optProc));
}
