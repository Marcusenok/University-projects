#include "Manager.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "creating" << endl;
	Manager* mgr = Manager::GetInstance();
	if (!mgr)
		cout << "ERROR" << endl;
	Manager::Destroy();

	return 0;
}