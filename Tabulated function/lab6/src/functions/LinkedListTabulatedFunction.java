package functions;

import java.io.*;
import java.util.Objects;

public class LinkedListTabulatedFunction implements TabulatedFunction, Externalizable {
    public LinkedListTabulatedFunction(){};


    public void writeExternal(ObjectOutput out) throws IOException {
        out.writeInt(length);
        for(int i=0;i<length;++i){
            out.writeDouble(getPointX(i));
            out.writeDouble(getPointY(i));
        }
        out.flush();
    }


    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
        int len = in.readInt();
        length = 1;
        Head = new FunctionNode();
        Head.next=Head.prev = new FunctionNode();
        Head.next.point = new FunctionPoint(in.readDouble(), in.readDouble());
        Head.next.next=Head.next.prev=Head.next;
        curIndex=0;
        curNode=Head.next;
        for(int i=1;i<len;++i){
            addNodeToTail().point = new FunctionPoint(in.readDouble(), in.readDouble());
        }
    }

    private static final long serialVersionUID = 1L;
    private FunctionNode Head, curNode;
    private int length, curIndex;
    private class FunctionNode implements Serializable{
        private FunctionPoint point;
        private FunctionNode next, prev;
    }
    public LinkedListTabulatedFunction(FunctionPoint[] arr) throws IllegalArgumentException {
        if (arr.length < 2) {
            throw new IllegalArgumentException();
        }
        for (int i = 0; i < arr.length - 1; ++i) {
            if (arr[i].get_X() >= arr[i + 1].get_X()) {
                throw new IllegalArgumentException();
            }
        }
        length = 1;
        Head = new FunctionNode();
        Head.next=Head.prev = new FunctionNode();
        Head.next.point = new FunctionPoint(arr[0]);
        Head.next.next=Head.next.prev=Head.next;
        curIndex=0;
        curNode=Head.next;
        for(int i=1;i<arr.length;++i){
            addNodeToTail().point = new FunctionPoint(arr[i]);
        }
    }
    public LinkedListTabulatedFunction(double leftX, double rightX, int pointsCount) throws IllegalArgumentException {
        if(leftX>=rightX||pointsCount<2){
            throw new IllegalArgumentException();
        }
        length = 1;
        Head = new FunctionNode();
        Head.next=Head.prev = new FunctionNode();
        Head.next.point = new FunctionPoint(leftX,0);
        Head.next.next=Head.next.prev=Head.next;
        curIndex=0;
        curNode=Head.next;
        for (int i = 1; i < pointsCount; ++i)
            addNodeToTail().point= new FunctionPoint(leftX + (rightX - leftX) * i / (pointsCount - 1), 0);
    }
    public LinkedListTabulatedFunction(double leftX, double rightX, double[] values) throws IllegalArgumentException {
        if(leftX>=rightX||values.length<2){
            throw new IllegalArgumentException();
        }
        length = 1;
        Head = new FunctionNode();
        Head.next=Head.prev = new FunctionNode();
        Head.next.point = new FunctionPoint(leftX,values[0]);
        Head.next.next=Head.next.prev=Head.next;
        curIndex=0;
        curNode=Head.next;
        for (int i = 1; i < values.length; ++i)
            addNodeToTail().point= new FunctionPoint(leftX + (rightX - leftX) * i / (values.length - 1), values[i]);
    }
    private static int min(int a,int b,int c){
        if(a<=b&&a<=c)
            return a;
        if(b<=c)
            return b;
        return c;
    }
    private FunctionNode getNodeByIndex(int index){
        if(this.min(index,length-index,Math.abs(curIndex-index))==index){
            curNode=Head.next;
            curIndex=0;
            for(int i=0;i<index;++i) {
                curNode=curNode.next;
                ++curIndex;
            }
            return curNode;
        }
        if(this.min(index,length-index,Math.abs(curIndex-index))==length-index){
            curNode=Head.next.prev;
            curIndex=length-1;
            for(int i=0;i<length-index-1;++i) {
                curNode=curNode.prev;
                --curIndex;
            }
            return curNode;
        }
        if(this.min(index,length-index,Math.abs(curIndex-index))==Math.abs(curIndex-index)){
            if(curIndex-index>=0){
                int x=curIndex-index;
                for(int i=0;i<x;++i){
                    curNode=curNode.prev;
                    --curIndex;
                }
            }
            else{
                int x=index-curIndex;
                for(int i=0;i<x;++i){
                    curNode=curNode.next;
                    ++curIndex;
                }
            }
        }
        return curNode;
    }
    private FunctionNode addNodeToTail(){
        FunctionNode temp = new FunctionNode();
        temp.prev=Head.next.prev;
        temp.next=Head.next;
        Head.next.prev.next=temp;
        Head.next.prev=temp;
        curNode=temp;
        curIndex=length++;
        return curNode;
    }
    private FunctionNode addNodeByIndex(int index) {
        FunctionNode temp = new FunctionNode();
        if (index == 0) {
            temp.next = Head.next;
            temp.prev = Head.next.prev;
            Head.next.prev.next = temp;
            Head.next.prev = temp;
            Head.next = temp;
            Head.prev = temp;
        }
        else if(index==length-1){
            addNodeToTail();
        }
        else {
            FunctionNode Pr = getNodeByIndex(index - 1);
            temp.next = Pr.next;
            temp.prev = Pr;
            Pr.next.prev = temp;
            Pr.next = temp;
        }
        curIndex=index;
        curNode=temp;
        ++length;
        return curNode;
    }
    private FunctionNode deleteNodeByIndex(int index){
        FunctionNode temp = getNodeByIndex(index);
        if(index==0){
            Head.next.next.prev=Head.next.prev;
            Head.next.prev.next=Head.next.next;
            Head.next=temp.next;
            Head.prev=temp.next;
        }
        else{
            temp.prev.next=temp.next;
            temp.next.prev=temp.prev;
        }
        --length;
        return temp;
    }
    public double getLeftDomainBorder(){
        return Head.next.point.get_X();
    }
    public double getRightDomainBorder(){
        return Head.next.prev.point.get_X();
    }
    public double getFunctionValue(double x) {
        if ((getLeftDomainBorder()<=x)&&(x<=getRightDomainBorder())) {
            curNode=Head.next;
            curIndex=0;
            while(!(curNode.point.get_X()<=x&&x<=curNode.next.point.get_X())){
                curNode=curNode.next;
                ++curIndex;
            }
            return (x * (curNode.next.point.get_Y() - curNode.point.get_Y()) - curNode.point.get_X() * (curNode.next.point.get_Y() - curNode.point.get_Y()) + curNode.point.get_Y() * (curNode.next.point.get_X() - curNode.point.get_X())) / (curNode.next.point.get_X() - curNode.point.get_X());
        }
        return Double.NaN;
    }
    public int getPointsCount() {
        return length;
    }
    public FunctionPoint getPoint(int index) throws FunctionPointIndexOutOfBoundsException {
        if (index<0||index>=length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        return getNodeByIndex(index).point;
    }
    public void setPoint(int index, FunctionPoint point) throws FunctionPointIndexOutOfBoundsException, InappropriateFunctionPointException{
        if (index<0||index>=length) {
            throw new FunctionPointIndexOutOfBoundsException();
        }
        if(index==0&&Head.next.next.point.get_X()<=point.get_X()){
            throw new InappropriateFunctionPointException();
        }
        else if(index==length-1&&Head.next.prev.prev.point.get_X()>=point.get_X()){
            throw new InappropriateFunctionPointException();
        }
        else if(getNodeByIndex(index-1).point.get_X()>=point.get_X()||getNodeByIndex(index+1).point.get_X()<=point.get_X()){
            throw new InappropriateFunctionPointException();
        }
        getNodeByIndex(index).point.set_X(point.get_X());
        getNodeByIndex(index).point.set_Y(point.get_Y());
    }
    public double getPointX(int index) throws FunctionPointIndexOutOfBoundsException {
        if (index < 0 ||index >= length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        return getNodeByIndex(index).point.get_X();
    }
    public void setPointX(int index, double x) throws FunctionPointIndexOutOfBoundsException, InappropriateFunctionPointException {
        if (index<0||index>=length) {
            throw new FunctionPointIndexOutOfBoundsException();
        }
        if(index==0&&Head.next.next.point.get_X()<=x){
            throw new InappropriateFunctionPointException();
        }
        else if(index==length-1&&Head.next.prev.prev.point.get_X()>=x){
            throw new InappropriateFunctionPointException();
        }
        else if(getNodeByIndex(index-1).point.get_X()>=x||getNodeByIndex(index+1).point.get_X()<=x){
            throw new InappropriateFunctionPointException();
        }
        getNodeByIndex(index).point.set_X(x);
    }
    public double getPointY(int index) throws FunctionPointIndexOutOfBoundsException {
        if (index < 0 ||index >= length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        return getNodeByIndex(index).point.get_Y();
    }

    public void setPointY(int index, double y) {
        if (index < 0 ||index >= length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        getNodeByIndex(index).point.set_Y(y);
    }
    public void deletePoint(int index) throws FunctionPointIndexOutOfBoundsException, IllegalStateException{
        if(length<3){
            throw new IllegalStateException();
        }
        if(index<0||index>=length){
            throw new FunctionPointIndexOutOfBoundsException();
        }
        deleteNodeByIndex(index);
    }

    public void addPoint(FunctionPoint point) throws InappropriateFunctionPointException {
        if (point.get_X() < Head.next.point.get_X()) {
            addNodeByIndex(0).point = point;
        } else if (point.get_X() > Head.next.prev.point.get_X()) {
            addNodeToTail().point = point;
        } else if (point.get_X() == Head.next.prev.point.get_X()) {
            throw new InappropriateFunctionPointException();
        } else {
            curNode = Head.next;
            curIndex = 0;
            while (!(curNode.point.get_X() <= point.get_X() && point.get_X() < curNode.next.point.get_X())) {
                curNode = curNode.next;
                ++curIndex;
            }
            if (curNode.point.get_X() == point.get_X()) {
                throw new InappropriateFunctionPointException();
            }
            addNodeByIndex(curIndex+1).point = point;
        }
    }

    @Override
    public String toString() {
        StringBuffer buf = new StringBuffer();
        buf.append(getPointsCount());
        buf.append(" { ");
        for(int i = 0; i < length-1; ++i){
            buf.append(getPoint(i).toString());
            buf.append(", ");
        }
        buf.append(getPoint(length-1).toString());
        buf.append(" }");
        return buf.toString();
    }

    @Override
    public boolean equals(Object o) {
        if( o instanceof TabulatedFunction) {
            if (o instanceof LinkedListTabulatedFunction) {
                LinkedListTabulatedFunction temp = (LinkedListTabulatedFunction) o;
                if (length != temp.length)
                    return false;
                for (int i = 0; i < length; ++i) {
                    if (getPointX(i) != temp.getPointX(i) || getPointY(i) != temp.getPointY(i))
                        return false;
                }
                return true;
            }
            TabulatedFunction temp = (TabulatedFunction) o;
            if(length != temp.getPointsCount())
                return false;
            for(int i = 0; i < length; ++i){
                if(!getPoint(i).equals(temp.getPoint(i)))
                    return false;
            }
            return true;
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = length;
        for(int i = 0; i < length; ++i){
            hash ^= getPoint(i).hashCode();
        }
        return hash;
    }
    public Object clone(){
        FunctionPoint[] temp = new FunctionPoint[length];
        for(int i = 0; i < length; ++i){
            temp[i] = new FunctionPoint(getPoint(i));
        }
        return new LinkedListTabulatedFunction(temp);
    }
}

