package functions;

import java.io.Serializable;
import java.util.Objects;

public class FunctionPoint implements Serializable {
    private double axis_X, axis_Y;
    public FunctionPoint(double x, double y) {
        this.axis_X=x;
        this.axis_Y=y;
    }
    public FunctionPoint(FunctionPoint point) {
        this.axis_X=point.axis_X;
        this.axis_Y=point.axis_Y;
    }
    public FunctionPoint() {
        this.axis_X=0;
        this.axis_Y=0;
    }
    public double get_X(){
        return this.axis_X;
    }
    public double get_Y(){
        return this.axis_Y;
    }
    public void set_X(double x){
        this.axis_X=x;
    }
    public void set_Y(double y){
        this.axis_Y=y;
    }

    @Override
    public String toString() {
        return "(" + axis_X + ';' + axis_Y + ')';
    }

    @Override
    public boolean equals(Object o) {
        if(o instanceof FunctionPoint && ((FunctionPoint) o).get_X()==get_X()&&((FunctionPoint) o).get_Y()==get_Y()){
            return true;
        }
        return false;
    }

    @Override
    public int hashCode() {
        int a = (int)(Double.doubleToLongBits(get_X())^(Double.doubleToLongBits(get_X())>>32));
        int b = (int)(Double.doubleToLongBits(get_Y())^(Double.doubleToLongBits(get_Y())>>32));
        return a^b;
    }
    public Object clone(){
        return new FunctionPoint(this);
    }
}

