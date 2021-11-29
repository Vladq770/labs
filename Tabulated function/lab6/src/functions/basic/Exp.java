package functions.basic;

import functions.Function;

import java.io.Serializable;

public class Exp implements Function, Serializable {
    public double getFunctionValue(double x) {
        return Math.exp(x);
    }
    public double getRightDomainBorder() {
        return Double.POSITIVE_INFINITY;
    }
    public double getLeftDomainBorder() {
        return Double.NEGATIVE_INFINITY;
    }
}
