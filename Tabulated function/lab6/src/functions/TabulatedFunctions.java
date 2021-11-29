package functions;

import java.io.*;

public class TabulatedFunctions{
    private TabulatedFunctions(){};
    public static TabulatedFunction tabulate(Function function, double leftX, double rightX, int pointsCount) throws IllegalArgumentException{
        if(leftX<function.getLeftDomainBorder()||rightX>function.getRightDomainBorder()||pointsCount<2||leftX>=rightX){
            throw new IllegalArgumentException();
        }
        FunctionPoint[] arr = new FunctionPoint[pointsCount];
        for(int i=0;i<pointsCount;++i){
            arr[i] = new FunctionPoint((leftX + (rightX - leftX) * i / (pointsCount - 1)),function.getFunctionValue((leftX + (rightX - leftX) * i / (pointsCount - 1))));
        }
        return new ArrayTabulatedFunction(arr);
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
        return new ArrayTabulatedFunction(arr);
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
        return new ArrayTabulatedFunction(arr);
    }
}
