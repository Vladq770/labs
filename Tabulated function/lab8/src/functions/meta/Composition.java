package functions.meta;

import functions.Function;

public class Composition implements Function {
    private Function F1, F2;
    public Composition(Function f1, Function f2){
        F1=f1;
        F2=f2;
    }

    @Override
    public double getFunctionValue(double x) {
        return F1.getFunctionValue(F2.getFunctionValue(x));
    }

    @Override
    public double getRightDomainBorder() {
        return F2.getRightDomainBorder();
    }

    @Override
    public double getLeftDomainBorder() {
        return F2.getLeftDomainBorder();
    }
}
