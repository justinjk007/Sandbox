import java.util.*;

public class NQueenIterative
{
    static int N = 6;

    static boolean iterativeSolution(int board[][]) 
    {
	Stack lastRow = new Stack();
	Stack lastCol = new Stack();
	int queenCount = 0;
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
				lastCol.push(coloumn);
				lastRow.push(row);
				coloumn++;
				row = 0;
				System.out.println("Queen Placed");
				if(queenCount == N)
				    return false; // We have a soltion
			    }
			else if(row == N)
			    {
				if(!lastRow.empty() && !lastCol.empty())
				    {
					Integer temp1 = (Integer) lastRow.pop();
					Integer temp2 = (Integer) lastCol.pop();
					board[temp1][temp2] = 0;
					System.out.println("Queen Removed");
					queenCount--;
					coloumn = temp2;
					row = temp1+1;
				    }
				else
				    System.out.println("Unimaginable error");
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
