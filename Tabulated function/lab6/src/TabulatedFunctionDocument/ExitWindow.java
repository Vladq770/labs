package TabulatedFunctionDocument;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.IOException;

public class ExitWindow {
    private FXMLExitWindowController ctrl;
    public FXMLExitWindowController getCtrl(){
        return ctrl;
    }
    public  void newExitWindow (Stage primaryStage) throws IOException {
        FXMLLoader loader = new FXMLLoader(FXMLExitWindowController.class.getResource("FXMLExitWindow.fxml"));
        Parent root = loader.load();
        Stage stage = new Stage();
        Scene scene = new Scene(root);
        ctrl = loader.getController();
        ctrl.setStage(stage);
        stage.setTitle("Tabulated Function");
        stage.setScene(scene);
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.initOwner(primaryStage);
        stage.setResizable(false);
    }
}
