package functions;

public interface TabulatedFunction extends Function, Cloneable{
    public void addPoint(FunctionPoint point) throws InappropriateFunctionPointException;
    public void deletePoint(int index) throws FunctionPointIndexOutOfBoundsException, IllegalStateException;
    public void setPointY(int index, double y);
    public double getPointY(int index) throws FunctionPointIndexOutOfBoundsException;
    public void setPointX(int index, double x) throws FunctionPointIndexOutOfBoundsException, InappropriateFunctionPointException;
    public double getPointX(int index) throws FunctionPointIndexOutOfBoundsException;
    public void setPoint(int index, FunctionPoint point) throws FunctionPointIndexOutOfBoundsException, InappropriateFunctionPointException;
    public FunctionPoint getPoint(int index) throws FunctionPointIndexOutOfBoundsException;
    public int getPointsCount();
    public Object clone();
}
