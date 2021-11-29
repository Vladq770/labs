package functions.basic;

import functions.Function;

public abstract class TrigonometricFunction implements Function {
    public double getRightDomainBorder() {
        return Double.POSITIVE_INFINITY;
    }
    public double getLeftDomainBorder() {
        return Double.NEGATIVE_INFINITY;
    }
}
