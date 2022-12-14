#include<iostream>
#include <typeinfo>
#include "Figures.h"

using namespace std;

int main()
{
	Figure* pFig[10] = { NULL };
	pFig[0] = new Circle(1, 1, 1, 1);
	pFig[1] = new Rectangle(2, 2, 2, 2, 2);
	pFig[2] = new Triangle(3, 3, 3, 3, 3, 3);
	int index_now = 0;

	int choice = -1;
	do
	{
		cout << "Index now: " << index_now << "\nFigure now: ", pFig[index_now]->Show();
		cout << "0 - Exit; 1 - Choose figure; 2 - Actions with a figure; 3 - Add figure; 4 - Print all figure\n";
		do { cin >> choice; } while (choice < 0 or choice > 4);
		switch (choice)
		{
		case 1:
			cout << "Input index: ";
			int index_figure;
			do { cin >> index_figure; } while (index_figure < 0 or index_figure > 9);
			if (pFig[index_figure] == NULL) cout << "No figure\n";
			else index_now = index_figure;
			break;
		case 2:
			cout << "1 - Delete; 2 - Change color; 3 - Moving; 4 - Change size\n";
			int actions_figure;
			do { cin >> actions_figure; } while (actions_figure < 1 or actions_figure > 4);
			switch (actions_figure)
			{
			case 1:
				delete pFig[index_now];
				pFig[index_now] = NULL;
				break;
			case 2:
				int new_color;
				cout << "Color now:", pFig[index_now]->GetColor();
				cout << "Color now:"; 
				cin >> new_color;
				pFig[index_now]->SetColor(new_color);
				break;
			case 3:
				int new_x, new_y;
				cout << "New X:";
				cin >> new_x;
				cout << "New Y:";
				cin >> new_y;
				pFig[index_now]->MoveTo(new_x, new_y);
				break;
			case 4:
				double new_size;
				cin >> new_size;
				pFig[index_now] -> SetSize(new_size);
				break;
			}
			break;
		case 3:
			cout << "Input index: ";
			int index_add_figure;
			do { cin >> index_add_figure; } while (index_add_figure < 0 or index_add_figure > 9);
			if (pFig[index_add_figure] == NULL)
			{
				cout << "Choose figure: 1 - Circle; 2 - Rectangle; 3 - Triangle\n";
				int choice_figure;
				do { cin >> choice_figure; } while (choice_figure < 1 or choice_figure > 3);
				switch (choice_figure)
				{
				case 1:
					pFig[index_add_figure] = new Circle;
					break;
				case 2:
					pFig[index_add_figure] = new Rectangle;
					break;
				case 3:
					pFig[index_add_figure] = new Triangle;
					break;
				}
			}
			else cout << "No place\n";
			break;
		case 4:
			for (int i = 0; pFig[i] != NULL; i++)
			{
				cout << "Index: " << i << "\nFigure: ", pFig[i]->Show();
			}
			cout << "\n";
		}
	} while (choice != 0);

	for (int i = 0; pFig[i] != NULL; i++) delete pFig[i];

	return 0;
}