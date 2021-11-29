package functions.basic;

import java.io.Serializable;

public class Cos extends TrigonometricFunction implements Serializable {
    public double getFunctionValue(double x) {
        return Math.cos(x);
    }
}
