import java.util.Scanner;
import java.util.Arrays;
import java.util.Stack;

public class queen {
    static Scanner scan;
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
        return true; //No conflicts are occuring, queen can be placed
    }

    public static void main(String[] args)
    {
        scan = new Scanner(System.in);
        System.out.println("State the value of N in this program!");
        N = scan.nextInt();
        System.out.println("");
        System.out.println("");
        int[][] board = new int[N][N];

        if (!recursiveSolution(board, 0)) { 
            System.out.println("Solution not found.");
        }
        drawLayout(board);

    } // End of main method
}
