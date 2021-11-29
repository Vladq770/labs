package functions;

import java.io.Serializable;
import java.util.Arrays;
import java.util.Objects;
import java.util.function.Function;

public class ArrayTabulatedFunction implements TabulatedFunction, Serializable {
    private static final long serialVersionUID = 1L;
    private FunctionPoint[] points;
    private int p_length;
    private int p_size;

    public ArrayTabulatedFunction(double leftX, double rightX, int pointsCount) throws IllegalArgumentException {
        if(leftX>=rightX||pointsCount<2){
            throw new IllegalArgumentException();
        }
        this.p_length = pointsCount;
        this.p_size = (int) (pointsCount * 1.5);
        points = new FunctionPoint[p_size];
        for (int i = 0; i < this.p_length; ++i)
            points[i] = new FunctionPoint(leftX + (rightX - leftX) * i / (pointsCount - 1), 0);
    }
    public ArrayTabulatedFunction(FunctionPoint[] arr) throws IllegalArgumentException{
        if(arr.length<2){
            throw new IllegalArgumentException();
        }
        for(int i=0;i<arr.length-1;++i){
            if(arr[i].get_X()>=arr[i+1].get_X()){
                throw new IllegalArgumentException();
            }
        }
        this.p_length = arr.length;
        this.p_size = (int) (arr.length * 1.5);
        points = new FunctionPoint[p_size];
        for(int i=0;i<p_length;++i){
            points[i] = new FunctionPoint(arr[i]);
        }
    }
    public ArrayTabulatedFunction(double leftX, double rightX, double[] values) throws IllegalArgumentException {
        if(leftX>=rightX||values.length<2){
            throw new IllegalArgumentException();
        }
        this.p_length = values.length;
        this.p_size = (int) (values.length * 1.5);
        points = new FunctionPoint[p_size];
        for (int i = 0; i < this.p_length; ++i)
            points[i] = new FunctionPoint(leftX + (rightX - leftX) * i / (values.length - 1), values[i]);
    }

    public double getLeftDomainBorder() {
        return this.points[0].get_X();
    }

    public double getRightDomainBorder() {
        return this.points[p_length - 1].get_X();
    }

