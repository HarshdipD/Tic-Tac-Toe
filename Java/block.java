class block implements global{
    public static int state;
    
    /**
     * Constructor, by default the state of block is empty
     */
    public block()
    {
        state = EMPTY;
    }
    
    /**
     * Sets the state of the block
     * @param new_state 
     * @return true
     */
    public static boolean setState(int new_state)
    {
        if(isValidState(new_state))
        {
            state = new_state;
        }
        
        return true;
    }
    
    /**
     * Helper boolean function
     * @param new_state
     * @return if the state is X or O then true
     */
    public static boolean isValidState(int new_state)
    {
        return (state == X || state == O);
    }
    
    /**
     * Getter
     * @return state
     */
    public int getState()
    {
        return state;
    }
    
    /**
     * toString method
     * @return
     */
    @Override
    public String toString()
    {
        switch (state) {
            case EMPTY:
                return " "; 
            case 1:
                return "X";
            default:
                return "O";
        }
    }
}
