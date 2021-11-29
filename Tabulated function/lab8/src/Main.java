import functions.*;
import functions.basic.*;
import functions.meta.*;
import threads.*;

import java.io.*;

public class Main {
    public static void main(String[] args) throws  InterruptedException{
        /*TabulatedFunction f = new ArrayTabulatedFunction(0, 4, 5);
        TabulatedFunction f2 = new LinkedListTabulatedFunction(0, 4, 5);
        for(FunctionPoint p : f )
            System.out.println(p);

         */

        /*Function f = new Cos();
        TabulatedFunction tf;
        tf = TabulatedFunctions.tabulate(f, 0, Math.PI, 11);
        System.out.println(tf.getClass());
        TabulatedFunctions.setTabulatedFunctionFactory(new
                LinkedListTabulatedFunction.LinkedListTabulatedFunctionFactory());
        tf = TabulatedFunctions.tabulate(f, 0, Math.PI, 11);
        System.out.println(tf.getClass());
        TabulatedFunctions.setTabulatedFunctionFactory(new
                ArrayTabulatedFunction.ArrayTabulatedFunctionFactory());
        tf = TabulatedFunctions.tabulate(f, 0, Math.PI, 11);
        System.out.println(tf.getClass());

         */
        TabulatedFunction f;
        f = TabulatedFunctions.createTabulatedFunction(
                ArrayTabulatedFunction.class, 0, 10, 3);
        System.out.println(f.getClass());
        System.out.println(f);
        f = TabulatedFunctions.createTabulatedFunction(
                ArrayTabulatedFunction.class, 0, 10, new double[] {0, 10});
        System.out.println(f.getClass());
        System.out.println(f);
        f = TabulatedFunctions.createTabulatedFunction(
                LinkedListTabulatedFunction.class,
                new FunctionPoint[] {
                        new FunctionPoint(0, 0),
                        new FunctionPoint(10, 10)
                }
        );
        System.out.println(f.getClass());
        System.out.println(f);
        f = TabulatedFunctions.tabulate(
                LinkedListTabulatedFunction.class, new Sin(), 0, Math.PI, 11);
        System.out.println(f.getClass());
        System.out.println(f);
    }

    public static void complicatedThreads() throws InterruptedException{
        Task task = new Task(1000);
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