    public double getFunctionValue(double x) {
        if ((this.getLeftDomainBorder()<=x)&&(x<=this.getRightDomainBorder())) {
            int first = 0;
            int last = p_length - 1;
            int mid;
            while (first < last) {
                mid = (first + last) / 2;
                if (x >= points[mid].get_X()) {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            }
            return (x * (points[last].get_Y() - points[last - 1].get_Y()) - points[last - 1].get_X() * (points[last].get_Y() - points[last - 1].get_Y()) + points[last - 1].get_Y() * (points[last].get_X() - points[last - 1].get_X())) / (points[last].get_X() - points[last - 1].get_X());
        }
        return Double.NaN;
    }

    public int getPointsCount() {
        return this.p_length;
    }

    public FunctionPoint getPoint(int index) throws FunctionPointIndexOutOfBoundsException {
        if (index<0||index>=this.p_length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        return points[index];
    }

    public void setPoint(int index, FunctionPoint point) throws FunctionPointIndexOutOfBoundsException, InappropriateFunctionPointException{
        if (index<0||index>=this.p_length) {
            throw new FunctionPointIndexOutOfBoundsException();
        }
        if(index==0&&this.points[1].get_X()<=point.get_X()){
            throw new InappropriateFunctionPointException();
        }
        else if(index==this.p_length-1&&this.points[this.p_length-2].get_X()>=point.get_X()){
            throw new InappropriateFunctionPointException();
        }
        else if(this.points[index-1].get_X()>=point.get_X()||this.points[index+1].get_X()<=point.get_X()){
            throw new InappropriateFunctionPointException();
        }
        this.points[index].set_X(point.get_X());
        this.points[index].set_Y(point.get_Y());
    }

    public double getPointX(int index) throws FunctionPointIndexOutOfBoundsException {
        if (index < 0 ||index >= this.p_length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        return this.points[index].get_X();
    }

    public void setPointX(int index, double x) throws FunctionPointIndexOutOfBoundsException, InappropriateFunctionPointException {
        if(index<0||index>=this.p_length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        if(index==0&&this.points[1].get_X()<=x){
            throw new InappropriateFunctionPointException();
        }
        else if(index==this.p_length-1&&this.points[this.p_length-2].get_X()>=x){
            throw new InappropriateFunctionPointException();
        }
        else if(this.points[index-1].get_X()>=x||this.points[index+1].get_X()<=x){
            throw new InappropriateFunctionPointException();
        }
        this.points[index].set_X(x);
    }

    public double getPointY(int index) throws FunctionPointIndexOutOfBoundsException {
        if (index < 0 ||index >= this.p_length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        return this.points[index].get_Y();
    }

    public void setPointY(int index, double y) {
        if (index < 0 ||index >= this.p_length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        this.points[index].set_Y(y);
    }

    public void deletePoint(int index) throws FunctionPointIndexOutOfBoundsException, IllegalStateException{
        if(this.p_length<3){
            throw new IllegalStateException();
        }
        if(index<0||index>=p_length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        System.arraycopy(this.points, index + 1, this.points, index, this.p_length - index - 1);
        --(this.p_length);
        this.points[this.p_length]=null;

        if(2*this.p_length<this.p_size){
            this.p_size=(int)(this.p_length*1.5);
            FunctionPoint[] temp = new FunctionPoint[this.p_size];
            System.arraycopy(this.points,0,temp,0,this.p_length);
            this.points=temp;
        }
    }

    public void addPoint(FunctionPoint point) throws InappropriateFunctionPointException {

        if(this.p_length==this.p_size){
            this.p_size=(int)((this.p_length+1)*1.5);
            FunctionPoint[] temp=new FunctionPoint[this.p_size];
            System.arraycopy(this.points,0,temp,0,this.p_length);
            this.points=temp;
        }
        int first = 0;
        int last = this.p_length - 1;
        int mid;
        while (first < last) {
            mid = (first + last) / 2;
            if (point.get_X() >= this.points[mid].get_X()) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        if(this.points[last].get_X()==point.get_X()){
            throw new InappropriateFunctionPointException();
        }
        if(this.points[last].get_X()<point.get_X()){
            ++last;
            this.points[last]=point;
        }
        else {
            System.arraycopy(this.points, last, this.points, last + 1, this.p_length - last);
            this.points[last] = point;
        }
        ++(this.p_length);
    }

    @Override
    public String toString() {
       StringBuffer buf = new StringBuffer();
       buf.append("{ ");
       for(int i = 0; i < p_length-1; ++i){
           buf.append(points[i].toString());
           buf.append(", ");
       }
       buf.append(points[p_length-1].toString());
       buf.append(" }");
       return buf.toString();
    }

    @Override
    public boolean equals(Object o){
        if( o instanceof TabulatedFunction) {
            if (o instanceof ArrayTabulatedFunction) {
                ArrayTabulatedFunction temp = (ArrayTabulatedFunction) o;
                if (p_length != temp.p_length)
                    return false;
                for (int i = 0; i < p_length; ++i) {
                    if (points[i].get_X() != temp.points[i].get_X() || points[i].get_Y() != temp.points[i].get_Y())
                        return false;
                }
                return true;
            }
            TabulatedFunction temp = (TabulatedFunction) o;
            if (p_length != temp.getPointsCount())
                return false;
            for (int i = 0; i < p_length; ++i) {
                if (!points[i].equals(temp.getPoint(i)))
                    return false;
            }
            return true;
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = p_length;
        for(int i = 0; i < p_length; ++i)
            hash ^= points[i].hashCode();
        return hash;
    }
    public Object clone(){
        FunctionPoint[] temp = new FunctionPoint[p_length];
        System.arraycopy(points,0,temp,0,p_length);
        return new ArrayTabulatedFunction(temp);
    }
}

