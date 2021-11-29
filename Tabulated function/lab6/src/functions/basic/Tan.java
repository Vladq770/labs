package functions.basic;

import java.io.Serializable;

public class Tan extends TrigonometricFunction implements Serializable {
    public double getFunctionValue(double x) {
        return Math.tan(x);
    }
}
