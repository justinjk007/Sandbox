import java.util.*;

public class RecursiveNQueenAll {
	
    //declare and initialize board size variable and solutions counter 
    public static int n = 8;
    public static int total = 0;
	
    //prints an single-dimension array as an NxN square of * and Q, where Q represents queen positions
    public static void printBoard(int[] board){
        for (int i = 0; i < board.length; i++){
            for (int j = 0; j < board.length; j++){
                if(board[i] == j)
                    System.out.print("Q ");
                else 
                    System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }
	
    //checks if a given coordinate on the board is safe for a queen to be placed
    //single dimension array is used to represent the board
    //index is used as row and value at index as column coordinate for queen position
    public static boolean safe(int[] board, int x){
        for (int i = 0; i < x; i++){
			
            //if this condition is true, there is a queen in the same column
            if (board[i] == board[x]){
                return false;
            }
			
            //if this condition is true, there is a diagonal attack
            if (Math.abs(board[i] - board[x]) == Math.abs(i - x)){
                return false;
            }
        }
        return true;
    }
	
    //combines printBoard method and safe() method to check for safe positions on the board, put queens, and print solution
    public static void placeQueen(int[] board, int x){
        //base case, if N queens have already been placed, solution found, print it
        if (x >= n){
            printBoard(board);
            //counter to keep track of total number of solutions
            total++;
            return;
        }
		
        for (int i = 0; i < n; i++){
            board[x] = i;
            //recursive backtracking call to find solutions for each row
            if (safe(board, x))
                placeQueen(board, x + 1);
            //no-solution case
            else
                board[x] = 0;
        }
    }
	
    public static void main(String[] args){
        //time at start of the program
        long startTime = System.currentTimeMillis();
			
        int[] board = new int[n];
        Arrays.fill(board, 0);
        placeQueen(board, 0);
        System.out.println("-------------------------------------");
        System.out.println("For n = " + n + ", there are " + total + " solutions");
			
        //time at end of program and total time for program to run 
        long endTime   = System.currentTimeMillis();
        long totalTime = endTime - startTime;
        System.out.println("Solutions calculated and printed in " + totalTime + " milliseconds");
    }
	
}
