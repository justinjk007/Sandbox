import java.util.Scanner;
import java.util.Arrays;
import java.util.Stack;

public class RecursiveNQueen {
    static Scanner scan;
    static int N = 8;
	
    static void drawLayout(int board[][])
    {
        for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    if (board[i][j] == 1)
                        System.out.print("Q   ");
                    else
                        System.out.print("*   ");
                System.out.println("\n");
            }
    }

    static boolean recursiveSolution(int board[][], int coloumn) {
        if (coloumn >= N)
            return true; // This is our base case
        for (int i = 0; i < N; i++)
            {
                if (conflictCheck(board, i, coloumn))
                    {
                        board[i][coloumn] = 1;
                        if (recursiveSolution(board, coloumn + 1))
                            return true;
                        board[i][coloumn] = 0; // We are backtracking here
			// The placed queen is removed
                    }
            }
        return false; // This statement is returned, when no solutions are found
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
        return true; //No conflicts are occuring, Queen can be placed
    }

    public static void main(String[] args)
    {
        System.out.println("N-queen solution calculated for N="+N + " using RECURSION");
	System.out.println("");
        System.out.println("");
	//time at start of the program
	long startTime = System.currentTimeMillis();
        int[][] board = new int[N][N];

        if (!recursiveSolution(board, 0))
	    { 
		System.out.println("Solution not found.");
	    }
	else
	    {
		drawLayout(board);
		//time at end of program and total time for program to run 
		long endTime   = System.currentTimeMillis();
		long totalTime = endTime - startTime;
		System.out.println("Solutions calculated and printed in " + totalTime + " milliseconds");
	    }

    } // End of main method
}
