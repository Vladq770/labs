package functions.basic;

import functions.Function;

import java.io.Serializable;

public abstract class TrigonometricFunction implements Function, Serializable {
    public double getRightDomainBorder() {
        return Double.POSITIVE_INFINITY;
    }
    public double getLeftDomainBorder() {
        return Double.NEGATIVE_INFINITY;
    }
}
