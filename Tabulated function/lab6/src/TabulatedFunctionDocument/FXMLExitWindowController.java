package TabulatedFunctionDocument;

import javafx.application.Platform;
import javafx.stage.Stage;
import javafx.event.ActionEvent;

import static TabulatedFunctionDocument.Main.tabFDoc;


public class FXMLExitWindowController {
    private Stage stage;
    public void setStage(Stage stage){
        this.stage = stage;
    }
    public void showDialog(){
        stage.showAndWait();
    }
    public void saveAction(ActionEvent av){
        tabFDoc.saveFunction();
        stage.hide();
        Platform.exit();
    }
    public void notSaveAction(ActionEvent av){
        stage.hide();
        Platform.exit();
    }
    public void cancelAction(ActionEvent av){
        stage.hide();
    }
}
