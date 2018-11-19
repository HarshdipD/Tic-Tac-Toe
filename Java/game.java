import java.util.Scanner;

public class game implements global
{
    
    board gameBoard = new board();
    player playerX;
    //player playerO;
    int turn;
    
    public game()
    {
        System.out.println("TIC TAC TOE");
        board.DisplayBoard();
    }
    
    public void start()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Game with 1. Computer or 2. Human player?");
        int p;
        
        do
        {
            p = sc.nextInt();
                    
            switch(p)
            {
                case 1:
                {
                    playWithHuman();
                    break;
                }
                
                case 2:
                {
                    playWithAI();
                    break;
                }
                
                case 0:
                {
                    System.out.println("Exiting...");
                    break;
                }
                
                default:{
                    System.out.println("Invalid input. To exit, press 0.");
                    break;
                }
            }
        }while(p != 0);
        
    /*
    turn X;
    
        if(turn == X)
        {
            playerX.play(gameBoard);
            board.updateState;
            playerY.play(gameBoard);
        }
        else
        {
            updateState();
            playerY.play(gameBoard);
            playerX.play(gameBoard);
        }
    */
    }
    
    public void playWithHuman()
    {
        //HumanPlayer playerX;
        //HumanPlayer playerO;
        
        playerX.play(gameBoard);
    }
    
    public static void playWithAI()
    {
        
    }
}
