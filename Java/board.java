public class board implements global {
    public static block blocks[][];
    private int state = EMPTY;
    
    /**
     * 
     */
    public board()
    {
        blocks = new block[3][3];
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                blocks[i][j] = new block();
            }
        }
    }
    
    public static void DisplayBoard()
    {
        System.out.println("Player 1: X\tvs\tPlayer 2: O\n");

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
        
        if (new_state == EMPTY) state = new_state;
        return state;
        
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
