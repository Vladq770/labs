package functions;

public interface TabulatedFunctionFactory {
    public TabulatedFunction createTabulatedFunction(FunctionPoint[] points);
    public TabulatedFunction createTabulatedFunction(double leftX, double rightX, int pointsCount);
    public TabulatedFunction createTabulatedFunction(double leftX, double rightX, double[] values);
}
