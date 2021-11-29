package functions;

import functions.meta.*;


public class Functions{
    private Functions(){};
    public static double valueOfIntegral(Function f, double left, double right, double step){
        if(left < f.getLeftDomainBorder() || right > f.getRightDomainBorder() || step <= 0)
            throw new IllegalArgumentException();
        double temp = left;
        double value = 0;
        while(temp + step < right){
            value += (f.getFunctionValue(temp) + f.getFunctionValue(temp + step)) * step * 0.5;
            temp += step;
        }
        value += (f.getFunctionValue(temp) + f.getFunctionValue(right)) * (right - temp) * 0.5;
        return value;
    }
    public static Function shift(Function f, double shiftX, double shiftY){
        return new Shift(f,shiftX,shiftY);
    }
    public static Function scale(Function f, double scaleX, double scaleY){
        return new Scale(f,scaleX,scaleY);
    }
    public static Function power(Function f, double power){
        return new Power(f,power);
    }
    public static Function sum(Function f1, Function f2){
        return new Sum(f1,f2);
    }
    public static Function mult(Function f1, Function f2){
        return new Mult(f1,f2);
    }
    public static Function composition(Function f1, Function f2){
        return new Composition(f1,f2);
    }
}
