package threads;

import functions.Functions;
import functions.basic.Log;

public class Integrator extends Thread{
    private  Task task;
    private Semaphore semaphore;
    public Integrator(Task task, Semaphore semaphore){
        this.task = task;
        this.semaphore = semaphore;
    }
    public void run(){
        for(int i = 0; i < task.getCountOfTasks() && !interrupted(); ++i) {
            try {
                semaphore.beginRead();
                if (task.getF() != null)
                    System.out.println("Result " + task.getLeft() + " | " + task.getRight() + " | " + task.getStep() + " | " + Functions.valueOfIntegral(task.getF(), task.getLeft(), task.getRight(), task.getStep()));
                semaphore.endRead();
            }catch (InterruptedException e){
                System.out.println("InterruptedException of Integrator");
                return;
            }
        }
    }
}
