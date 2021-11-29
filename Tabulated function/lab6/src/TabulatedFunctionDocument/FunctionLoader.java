package TabulatedFunctionDocument;

import functions.*;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
/*
Загрузить можно объект, который был ранее сериализован
 */
public class FunctionLoader extends ClassLoader{
    public Function functionLoader(String fileName){
        Object f = null;
        try {
            FileInputStream inputFile = new FileInputStream(fileName);
            ObjectInputStream inputObject = new ObjectInputStream(inputFile);
            f = inputObject.readObject();
            inputObject.close();
            inputFile.close();
        }catch(FileNotFoundException e){
            new Alert(Alert.AlertType.ERROR,"FileNotFoundException", ButtonType.OK).showAndWait();
            return null;}
        catch(IOException e){
            new Alert(Alert.AlertType.ERROR,"IOException", ButtonType.OK).showAndWait();
            return null;}
        catch (ClassNotFoundException e){
            new Alert(Alert.AlertType.ERROR,"ClassNotFoundException", ButtonType.OK).showAndWait();
            return null;}
        if(f instanceof Function)
            return (Function) f;
        return null;
    }
}
