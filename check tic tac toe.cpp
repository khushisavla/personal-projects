#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>


using namespace std;

bool check(bool check_array[])
{
	for(int i = 0; i <= 6 ; i = i+3)
	{
		if(check_array[i] == true && check_array[i+1] == true && 
		check_array[i+2] == true)
		{
			return true;
		}
	}
	
	
	 for(int i = 0; i <3 ; i ++)
	{
		if(check_array[i] == true && check_array[i+3] == true && 
		check_array[i+6] == true)
		{
			return true;
		}
	}
	
	if(check_array[0] == true && check_array[4]== true && check_array[8]==true)
	{
		return true;
	}
	
	else if(check_array[2] == true && check_array[4]== true && check_array[6]==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void grid(bool o_array[], bool x_array[])
{
	cout<< endl;
	//check each row
	int num =0;
	for(int i= 0; i<9 ; i++)
	{

			if(o_array[i] == true)
			{
				cout<<"O";
			}
			else if(x_array[i]==true)
			{
				cout<<"X";
			}
			else
			{
				cout<<" ";
			}
			if(i != 2 && i!= 5 && i!= 8)
			cout<< "|";
		
		if ( (i+1)%3 == 0 && i!=8)
		{
			cout<< endl<<"_ _ _"<<endl;
		}
	}
	cout<<endl;
}

int main() 
{
	
	//intitialization
	string player1 = "x", player2 = "o";
	bool x_array[9] = {false};
	bool o_array[9] = {false};
	cout<<"Welcome to Tic Tac Toe"<<endl;
	

	bool finish = false;
	int turn = 1;
	//begining game
	while(finish == false && turn<=9)
	{
		if(turn%2 !=0)
		{ 
		//player one
		bool proceed1 =false;
		bool winner = false;
		do
		{
		cout<< "Player 1, Pick your spot"<<endl;
		double input = 0;
		cin >> input;
		int spot = input;
		spot--;
		if(x_array[spot] != true && o_array[spot] != true)
		{
			if(spot >= 0 && spot <= 8)
			{
				
			o_array[spot] = true;
			grid(o_array, x_array);
			proceed1 = true;
			turn++;
		}
			}
		}while(proceed1 ==false);
		
		for (int i = 0; i <9 ; i++)
		{
		    cout << o_array[i];
		}
		cout<< endl;
		for (int i = 0; i <9 ; i++)
		{
		    cout << x_array[i];
		}
		cout<< endl;
		winner = check(o_array);
		if (winner==true)
			{
				finish = true;
				cout<< "Player 1 Wins!";
			}
			//check when to put the increment of turn
			else if(winner != true && turn ==10)
			{
				finish = true;
				cout<< "game is a draw";
		}	
	}
		
		else
		{ 
		
		//player two
		bool proceed2 =false;
		bool winner = false;
		do
		{
		cout<< "Player 2, Pick your spot"<<endl;
		double input = 0;
		cin >> input;
		int spot = input;
		spot--;
		
		if(x_array[spot] != true && o_array[spot] != true)
		{
		    if(spot >= 0 && spot <= 8)
		    {
		    x_array[spot] = true;
			grid(o_array, x_array);
			proceed2 = true;
			turn++;
			}
			
		}
		}while(proceed2 ==false);
		for (int i = 0; i <9 ; i++)
		{
		    cout << o_array[i];
		}
		cout<< endl;
		for (int i = 0; i <9 ; i++)
		{
		    cout << x_array[i];
		}
		cout<< endl;
		winner = check(x_array);
		if (winner==true)
			{
				finish = true;
				cout<< "Player 2 Wins!";
			}
			//check when to put the increment of turn
			else if(winner != true && turn ==10)
			{
				finish = true;
				cout<< "game is a draw";
		}	
		
			
	}
	
}
	
return EXIT_SUCCESS;
}
