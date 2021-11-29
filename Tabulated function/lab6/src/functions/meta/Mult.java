package functions.meta;

import functions.Function;

public class Mult implements Function {
    private Function F1, F2;
    public Mult(Function f1, Function f2){
        F1=f1;
        F2=f2;
    }
    @Override
    public double getFunctionValue(double x) {
        return (F1.getFunctionValue(x)*F2.getFunctionValue(x));
    }

    @Override
    public double getRightDomainBorder() {
        if(F1.getRightDomainBorder()<F2.getLeftDomainBorder()||F2.getRightDomainBorder()<F1.getLeftDomainBorder())
            return Double.NaN;
        return Math.min(F1.getRightDomainBorder(),F2.getRightDomainBorder());
    }

    @Override
    public double getLeftDomainBorder() {
        if(F1.getRightDomainBorder()<F2.getLeftDomainBorder()||F2.getRightDomainBorder()<F1.getLeftDomainBorder())
            return Double.NaN;
        return Math.max(F1.getLeftDomainBorder(),F2.getLeftDomainBorder());
    }
}