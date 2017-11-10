import java.util.*;

public class Parallel extends Thread
{
    public static int x =1;	    // Global variable
    public static boolean flag = true; // Semaphore
    public void run(){
	if(flag)
	    {
		++x;
		flag = false; // This thread has been already been ran once
		System.out.println("Thread ran..");
	    }
	else
	    System.out.println("Thread prevented..");
    }
    public static void main(String args[]){
	Parallel thread1 = new Parallel();
	thread1.start();

	Parallel thread2 = new Parallel();
	thread2.start();

	System.out.print("X after running two threads safely: "+ x + "\n");
    }
}
