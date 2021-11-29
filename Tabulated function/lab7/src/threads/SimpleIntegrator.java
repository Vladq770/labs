package threads;

import functions.Functions;
import functions.basic.Log;

public class SimpleIntegrator implements Runnable{
    private Task task;
    public SimpleIntegrator(Task task){
        this.task = task;
    }
    public void run(){
        for(int i = 0; i < task.getCountOfTasks(); ++i) {
            synchronized (task) {
                if (task.getF() != null)
                    System.out.println("Result " + task.getLeft() + " | " + task.getRight() + " | " + task.getStep() + " | " + Functions.valueOfIntegral(task.getF(), task.getLeft(), task.getRight(), task.getStep()));
                Thread.yield();
            }
        }
    }
}
