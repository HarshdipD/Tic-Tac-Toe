package tictactoenew;

class block implements global{
    private static int state;
    
    public block()
    {
        state = EMPTY;
    }
    
    public static boolean setState(int new_state)
    {
        if(isValidState(new_state))
        {
            new_state = state;
        }
        
        return true;
    }
    
    public static boolean isValidState(int new_state)
    {
        return (state == X || state == O);
    }
    
    public int getState()
    {
        return state;
    }
    
    @Override
    public String toString()
    {
        if(state == EMPTY) return " "; 
        else if(state == 1) return "x"; 
        else return "o"; 
    }
}
