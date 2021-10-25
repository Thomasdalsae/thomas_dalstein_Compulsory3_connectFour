#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

struct tiles
{
	char tileSymbol{ '*' };
	int color{};
};
void dropAnimation(int, std::vector<std::vector<tiles>>&);
void boardLayout(std::vector<std::vector<tiles>>);
bool dropSlot(int, std::vector<std::vector<tiles>>);



int witdh = 7;
int height = 8;

int main(){

	std::vector<std::vector<tiles>> board(witdh, std::vector<tiles>(height, tiles{ '*' }));


	dropSlot(board[0].size(),board);
	//boardLayout(board);
	
	
	
	
	return 0;
}

void boardLayout(std::vector<std::vector<tiles>> board) {

	

	
	for (int i = board.size() - 1; i >= 0; i--)
	
	{
		
		for (int j = 0; j < board[0].size(); j++)
		{
		
			std::cout << "[" << board[i][j].tileSymbol << "]";


		}

		std::cout << std::endl;
	}


}

bool dropSlot(int boardSize, std::vector<std::vector<tiles>> Aboard) {

	int slot{};

	while (true)
	{

	for (size_t i = 0; i < boardSize; i++)
	{
		
		if (slot == i)
		{
			std::cout << "(" << "|" << ")";
		}
		else
		{
			std::cout << "( )";
		}

	}
	std::cout << std::endl;
	boardLayout(Aboard);


	char b = _getch();

	switch (b)
	{
		//Player goes left
	case 'a': case 'A':

		slot += -1;

		if (slot <= 0)
		{
			slot = boardSize -1;
		}

		break;
		//Player goes right
	case 'd': case 'D':
		slot += 1;

		if (slot == boardSize)
		{
			slot = 0;

		}
		break;

	case ' ':
		dropAnimation(slot, Aboard);
		return false;

		break;

	default:
		break;
	}

	system("cls");
	}
	
}

void dropAnimation(int slotdrop, std::vector<std::vector<tiles>>& animboard) {

	system("cls");

	//animboard[0][0].tileSymbol = 'G';

	while (true)
	{
		animboard[0][slotdrop].tileSymbol = 'x';
		boardLayout(animboard);

		break;
	}




	

}
