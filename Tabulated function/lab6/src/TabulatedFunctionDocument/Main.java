package TabulatedFunctionDocument;
import functions.*;
import functions.basic.Exp;
import functions.basic.Log;
import functions.meta.Composition;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.*;

public class Main extends Application {
    public static TabulatedFunctionDoc tabFDoc = new TabulatedFunctionDoc("TabulatedFunction");
    public static void main(String[] args) throws  IOException, ClassNotFoundException{
        launch(args);
        /*String a = "qwerty";
        Function ex = new Exp();
        TabulatedFunction testfunction = TabulatedFunctions.tabulate((new Composition(new Log(2), new Exp())),0,10,11);
        FileOutputStream   test1out = new FileOutputStream("testnotfunction.txt");
        ObjectOutputStream test1ouT = new ObjectOutputStream(test1out);
        test1ouT.writeObject(a);
        test1ouT.close();
        TabulatedFunctionDoc test  = new TabulatedFunctionDoc("test");
        test.newFunction(0,35,14);
        test.saveFunctionAs("saveIt");
        TabulatedFunctionDoc test2  = new TabulatedFunctionDoc("test2");
        test2.loadFunction("saveIt");
        test2.saveFunctionAs("saveIt2");
        test2.saveFunction();
        System.out.println(test2.toString());
        System.out.println(test2.hashCode());
        System.out.println(test.hashCode());
        System.out.println(test2.equals(test));
        TabulatedFunctionDoc test3 = (TabulatedFunctionDoc) test2.clone();
        System.out.println(test3.hashCode());
        System.out.println(test3.equals(test));

         */
    }
    @Override
    public void start(Stage stage) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("FXMLMainForm.fxml"));
        Parent root = loader.load();
        FXMLMainFormController ctrl = loader.getController();
        ctrl.setStage(stage);
        ctrl.createWindow();
        ctrl.createEWindow();
        tabFDoc.registerRedrawFunctionController(ctrl);
        Scene scene = new Scene(root);
        stage.setTitle("Tabulated Function");
        stage.setScene(scene);
        stage.setOnCloseRequest(ctrl.getCloseEventHandler());
        stage.show();
    }
}
