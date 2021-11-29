package functions.meta;

import functions.Function;

public class Power implements Function {
    private double Pow;
    private Function F;
    public Power(Function f, double x){
        Pow=x;
        F=f;
    }

    @Override
    public double getFunctionValue(double x) {
        return Math.pow(F.getFunctionValue(x),Pow);
    }

    @Override
    public double getRightDomainBorder() {
        return F.getRightDomainBorder();
    }

    @Override
    public double getLeftDomainBorder() {
        return F.getLeftDomainBorder();
    }
}
