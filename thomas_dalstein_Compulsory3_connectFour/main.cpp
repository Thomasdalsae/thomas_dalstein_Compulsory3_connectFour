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



int witdh = 7;
int height = 8;
int turn{};

int main(){
	
	
	std::vector<std::vector<tiles>> board(witdh, std::vector<tiles>(height, tiles{ '*' }));

	
	
		dropSlot(board[0].size(), board);
	
	
	
	
	
	
	return 0;
}


bool dropSlot(int boardSize, std::vector<std::vector<tiles>> Aboard) {

	int slot{};
	
		while (true)
		{
			
			
			
			
			for (size_t i = 0; i < boardSize; i++)
			{

				if (slot == i)
				{
					std::cout << "(" << 'x' << ")";

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

					if (slot < 0)
					{
						slot = boardSize - 1;
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
					animDrop(slot, Aboard);
					turn++;

					break;

				default:
					break;
				}

				system("cls");
			
			}
	
}
void boardLayout(std::vector<std::vector<tiles>> board) {

	
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
		if (animboard[i][slotdrop].tileSymbol == 'x')
		{
			i++;
			animboard[i][slotdrop].tileSymbol = 'x';

			break;
		}
		if (animboard[i][slotdrop].tileSymbol == '*' )
		{
			
			animboard[i][slotdrop].tileSymbol = 'x';
			
			
		}
		if (i >= 1) {
			animboard[i][slotdrop].tileSymbol = 'x';
			boardLayout(animboard);
			Sleep(200);
			animboard[i][slotdrop].tileSymbol = '*';
			system("cls");
		}
		
		
	
	}
	

	
	return 0;
	}
	

	

	
	


	
//for (size_t i = 0; i < animboard[0].size(); i++)
//{
//	if (animboard[slotdrop][i].tileSymbol == '*')
//		animboard[slotdrop][i].tileSymbol = animboard[0][1].playerSymbol;
//
//}
//return false;