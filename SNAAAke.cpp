// SNAAAke.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>



using namespace std;


int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
int main()
{   
	char map[30][30];//иницилизация карты
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (i == 0 || i == 30 || j == 0 || j == 30) {
				map[i][j] = '#';
			}
			else { map[i][j] = ' '; }
		}
	}
	//инициализация змаейки
	int snake[2][300],snakesize;//первая строка это i, вторая - j
	snakesize = 3;
	int last = 3;// 1-right,2-left,3-up,4-down
	int x = 15;
	for (int j = 0; j < 3; j++) {
		
		snake[0][j] = x;
		snake[1][j] = 15;
		x++;
	}

   //ввод змейки на карту
	for (int k = 0; k < snakesize; k++) {
		int i, j;
		i = snake[0][k];
		j = snake[1][k];
		map[i][j] = 'O';
	}
	//вывод карты
	int mouse[2];
	mouse[0] = getRandomNumber(1,29);
	mouse[1] = getRandomNumber(1, 29);
   for (int i = 0; i <= 30; i++) {
	   for (int j = 0; j <=30; j++) {
		   cout << map[i][j] << ' ';
	   }
	   cout << endl;
   }
   map[mouse[0]][mouse[1]] = 'o';
   //Цикл игры
   char vvod;
   vvod = ' ';
   bool left = false, right = false, up = true, down = false,end = false,hit = false;
 
   while (!hit) {
	   if (_kbhit()) {
		   vvod = _getch();
		   
		   switch(vvod) {
		      case 'a':
				  left = true;
				  up = false;
				  down = false;
				  break;
			  case 'd':
				  right = true;
				  up = false;
				  down = false;
				  break;
			  case 'w':
				  left = false;
				  right = false;
				  up = true;
				  break;
			  case 's':
				  left = false;
				  right = false;
				  down = true;
				  break;

		   }
	   }
	   
	   //перезапись змейки
	   for (int j = snakesize; j > 0; j--) {
		   snake[0][j] = snake[0][j - 1];
		   snake[1][j] = snake[1][j - 1];

	   }
	   //перемещение
	   if ((right) & (left == false)) {
		   snake[1][0] = snake[1][0] + 1;
		   last = 1;
	   }
	   else if ((left) & (right == false)) {
		   snake[1][0] = snake[1][0] - 1;
		   last = 2;
	   }
	   else if ((up) & (down == false)) {
		   snake[0][0] = snake[0][0] - 1;
		   last = 3;
	   }
	   else if ((down) & (up == false)) {
		   snake[0][0] = snake[0][0] + 1;
		   last = 4;

	   }
	   else { switch (last) {
	       case 1:
			  snake[1][0] = snake[1][0] + 1;
		      down = false;
		      break;
	       case 2:
			   snake[1][0] = snake[1][0] - 1;
		       break;
	       case 3:
			   snake[0][0] = snake[0][0] - 1;
		       break;
	       case 4:
			   snake[0][0] = snake[0][0] + 1;
		       break;
	   } }

	   if (map[snake[0][0]][snake[1][0]] == '#'|| map[snake[0][0]][snake[1][0]] =='O' ) {
		   hit = true; }
	   else {
		   if (map[snake[0][0]][snake[1][0]] == 'o') {
			   snakesize = snakesize + 1;
			   snake[0][snakesize] =snake[0][snakesize-2]+(snake[0][snakesize - 2]- snake[0][snakesize - 1]) ;
			   snake[1][snakesize] =snake[1][snakesize - 2] + (snake[1][snakesize - 2] - snake[1][snakesize - 1]);
			   mouse[0] = getRandomNumber(1, 29);
			   mouse[1] = getRandomNumber(1, 29);

		   }
		   
		   //очищение карты
		  for (int i = 0; i <= 30; i++) {
			   for (int j = 0; j <= 30; j++) {
				   if (i == 0 || i == 30 || j == 0 || j == 30) {
					   map[i][j] = '#';
				   }
				   else { map[i][j] = ' '; }
			   }
		   }
		   map[mouse[0]][mouse[1]]='o';
		   //ввод змейки на карту
		   for (int k = 0; k < snakesize; k++) {
			   int i, j;
			   i = snake[0][k];
			   j = snake[1][k];
			   map[i][j] = 'O';
		   }
		   system("Cls");
		   //вывод карты
		   for (int i = 0; i <= 30; i++) {
			   for (int j = 0; j <= 30; j++) {
				   cout << map[i][j] << ' ';
			   }
			   cout << endl;
		   }
	   }
   }
   cout<< "GAME OVER";
   cin >> vvod;

   return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
