package functions.basic;

import java.io.Serializable;

public class Sin extends TrigonometricFunction implements Serializable {
    public double getFunctionValue(double x) {
        return Math.sin(x);
    }
}
