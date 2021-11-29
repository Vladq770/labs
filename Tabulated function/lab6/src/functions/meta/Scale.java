package functions.meta;

import functions.Function;

public class Scale implements Function {
    private Function F;
    private double X;
    private double Y;
    public Scale(Function f, double x, double y){
        F=f;
        X=x;
        Y=y;
    }

    @Override
    public double getFunctionValue(double x) {
        return Y*F.getFunctionValue(X*x);
    }

    @Override
    public double getRightDomainBorder() {
        if(X>=0)
            return F.getRightDomainBorder()/X;
        return F.getLeftDomainBorder()/X;
    }

    @Override
    public double getLeftDomainBorder() {
        if(X>=0)
            return F.getLeftDomainBorder()/X;
        return F.getRightDomainBorder()/X;
    }
}
