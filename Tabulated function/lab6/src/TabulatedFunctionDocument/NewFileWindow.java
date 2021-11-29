package TabulatedFunctionDocument;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.IOException;

public class NewFileWindow {
    private FXMLNewFileWindowController ctrl;
    public FXMLNewFileWindowController getCtrl(){
        return ctrl;
    }
    public  void newFileWindow (Stage primaryStage) throws IOException {
        FXMLLoader loader = new FXMLLoader(FXMLNewFileWindowController.class.getResource("FXMLNewFileWindow.fxml"));
        Parent root = loader.load();
        Stage stage = new Stage();
        Scene scene = new Scene(root);
        ctrl = loader.getController();
        ctrl.setStage(stage);
        stage.setTitle("Function parameters");
        stage.setScene(scene);
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.initOwner(primaryStage);
        stage.setResizable(false);
        stage.setOnCloseRequest(ctrl.getCloseEventHandler());
    }
}
