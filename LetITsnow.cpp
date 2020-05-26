#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
void Physics(int *array, int *position)
{
  int ch;
 
			ch = _getch();
			if (ch == 224)
			{
				switch (_getch())
				{
				case 80:
					if (position[0] != 0)
					{
						array[position[1]*25+position[0]] = 0;
						position[0] -= 1;
						array[position[1]*25+position[0]] = 1;
					}
					break;
				case 72:
					if (position[0] != 25)
					{
						array[position[1]*25+position[0]] = 0;
						position[0] += 1;
						array[position[1]*25+position[0]] = 1;
					}
					break;

				}

			}
			if (ch == ' ')
			{
				array[(position[1] + 1)*25 + position[0]] = -1;
			}
}




int main()
{
int matrix[25][25] = { 0 };
int position[2] = { 0,0 };
int ch;
matrix[0][0] = 1;
	do
	{
		system("cls");

		for (int i = 0; i < 25; ++i)
		{
			for (int g = 0; g < 25; ++g)
			{
				if (matrix[i][g] == -1 && matrix[i + 1][g] == 2)
				{
					if (matrix[i + 1][g + 1] == 0)
					{
						matrix[i + 1][g + 1] = -1;
						matrix[i][g] = 0;
					}
					if (matrix[i + 1][g + 1] == 2)
					{
						matrix[i][g + 1] = -1;
						matrix[i][g] = 0;
					}
					if (matrix[i + 1][g + 1] == 3)
					{
						matrix[i][g + 1] = -1;
						matrix[i][g] = 0;
					}
					if (matrix[i + 1][g + 1] == -1)
					{
						matrix[i][g + 1] = -1;
						matrix[i][g] = 0;
					}
					
				}
				if (matrix[i][g] == -1)
				{
					matrix[i + 1][g] = -1;
					matrix[i][g] = 0;
				}

			}
		}
		for (int i=0; i < 25; ++i)
		{
			for (int g=0; g<25; ++g)
			{
				if (matrix[i][g] == 1)
				{
					std::cout << '^';
				}
				if (matrix[i][g] == 0)
				{
					std::cout << ' ';
				}
				if (matrix[i][g] == 2)
				{
					std::cout << '\\' ;
				}
				if (matrix[i][g] == -1)
				{
					std::cout << '*';
				}
				if (matrix[i][g] == 3)
				{
					std::cout << '_';
				}

			}
			std::cout << '\n';
		}
	
	std::thread secondthread(Physics,std::ref(matrix), std::ref(position));
	secondthread.detach();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	}
	while (ch != 27);
}