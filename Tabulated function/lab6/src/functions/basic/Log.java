package functions.basic;

import functions.Function;

import java.io.Serializable;

public class Log implements Function, Serializable {
    private double base;
    public Log(double b){
        if(b>0&&b!=1)
            base=b;
    }
    public double getFunctionValue(double x) {
        if(x>0)
            return Math.log(x)/Math.log(base);
        return Double.NaN;
    }
    public double getRightDomainBorder() {
        return Double.POSITIVE_INFINITY;
    }
    public double getLeftDomainBorder() {
        return 0;
    }
}
