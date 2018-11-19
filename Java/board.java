public class board implements global
{
    private static block blocks[][] = new block[3][3];
    private int state = EMPTY;
    
    /**
     * Constructor, putting default state of board (EMPTY)
     */
    public board()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                blocks[i][j] = new block();
            }
        }
    }
    
    public static void makeMove()
    {
        
    }
    
    /**
     * Displays the board to console
     */
    public static void DisplayBoard()
    {
        System.out.println("     |     |     ");
        System.out.println("  " + blocks[0][0] + "  |  " + blocks[0][1] + "  |  " + blocks[0][2] + "  ");
        System.out.println("_____|_____|_____");
        System.out.println("     |     |     ");
        System.out.println("  " + blocks[1][0] + "  |  " + blocks[1][1] + "  |  " + blocks[1][2] + "  ");
        System.out.println("_____|_____|_____");
        System.out.println("     |     |     ");
        System.out.println("  " + blocks[2][0] + "  |  " + blocks[2][1] + "  |  " + blocks[2][2] + "  ");
        System.out.println("     |     |     \n");
    }
    
    public int updateState()
    {
        int new_state;
        new_state = checkRow(0) + checkRow(1) + checkRow(2) + checkCol(0) + checkCol(1) + checkCol(2);
        
        //If the addition is 0, the board is empty
        if (new_state == EMPTY)
            state = new_state;
        
        //If the addition is 1, the game is won by X
        else if(new_state + checkDiagonals() == X)
            state = new_state;
        
        //If the addition is 2, the game is won by O
        else if(new_state + checkDiagonals() == O)
            state = new_state;
        
        return state;
    }
    
    public int checkBoard()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(blocks[i][j].getState() != EMPTY)
                    return 3;
            }
        }
        return 0;
    }
   
    
    private int checkRow(int row)
    {
        if(blocks[row][0].getState() != EMPTY)
        {
            if( (blocks[row][0] == blocks[row][1]) && 
                (blocks[row][1] == blocks[row][2])) 
               return blocks[row][0].getState();
        }
        return EMPTY;
    }
    
    private int checkCol(int col)
    {
        if(blocks[0][col].getState() != EMPTY)
        {
            if( (blocks[0][col] == blocks[1][col]) && 
                (blocks[1][col] == blocks[2][col])) 
               return blocks[0][col].getState();
        }
        return EMPTY;
    }
    
    /**
     * 
     * @return 
     */
    private int checkDiagonals()
    {
        if(blocks[0][0].getState() != EMPTY)
        {
            if( (blocks[0][0] == blocks[1][1]) && 
                (blocks[1][1] == blocks[2][2])) 
               return blocks[0][0].getState();
        }
        else if(blocks[0][2].getState() != EMPTY)
        {
            if( (blocks[0][2] == blocks[1][1]) && 
                (blocks[1][1] == blocks[2][0])) 
               return blocks[0][0].getState();
        }
        return EMPTY;
    }
}
