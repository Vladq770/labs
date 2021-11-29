package threads;


import functions.Functions;
import functions.basic.Log;

public class SimpleGenerator implements Runnable{
    private Task task;
    public SimpleGenerator(Task task){
        this.task = task;
    }
    public void run(){
        for(int i = 0; i < task.getCountOfTasks(); ++i) {
            synchronized (task) {
                task.setTask(new Log(Math.random() * 9 + 1), Math.random() * 100, Math.random() * 100 + 100, Math.random());
                System.out.println("Source " + task.getLeft() + " | " + task.getRight() + " | " + task.getStep());
                Thread.yield();
            }
        }
    }
}
