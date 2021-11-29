import functions.*;
import functions.basic.*;
import functions.meta.*;
import threads.*;

import java.io.*;

public class Main {
    public static void main(String[] args) throws  InterruptedException{
        //Function ex = new Exp();
        //System.out.println(Functions.valueOfIntegral(ex, 0 ,1, 0.001));
        //nonThread();
        //simpleThreads();
        complicatedThreads();
    }
    public static void nonThread(){
        Task task = new Task(100);
        for(int i = 0; i < task.getCountOfTasks(); ++i){
            task.setTask(new Log(Math.random() * 9 +1), Math.random() * 100, Math.random() * 100 + 100, Math.random());
            System.out.println("Source " + task.getLeft() + " | " + task.getRight() + " | " + task.getStep());
            System.out.println("Result "+ task.getLeft() + " | " + task.getRight() + " | " + task.getStep() + " | " + Functions.valueOfIntegral(task.getF(), task.getLeft(), task.getRight(), task.getStep()));
        }
    }
    public static void simpleThreads(){
        Task task = new Task(100);
        Thread simpleGenerator = new Thread(new SimpleGenerator(task));
        Thread simpleIntegrator = new Thread(new SimpleIntegrator(task));
        //simpleGenerator.setPriority(7);
        //simpleGenerator.setPriority(3);
        simpleGenerator.start();
        simpleIntegrator.start();
    }
    public static void complicatedThreads() throws InterruptedException{
        Task task = new Task(100);
        Semaphore semaphore = new Semaphore();
        Thread generator = new Thread(new Generator(task, semaphore));
        Thread integrator = new Thread(new Integrator(task, semaphore));
        //generator.setPriority(1);
        generator.start();
        integrator.start();
        Thread.sleep(50);
        generator.interrupt();
        integrator.interrupt();
    }
}
