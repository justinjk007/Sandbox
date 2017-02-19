import java.util.Scanner;
import java.util.Arrays;

public class queen {
    static Scanner scan;
    static int N = 4;
	
    static void drawLayout(int board[][]) {
        int i;
        for (i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                if (board[i][j] == 1) {
                    System.out.print("Q ");
                } else {
                    System.out.print("_ ");
                }
            System.out.println("\n");
        }
    }

    static boolean conflictCheck(int board[][], int row, int coloumn) {
        int i, j;
        for (i = 0; i < coloumn; i++) {
            if (board[row][i] == 1)
                return false;
        }
        for (i = row, j = coloumn; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1)
                return false;
        }
        for (i = row, j = coloumn; j >= 0 && i < N; i++, j--) {
            if (board[i][j] == 1)
                return false;
        }
        return true;
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

    static boolean iterativeSolution(int board[][])
    {
        for (int row = 0; row < N; row++)
            for(int coloumn =0; coloumn < N; coloumn++)
                {
                    if (coloumn >= N || row >=N)
                        return true; // Solution found
                    board[row][coloumn] = 1;
                    if (!conflictCheck(board, row, coloumn))
                        {
                            board[row][coloumn] = 0; // We are backtracking here
                        }
                }
        return false; // This statement is returned, when no solutions are found
    } 

    public static void main(String[] args) {
    scan = new Scanner(System.in);
    System.out.println("State the value of N in this program!");
    N = scan.nextInt();
    int[][] board = new int[N][N];
    // This is for finding the first solution

    // if (!recursiveSolution(board, 0)) { 
    // 	System.out.println("Solution not found.");
    // }
    // drawLayout(board);

    // for(int i =0; i < N; i++)
    //     {
    //         for(int[] eachRow: board)
    //             Arrays.fill(eachRow,0); // Resets the array every loop
    //         if (recursiveSolution(board, i))
    //             {
    //                 drawLayout(board);
    //                 System.out.println("-------------------------------------------------------");
    //             }
    //     }

    if (!iterativeSolution(board)) { 
        System.out.println("Solution not found.");
    }
    drawLayout(board);

    }
}
// http://stackoverflow.com/questions/18610003/can-we-solve-n-queens-without-backtracking-and-how-to-calculate-and-what-will-b
