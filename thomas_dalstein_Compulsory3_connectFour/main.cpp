#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>


struct tiles
{

	char tileSymbol{ '*' };
	int color{};
};
bool animDrop(int, std::vector<std::vector<tiles>>&);
void boardLayout(std::vector<std::vector<tiles>>);
bool dropSlot(int, std::vector<std::vector<tiles>>);
bool winChecker(std::vector<std::vector<tiles>>& animboardChecker);

int x{};
int y{};
int witdh = 7;
int height = 6;
int turn{};
char playerSymbol = 'x';
int inaRow{};
int main(){
	
	
	std::vector<std::vector<tiles>> board(witdh, std::vector<tiles>(height, tiles{ '*' }));

	
	
		dropSlot(board[0].size(), board);
	
	
	
	
	
	
	return 0;
}


bool dropSlot(int boardSize, std::vector<std::vector<tiles>>aboard) {

	
	
		while (true)
		{
			
				boardLayout(aboard);


 			char b = _getch();

				switch (b)
				{
					//Player goes left
				case 'a': case 'A':

					x += -1;

					if (x < 0)
					{
						x = boardSize - 1;
					}

					break;
					//Player goes right
				case 'd': case 'D':
					x += 1;

					if (x == boardSize)
					{
						x = 0;

					}
					break;

				case ' ':
					
					animDrop(x, aboard);
					turn++;

					break;

				default:
					break;
				}

				
			
			}
		
}

bool winChecker(std::vector<std::vector<tiles>> &animboardChecker)
{
	inaRow = 0;
	int row = x;
	int column = y;
	
	while (true)
	{
		if (row < 0 || row >= animboardChecker.size() || !playerSymbol) {
			// handle edge in y-direction
			break;
		}
		if (column < 0 || column >= animboardChecker[0].size() || !playerSymbol) {
			// handle edge in x-direction

			break;
		}
			if (animboardChecker[row][column].tileSymbol == animboardChecker[row][column + 1].tileSymbol && animboardChecker[row][column].tileSymbol == animboardChecker[row][column + 2].tileSymbol)
			{
				return true;
									
			}
			

		

		
			return false;


	}

	
	
}

void boardLayout(std::vector<std::vector<tiles>> board) {
	system("cls");

	if (turn % 2 == 0)
	{
		playerSymbol = 'x';
	}
	else
	{
		playerSymbol = 'o';
	}

	for (size_t i = 0; i < board[0].size(); i++)
	{

		if (x == i)
		{
			std::cout << " " << '|' << " ";

		}
		else
		{
			std::cout << "   ";
		}

	}
	std::cout << std::endl;
	for (size_t i = 0; i < board[0].size(); i++)
	{

		if (x == i)
		{
			std::cout << " " << 'v' << " ";

		}
		else
		{
			std::cout << "   ";
		}

	}
	std::cout << std::endl;
	for (size_t i = 0; i < board[0].size(); i++)
	{

		if (x == i)
		{
			std::cout << "(" << playerSymbol << ")";

		}
		else
		{
			std::cout << "( )";
		}

	}
	std::cout << std::endl;
	
	
	
  	for (int column = board.size() - 1; column >= 0; column--)
		
	{

		
		for (int rows = 0; rows < board[0].size(); rows++)
		{
			
			std::cout << "[" << board[column][rows].tileSymbol << "]";
			
			

		}

		std::cout << std::endl;
		
	}
	
	
	std::cout << turn;
	
}

bool animDrop(int slotdrop,std::vector<std::vector<tiles>>& animboard) {
	
	


	
	for (int i = animboard.size() - 1; i >= 0; i--)
	{
		if (animboard[i][slotdrop].tileSymbol == 'x' || animboard[i][slotdrop].tileSymbol == 'o')
		{
			i++;
			animboard[i][slotdrop].tileSymbol = playerSymbol;

			break;
		}
		if (animboard[i][slotdrop].tileSymbol == '*' )
		{
			
			animboard[i][slotdrop].tileSymbol = playerSymbol;
			
			
		}
		if (i >= 0) {
			animboard[i][slotdrop].tileSymbol = playerSymbol;
			
			
			y = i;
			x = slotdrop;
			boardLayout(animboard);
			
			
			Sleep(100);
			if (i == 0)
			{
				break;
			
			}
			animboard[i][slotdrop].tileSymbol = '*';
		}
		
	}
	winChecker(animboard);
	if (true) {
		std::cout << "three in a row ";
	}

	Sleep(500);
	
	return 0;
	}
