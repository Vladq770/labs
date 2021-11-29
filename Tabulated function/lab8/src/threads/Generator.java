package threads;

import functions.basic.Log;

public class Generator extends Thread{
    private  Task task;
    private Semaphore semaphore;
    public Generator(Task task, Semaphore semaphore){
        this.task = task;
        this.semaphore = semaphore;
    }
    public void run(){
        for(int i = 0; i < task.getCountOfTasks() && !interrupted(); ++i) {
            try {
                semaphore.beginWrite();
                task.setTask(new Log(Math.random() * 9 + 1), Math.random() * 100, Math.random() * 100 + 100, Math.random());
                System.out.println("Source " + task.getLeft() + " | " + task.getRight() + " | " + task.getStep());
                semaphore.endWrite();
            }catch (InterruptedException e){
                System.out.println("InterruptedException of Generator");
                return;
            }
        }
    }
}
