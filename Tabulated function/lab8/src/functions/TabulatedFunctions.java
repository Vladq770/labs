package functions;

import javax.xml.crypto.NoSuchMechanismException;
import java.io.*;
import java.lang.reflect.Constructor;
import java.util.NoSuchElementException;

public class TabulatedFunctions{
    private TabulatedFunctions(){};
    private static TabulatedFunctionFactory tabulatedFunctionFactory = new ArrayTabulatedFunction.ArrayTabulatedFunctionFactory();
    public static void setTabulatedFunctionFactory(TabulatedFunctionFactory tabulatedFunctionFactory) {
        TabulatedFunctions.tabulatedFunctionFactory = tabulatedFunctionFactory;
    }
    public static TabulatedFunction createTabulatedFunction(FunctionPoint[] points){
        return tabulatedFunctionFactory.createTabulatedFunction(points);
    }
    public static TabulatedFunction createTabulatedFunction(double leftX, double rightX, int pointsCount){
        return tabulatedFunctionFactory.createTabulatedFunction(leftX, rightX, pointsCount);
    }
    public static TabulatedFunction createTabulatedFunction(double leftX, double rightX, double[] values){
        return tabulatedFunctionFactory.createTabulatedFunction(leftX, rightX, values);
    }
    public static TabulatedFunction createTabulatedFunction(Class<? extends TabulatedFunction> classFunction, FunctionPoint[] points){
        Constructor[] constructors = classFunction.getConstructors();
        for(Constructor constructor : constructors){
            Class[] parameters = constructor.getParameterTypes();
            if(parameters[0].equals(points.getClass())){
                try{
                    return (TabulatedFunction) constructor.newInstance(new Object[]{points});
                }catch (Exception e){
                    throw new IllegalArgumentException(e);
                }
            }
        }
        throw new NoSuchMechanismException();
    }
    public static TabulatedFunction createTabulatedFunction(Class<? extends TabulatedFunction> classFunction, double leftX, double rightX, int pointsCount){
        Constructor[] constructors = classFunction.getConstructors();
        for(Constructor constructor : constructors){
            Class[] parameters = constructor.getParameterTypes();
            if (parameters.length == 3 && parameters[0].equals(Double.TYPE) && parameters[1].equals(Double.TYPE) && parameters[2].equals(Integer.TYPE)){
                try{
                    return (TabulatedFunction) constructor.newInstance(leftX, rightX, pointsCount);
                }catch (Exception e){
                    throw new IllegalArgumentException(e);
                }
            }
        }
        throw new NoSuchMechanismException();
    }
    public static TabulatedFunction createTabulatedFunction(Class<? extends TabulatedFunction> classFunction, double leftX, double rightX, double[] values){
        Constructor[] constructors = classFunction.getConstructors();
        for(Constructor constructor : constructors){
            Class[] parameters = constructor.getParameterTypes();
            if (parameters.length == 3 && parameters[0].equals(Double.TYPE) && parameters[1].equals(Double.TYPE) && parameters[2].equals(values.getClass())){
                try{
                    return (TabulatedFunction) constructor.newInstance(leftX, rightX, values);
                }catch (Exception e){
                    throw new IllegalArgumentException(e);
                }
            }
        }
        throw new NoSuchMechanismException();
    }
    public static TabulatedFunction tabulate(Class<? extends TabulatedFunction> classFunction, Function function, double leftX, double rightX, int pointsCount) throws IllegalArgumentException{
        if(leftX<function.getLeftDomainBorder()||rightX>function.getRightDomainBorder()||pointsCount<2||leftX>=rightX){
            throw new IllegalArgumentException();
        }
        FunctionPoint[] arr = new FunctionPoint[pointsCount];
        for(int i=0;i<pointsCount;++i){
            arr[i] = new FunctionPoint((leftX + (rightX - leftX) * i / (pointsCount - 1)),function.getFunctionValue((leftX + (rightX - leftX) * i / (pointsCount - 1))));
        }
        return createTabulatedFunction(classFunction, arr);
    }
    public static TabulatedFunction tabulate(Function function, double leftX, double rightX, int pointsCount) throws IllegalArgumentException{
        if(leftX<function.getLeftDomainBorder()||rightX>function.getRightDomainBorder()||pointsCount<2||leftX>=rightX){
            throw new IllegalArgumentException();
        }
        FunctionPoint[] arr = new FunctionPoint[pointsCount];
        for(int i=0;i<pointsCount;++i){
            arr[i] = new FunctionPoint((leftX + (rightX - leftX) * i / (pointsCount - 1)),function.getFunctionValue((leftX + (rightX - leftX) * i / (pointsCount - 1))));
        }
        return createTabulatedFunction(arr);
    }
    public static void outputTabulatedFunction(TabulatedFunction function, OutputStream out) throws IOException {
        DataOutputStream Out = new DataOutputStream(out);
        int len = function.getPointsCount();
        Out.writeInt(len);
        for(int i=0;i<len;++i){
            Out.writeDouble(function.getPointX(i));
            Out.writeDouble(function.getPointY(i));
        }
        Out.flush();
    }
    public static TabulatedFunction inputTabulatedFunction(InputStream in) throws IOException{
        DataInputStream In = new DataInputStream(in);
        int len = In.readInt();
        FunctionPoint arr[] = new FunctionPoint[len];
        for (int i=0;i<len;i++) {
            arr[i] = new FunctionPoint(In.readDouble(),In.readDouble());
        }
        return createTabulatedFunction(arr);
    }
    public static TabulatedFunction inputTabulatedFunction(Class<? extends TabulatedFunction> classFunction, InputStream in) throws IOException{
        DataInputStream In = new DataInputStream(in);
        int len = In.readInt();
        FunctionPoint arr[] = new FunctionPoint[len];
        for (int i=0;i<len;i++) {
            arr[i] = new FunctionPoint(In.readDouble(),In.readDouble());
        }
        return createTabulatedFunction(classFunction, arr);
    }
    public static void writeTabulatedFunction(TabulatedFunction function, Writer out){
        int len = function.getPointsCount();
        PrintWriter Out = new PrintWriter(out);
        Out.print(len);
        for(int i=0;i<len;++i){
            Out.print(' ');
            Out.print(function.getPointX(i));
            Out.print(' ');
            Out.print(function.getPointY(i));
        }
        Out.flush();
    }
    public static TabulatedFunction readTabulatedFunction(Reader in) throws IOException{
        StreamTokenizer In = new StreamTokenizer(in);
        In.nextToken();
        int len = (int)In.nval;
        FunctionPoint[] arr = new FunctionPoint[len];
        double x;
        double y;
        for(int i=0;i<len;++i){
            In.nextToken();
            x=In.nval;
            In.nextToken();
            y=In.nval;
            arr[i] = new FunctionPoint(x,y);
        }
        return createTabulatedFunction(arr);
    }
    public static TabulatedFunction readTabulatedFunction(Class<? extends TabulatedFunction> classFunction, Reader in) throws IOException{
        StreamTokenizer In = new StreamTokenizer(in);
        In.nextToken();
        int len = (int)In.nval;
        FunctionPoint[] arr = new FunctionPoint[len];
        double x;
        double y;
        for(int i=0;i<len;++i){
            In.nextToken();
            x=In.nval;
            In.nextToken();
            y=In.nval;
            arr[i] = new FunctionPoint(x,y);
        }
        return createTabulatedFunction(classFunction, arr);
    }
}
