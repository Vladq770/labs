package functions.meta;

import functions.Function;

public class Shift implements Function {
    private Function F;
    private double A,B;
    public Shift(Function f,double a, double b){
        F=f;
        A=a;
        B=b;
    }
    @Override
    public double getFunctionValue(double x) {
        return F.getFunctionValue(x)+B;
    }

    @Override
    public double getRightDomainBorder() {
        return F.getRightDomainBorder()-A;
    }

    @Override
    public double getLeftDomainBorder() {
        return F.getLeftDomainBorder()-A;
    }
}
