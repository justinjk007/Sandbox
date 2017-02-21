import java.util.*;

public class IterativeNQueenAll
{
    static int N = 9;
    static int[] valid = new int[N];
    static int[] position = new int[N];

    static void print_all(int p[])
    {
        for (int i = 0; i < p.length; i++)
            {
                for (int j = 0; j < p.length; j++)
                    {
                        if(p[i] == j)
                            System.out.print("Q ");
                        else 
                            System.out.print("* ");
                    }
                System.out.println();
            }
        System.out.println();
    }

    static boolean toBool(int num)
    {
        if(num == 0)
            return false;
        else
            return true;
    }
    static int toNum(boolean ans)
    {
        if(ans == true)
            return 1;
        else
            return 0;
    }
    static void conflictCheck(int board[], int pos[])
    {
        int val =1;
        int q;
        int c;
        for (q=1; q< N; ++q)
            {
                if (toBool(val))
                    {
                        for (c=0; c<q; ++c)
                            val = toNum(toBool(val) && (position[c] != position[q]) && (position[c] + (q-c) != position[q]) && (position[c] != position[q] + (q-c)));
                    }
                valid[q] = val;
            }
    } // End of conflictchecker

    
    public static void main(String[] args)
    {
        System.out.println("N-queen solution calculated for N="+N + " using ITERATION");
        System.out.println("");
        //time at start of the program
        long startTime = System.currentTimeMillis();

        int q;
        int solutions = 0;
        int iterations = 0;

        for (q=0; q < N; ++q)
            {
                position[q] = 0;
                valid[q] = 1;
            }
        while (true)
            {
                iterations++;
                conflictCheck(valid, position);
                if (toBool(valid[N-1]))
                    {
                        solutions++;
                        print_all(position);
                    }

                for (q=N-1; q>=0; --q)
                    {
                        int val = toNum((q==0) || (toBool(valid[q-1])));
                        if (toBool(val) && (position[q]<N-1))
                            {
                                position[q]++;
                                break; // out of for loop
                            }
                        position[q] = 0;
                    }
                if (q<0)
                    {
                        break; // out of while loop
                    }

            } // end of while (1)

        System.out.println("Number of iterations "+ iterations);
        System.out.println("Number of solutions "+ solutions);

        //time at end of program and total time for program to run 
        long endTime   = System.currentTimeMillis();
        long totalTime = endTime - startTime;
        System.out.println("Solutions calculated and printed in " + totalTime + " milliseconds");

        //     }

    } // End of main method
} 
