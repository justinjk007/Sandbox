import java.util.Arrays;
import java.util.Stack;

public class queen
{
    static int N = 4;
	
    static void drawLayout(int board[][])
    {
        for (int i = 0; i < N; i++)
	    {
		for (int j = 0; j < N; j++)
		    if (board[i][j] == 1)
			System.out.print("Q   ");
		    else
			System.out.print("_   ");
		System.out.println("\n");
	    }
    }

    static boolean conflictCheck(int board[][], int row, int coloumn)
    {
	int i, j;
	for (i = 0; i < coloumn; i++) {
	    if (board[row][i] == 1)
		return false; // Returns false if there is a conflict
	}
	for (i = row, j = coloumn; i >= 0 && j >= 0; i--, j--) {
	    if (board[i][j] == 1)
		return false;
	}
	for (i = row, j = coloumn; j >= 0 && i < N; i++, j--) {
	    if (board[i][j] == 1)
		return false;
	}
	return true; //No conflicts are occuring, queen can be placed
    }

    static boolean iterativeSolution(int board[][]) 
    {
	int queenCount = 0;
	int lastCol = 0;
	int lastRow = 0;
	int row = 0;
	int coloumn = 0;
	while(row < N)
	    {
		while(coloumn < N)
		    {
			System.out.println(row+" "+coloumn);
			if (conflictCheck(board, row, coloumn))
			    {
				// If there is no conflicts place the queen
				board[row][coloumn] = 1;
				queenCount++;
				lastCol = coloumn;
				lastRow = row;
				coloumn++;
				System.out.println("Queen Placed");
				if(queenCount == N)
				    return false; // We have a soltion
			    }
			else if(row == N)
			    {
				board[lastRow][lastCol] = 0;
				System.out.println("Queen Removed");
				queenCount--;
				coloumn = lastCol+1;
				row = lastRow;
			    }
			else
			    {
				if(row < N-1) 
				    row++;
				else
				    row = 0;
			    }
		    }
	    }
	return true; // This statement is returned, when no solutions are found
    } 
    
    public static void main(String[] args)
    {
	System.out.println("N-queen solution calculated for N="+N);
	System.out.println("");
	int[][] board = new int[N][N];

	if (iterativeSolution(board)) { 
	    System.out.println("Solution not found.");
	}
	else
	    drawLayout(board);

    } // End of main method
}
