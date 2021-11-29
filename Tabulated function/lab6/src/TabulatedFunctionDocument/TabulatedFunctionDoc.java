package TabulatedFunctionDocument;

import functions.*;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TabulatedFunctionDoc implements TabulatedFunction {
    private TabulatedFunction function;
    private String fileName;
    private boolean modified;
    private boolean fileNameAssigned;
    private FXMLMainFormController controller;
    public void setFunction(double leftDomainBorder, double rightDomainBorder, int pointsCount){
        function = new ArrayTabulatedFunction(leftDomainBorder, rightDomainBorder, pointsCount);
        modified = true;
        CallRedraw();
    }
    public void setFunction(TabulatedFunction function){
        this.function = function;
        modified = true;
        CallRedraw();
    }
    public TabulatedFunctionDoc(String fileName){
        this.fileName = fileName;
        modified = false;
        fileNameAssigned = true;
        function = new ArrayTabulatedFunction(0, 4, 5);
    }
    public TabulatedFunctionDoc(){
        this.fileName = "";
        modified = false;
        fileNameAssigned = false;
        function = new ArrayTabulatedFunction(0, 4, 5);
    }
    public void registerRedrawFunctionController (FXMLMainFormController fxmlMainFormController){
        controller = fxmlMainFormController;
        CallRedraw();
    }
    public void CallRedraw(){
        controller.redraw();
    }
    @Override
    public double getFunctionValue(double x) {
        return function.getFunctionValue(x);
    }

    @Override
    public double getRightDomainBorder() {
        return function.getRightDomainBorder();
    }

    @Override
    public double getLeftDomainBorder() {
        return function.getLeftDomainBorder();
    }

    @Override
    public void addPoint(FunctionPoint point) throws InappropriateFunctionPointException {
        function.addPoint(point);
        modified = true;
        if(controller != null)
            CallRedraw();
    }

    @Override
    public void deletePoint(int index) throws FunctionPointIndexOutOfBoundsException, IllegalStateException {
        function.deletePoint(index);
        modified = true;
        if(controller != null)
            CallRedraw();
    }

    @Override
    public void setPointY(int index, double y) {
        function.setPointY(index, y);
        modified = true;
        if(controller != null)
            CallRedraw();
    }

    @Override
    public double getPointY(int index) throws FunctionPointIndexOutOfBoundsException {
        return function.getPointY(index);
    }

    @Override
    public void setPointX(int index, double x) throws FunctionPointIndexOutOfBoundsException, InappropriateFunctionPointException {
        function.setPointX(index, x);
        modified = true;
        if(controller != null)
            CallRedraw();
    }

    @Override
    public double getPointX(int index) throws FunctionPointIndexOutOfBoundsException {
        return function.getPointX(index);
    }

    @Override
    public void setPoint(int index, FunctionPoint point) throws FunctionPointIndexOutOfBoundsException, InappropriateFunctionPointException {
        function.setPoint(index, point);
        modified = true;
        if(controller != null)
            CallRedraw();
    }

    @Override
    public FunctionPoint getPoint(int index) throws FunctionPointIndexOutOfBoundsException {
        return function.getPoint(index);
    }

    @Override
    public int getPointsCount() {
        return function.getPointsCount();
    }

    @Override
    public Object clone() {
        TabulatedFunctionDoc temp = new TabulatedFunctionDoc(this.fileName);
        temp.modified = this.modified;
        temp.fileNameAssigned = this.fileNameAssigned;
        FunctionPoint[] points = new FunctionPoint[function.getPointsCount()];
        for(int i = 0; i < function.getPointsCount(); ++i){
            points[i] = function.getPoint(i);
        }
        temp.function = new ArrayTabulatedFunction(points);
        return temp;
    }

    @Override
    public String toString() {
        return "TabulatedFunctionDoc{" +
                "function= " + function +
                ", fileName='" + fileName + '\'' +
                ", modified=" + modified +
                ", fileNameAssigned=" + fileNameAssigned +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if(o instanceof TabulatedFunctionDoc){
            TabulatedFunctionDoc temp = (TabulatedFunctionDoc) o;
            if(temp.fileName == this.fileName && temp.function.equals(this.function) && temp.modified == this.modified && temp.fileNameAssigned == this.fileNameAssigned)
                return true;
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = function.hashCode();
        char[] arr = fileName.toCharArray();
        for(int i = 0; i < arr.length; ++i)
            hash ^= (int)arr[i];
        if(modified)
            hash ^= 1;
        else
            hash ^= 0;
        if(fileNameAssigned)
            hash ^= 1;
        else
            hash ^= 0;
        return hash;
    }

    public boolean isModified(){
        return modified;
    }
    public boolean isFileNameAssigned(){
       return fileNameAssigned;
    }
    public void newFunction(double leftX, double rightX, int pointsCount){
        this.function = new ArrayTabulatedFunction(leftX, rightX, pointsCount);
        modified = true;
    }
    public void tabulateFunction (Function function, double leftX, double rightX, int pointsCount){
        this.function = TabulatedFunctions.tabulate(function, leftX, rightX, pointsCount);
        modified = true;
        if(controller != null)
            CallRedraw();
    }
    public void saveFunctionAs(String fileName){
        JSONObject count= new JSONObject();
        count.put(Integer.toString(function.getPointsCount()),"");
        JSONArray points = new JSONArray();
        points.add(count);
        for(int i = 0; i < function.getPointsCount(); ++i){
            JSONObject point= new JSONObject();
            point.put(Double.toString(function.getPointX(i)), Double.toString(function.getPointY(i)));
            points.add(point);
        }
        try (FileWriter file = new FileWriter(fileName)){
            file.write(points.toJSONString());
            file.flush();
        } catch (IOException e){}
        modified = false;
    }
    public void loadFunction(String fileName){
        JSONParser parser = new JSONParser();
        try (FileReader reader = new FileReader(fileName)) {
            Object obj = parser.parse(reader);
            JSONArray points = (JSONArray) obj;
            JSONObject temp = (JSONObject)points.get(0) ;
            int len = 0;
            for (Object key : temp.keySet()) {
                len = Integer.parseInt((String) key);
            }
            FunctionPoint[] arr = new FunctionPoint[len];
            for(int i = 1; i < points.size(); ++i) {
                temp = (JSONObject) points.get(i);
                for (Object key : temp.keySet()) {
                    arr[i - 1] = new FunctionPoint(Double.parseDouble((String) key), Double.parseDouble((String) temp.get(key)));
                }
            }
            this.function = new ArrayTabulatedFunction(arr);
        }catch (
    FileNotFoundException e) {
        e.printStackTrace();
    } catch (IOException e) {
        e.printStackTrace();
    } catch (
    ParseException e) {
        e.printStackTrace();
    }
        modified = true;
        if(controller != null)
            CallRedraw();
    }
    public void saveFunction(){
        this.saveFunctionAs(this.fileName);
    }
}
