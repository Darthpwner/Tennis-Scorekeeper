/*Property of Maximagq 
Created 20 August 2014
All Rights Reserved*/

//Insert backspace to go undo

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void getSetScore(const int& setScoreP1,const int& setScoreP2)
{
	cout << setScoreP1 << endl;
	cout << setScoreP2 << endl;
}

void getGameScore(const int& gameScoreP1, const int& gameScoreP2)
{
	cout << gameScoreP1 << endl;
	cout << gameScoreP2 << endl;
}

void getPointScore(const int& pointScoreP1, const int& pointScoreP2)
{
	cout << pointScoreP1 << endl;
	cout << pointScoreP2 << endl;
}

void getPointScoreAd(int& pointScore)
{
	if (pointScore == 1)
	{
		cout << "Ad" << endl;
		cout << endl;
	}

	else if (pointScore == 2)
	{
		cout << endl;
		cout << "Ad" << endl;
	}
}

int main()
{
	int setScoreP1 = 0, setScoreP2 = 0, gameScoreP1 = 0, gameScoreP2 = 0, pointScoreP1 = 0, pointScoreP2 = 0;
	bool deuce = false, AdP1 = false, AdP2 = false;

	int numOfSets;
	cout << "How many sets do you want to play (1, 3, or 5)?" << endl;
	while (true)
	{
		cin >> numOfSets;
		if (numOfSets != 1 && numOfSets != 3 && numOfSets != 5)
			cout << "Enter 1, 3, or 5" << endl;
		else
			break;
	}

	string Player1Name, Player2Name;
	cout << "What is Player 1's name?" << endl;
	cin.ignore(10000, '\n');
	getline(cin, Player1Name);

	cout << "What is Player 2's name?" << endl;
	getline(cin, Player2Name);

	do
	{
		if (pointScoreP1 == 40 && pointScoreP2 == 40)
			deuce = true;

		if ((setScoreP1 != 0 || setScoreP2 != 0))
		{
			cout << "Set score" << endl;
			getSetScore(setScoreP1, setScoreP2);
			cout << "Game score" << endl;
			getGameScore(gameScoreP1, gameScoreP2);
			cout << "Point score" << endl;
			if (deuce == true)
				cout << "Deuce" << endl;
			else if (AdP1 == true)
				cout << "Advantage " << Player1Name << endl;
			else if (AdP2 == true)
				cout << "Advantage " << Player2Name << endl;
			else
				getPointScore(pointScoreP1, pointScoreP2);
		}

		else if (gameScoreP1 != 0 || gameScoreP2 != 0)
		{
			cout << "Game score" << endl;
			getGameScore(gameScoreP1, gameScoreP2);
			cout << "Point score" << endl;
			if (deuce == true)
				cout << "Deuce" << endl;
			else if (AdP1 == true)
				cout << "Advantage " << Player1Name << endl;
			else if (AdP2 == true)
				cout << "Advantage " << Player2Name << endl;
			else
				getPointScore(pointScoreP1, pointScoreP2);
		}

		else
		{
			cout << "Point score" << endl;
			if (deuce == true)
				cout << "Deuce" << endl;
			else if (AdP1 == true)
				cout << "Advantage " << Player1Name << endl;
			else if (AdP2 == true)
				cout << "Advantage " << Player2Name << endl;
			else
				getPointScore(pointScoreP1, pointScoreP2);
		}
		cout << endl << "Which player won the point (1 or 2): ";
		int input;
		cin >> input;
		if (input != 1 && input != 2)
		{
			cout << "Enter 1 or 2" << endl;
			continue;
		}

		if (deuce == true)
		{
			if (input == 1)
			{
				deuce = false;
				AdP1 = true;
				pointScoreP1 = -1, pointScoreP2 = -1;
				continue;
			}

			else if (input == 2)
			{
				deuce = false;
				AdP2 = true;
				pointScoreP1 = -1, pointScoreP2 = -1;
				continue;
			}
		}

		if (input == 1 && (pointScoreP1 == 0 || pointScoreP1 == 15))
			pointScoreP1 += 15, deuce = false;
		else if (input == 1 && pointScoreP1 == 30)
			pointScoreP1 += 10, deuce = false;
		else if (input == 1 && (pointScoreP1 == 40 && pointScoreP2 != 40 || AdP1 == true))
		{
			pointScoreP1 = 0;
			pointScoreP2 = 0;
			gameScoreP1++;
			cout << "Game " << Player1Name << endl;
			deuce = false;
			AdP1 = false;
		}
		else if (AdP1 == true && input == 2)
		{
			pointScoreP1 = -1;
			pointScoreP2 = -1;
			deuce = true;
			AdP1 = false;
		}
		else if (input == 2 && (pointScoreP2 == 0 || pointScoreP2 == 15))
			pointScoreP2 += 15, deuce = false;
		else if (input == 2 && pointScoreP2 == 30)
			pointScoreP2 += 10, deuce = false;
		else if (AdP2 == true && input == 1)
		{
			pointScoreP1 = -1;
			pointScoreP2 = -1;
			deuce = true;
			AdP2 = false;
		}
		else if (input == 2 && (pointScoreP2 == 40 && pointScoreP1 != 40 || AdP2 == true))
		{
			pointScoreP1 = 0;
			pointScoreP2 = 0;
			gameScoreP2++;
			cout << "Game " << Player2Name << endl;
			deuce = false;
			AdP2 = false;
		}

		if ((gameScoreP1 >= 6 || gameScoreP2 >= 6) && abs(gameScoreP1 - gameScoreP2) > 1)
		{
			if (gameScoreP1 == 6)
			{
				setScoreP1++;
				cout << "Set " << Player1Name << endl;
				gameScoreP1 = 0;
				gameScoreP2 = 0;
			}
			else
			{
				setScoreP2++;
				cout << "Set " << Player2Name << endl;
				gameScoreP1 = 0;
				gameScoreP2 = 0;
			
			}
		}
		
		if (numOfSets == 1)
		{
			if (setScoreP1 == 1)
			{
				cout << Player1Name << " wins" << endl;
				break;
			}
			
			else if (setScoreP2 == 1)
			{
				cout << Player2Name << " wins" << endl;
				break;
			}
		}

		else if (numOfSets == 3)
		{
			if (setScoreP1 == 2)
			{
				cout << Player1Name << " wins" << endl;
				break;
			}
			
			else if (setScoreP2 == 2)
			{
				cout << Player2Name << " wins" << endl;
				break;
			}
		}

		else
		{
			if (setScoreP1 == 3)
			{
				cout << Player1Name << " wins" << endl;
				break;
			}
			else if (setScoreP2 == 3)
			{
				cout << Player2Name << " wins" << endl;
				break;
			}
		}
	}
	while (true);
}
