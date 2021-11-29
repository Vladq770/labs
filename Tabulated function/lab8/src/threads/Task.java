package threads;

import functions.Function;
import functions.Functions;

public class Task {
    private Function f;
    private double left;
    private double right;
    private double step;
    private int countOfTasks;
    public Task (int count){
        countOfTasks = count;
    }
    public void setTask(Function f, double left, double right, double step){
        this.f = f;
        this.left = left;
        this.right = right;
        this.step = step;
    }
    public int getCountOfTasks() {
        return countOfTasks;
    }
    public double getLeft(){
        return left;
    }
    public double getStep(){
        return step;
    }
    public double getRight(){
        return right;
    }
    public Function getF(){
        return f;
    }
}
