package TabulatedFunctionDocument;

import functions.FunctionPoint;

public class FunctionPointT {
    private double x;
    private double y;
    public FunctionPointT(FunctionPoint p){
        this.x = p.get_X();
        this.y = p.get_Y();
    }
    public Double getX() {
        return x;
    }

    public void setX(Double x) {
        this.x = x;
    }
    public Double getY() {
        return y;
    }

    public void setY(Double y) {
        this.y = y;
    }

}
