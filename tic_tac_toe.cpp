#include <iostream>
using namespace std;


char board [3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};   //declared 2D array. First square brackets for rows and second for columns. each curly has one row content

char turn = 'X';  //we have defined array data type as character because later we want to replace these numbers with characters. i.e. X or O

bool draw = false;


void display_board(){
	
	    system ("cls");  // it is useful bcz on every input, it will not display new board but will make changes on the same board
	
	
	cout<<"  \n  T I C K TAC T O E GAME\n"<<endl;
	
	cout<<"  Player1 [X] \n  Player2 [O]\n"<<endl;
	cout<<endl;
	
	
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t   "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
	cout<<"\t\t _____|_____|_____ \n";
	
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t   "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
	cout<<"\t\t _____|_____|_____ \n";
	
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t   "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
	cout<<"\t\t      |     |     \n";
}

//we made a function with name display_board and saved all that code which was to print board on screen in it. now, everytime we have to print a board, we don't have to write
//complete code. we can simply call the function.


void player_turn (){
	
	int choice;	
	int row, column;
	
	//cout<<"  PLayer1 [X] turn : ";

	if (turn == 'X')
	cout<<"\n Player1 [X] turn : ";
	
	if (turn == 'O')
	cout<<"\n Player2 [O] turn : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			row = 0; column = 0;
			break;
			
			case 2:
			row = 0; column = 1;
			break;
			
			case 3:
			row = 0; column = 2;
			break;
			
			case 4:
			row = 1; column = 0;
			break;
			
			case 5:
			row = 1; column = 1;
			break;
			
			case 6:
			row = 1; column = 2;
			break;
			
			case 7:
			row = 2; column = 0;
			break;
			
			case 8:
			row = 2; column = 1;
			break;
			
			case 9:
			row = 2; column = 2;
			break;
			
			default : 
			cout<<"Invalid Choice"<<endl;
	}
	
	if (turn == 'X' && board[row][column]!='X' && board[row][column]!='O')
	    {
		  board[row][column] = 'X';
		  turn = 'O';                      //after player 1 turn. now it is turn of second player which is O
	    }
		
		else if(turn == 'O' && board[row][column]!='X' && board[row][column]!='O')               //these additional conditions of 'board not equal to' are playing important role.
		                                                                               //previously, if one user has given input, the input by other was able to overwrite it. now by these
		                                                                               //conditions,only blank space can be filled. those already filled cannot be overwritten.
		{
			board [row][column] = 'O';
			turn = 'X';
		}
		
		else 
		{
			cout<<"\nBox is already filled! Try another number\n";
			player_turn();
		}
	
display_board(); cout<<endl;
	
}


//now we have to end game somewhere. There can be three scenarios. Any one player wins. OR Game is draw. OR it's still continue. means all boxes are not filled and no one wins yet

bool gameover(){
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][0]== board[i][2] || board[0][i] == board[1][i] && board[0][i]== board[2][i]){
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0]== board[2][2] || board[0][2] == board[1][1] && board[0][2]== board[2][0]){
        return true;
    }
    bool flag = true;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                flag = false;
            }
        }
    }
    if (flag){
        draw = true;
    }
    return false;
}


int main()
{
	
	
	//int A[9];            //this is an array. used to declare multiple variables of same type. here, we had to declare nine variables corresponds to each number so that when 
	                     //user enters number, that number is replaced by X or O. so that can only be done if numbers are variables. if constant, it's not possible
	                     
	    // single dimensional array: Having one row and multiple columns. so here we have 3 rows. we have to declare array for every row.
	    
	    //2D array : Having multiple rows and columns
	    
	    /* so we have 3 methods of declaring 9 variables. first one is declaring separately and we would have to take input as well. so it would become very lengthy
		other method is to use 3 single dimensional arrays, one for each row and last is to use a 2D array*/
	
	
	cout<<"  \n  T I C K TAC T O E GAME\n"<<endl;
	
	cout<<"  Player1 [X] \n  Player2 [O]\n"<<endl;
	cout<<endl;	 
	
    
    while(gameover() == false)                          //while(true) is used for infinite loop. means it will continue and never end. but we had to end it. so we use that function in while
 {
	if (draw == true){
            break;}
    display_board(); cout<<endl;
	cout<<endl;
	
	player_turn(); cout<<endl;
	
	cout<<endl;
	gameover();
}

if(turn == 'X' && draw == false)
cout<<"Player2 [O] wins. Congrats!"<<endl;         //if the turn now is of player X, means that player2 has won because he has played bari and now turn is of X. 

if(turn == 'O' && draw == false)
cout<<"Player1 [X] wins. Congrats!"<<endl;
else{
	cout << "ITS A DRAW";
}
	return 0;
}
