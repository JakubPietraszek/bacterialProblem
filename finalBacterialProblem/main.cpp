#include "GameHandler.h"

int main() {
	srand(time(NULL));
	std::cout << "Specify the length of the Petri Dish: \n -->";
	int size;
	std::cin >> size;
	std::cout << "Specify the number of bacteria: \n -->";
	int numberOfBacteria;
	std::cin >> numberOfBacteria;
	if (size < 2 || numberOfBacteria * 3 > size * size)
	{
		std::cerr << "Improper input date, program is running with defautl values\nPress anything to continue";
		size = 50;
		numberOfBacteria = 200;
		_getch();
	}
	GameHandler gameHandler(size, numberOfBacteria);
	gameHandler.lifeCourse();


	return 0;
}