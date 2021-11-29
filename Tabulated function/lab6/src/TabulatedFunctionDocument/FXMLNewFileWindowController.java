package TabulatedFunctionDocument;

import functions.Function;
import functions.TabulatedFunctions;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.stage.WindowEvent;

import static TabulatedFunctionDocument.Main.tabFDoc;


public class FXMLNewFileWindowController {
    static final int cancel = 0;
    static final int ok1 = 1;
    static final int ok2 = 2;
    private int lastButton = 1;
    private  Stage stage;
    private Function function;
    @FXML
    private Spinner<Integer> spinner;
    @FXML
    private TextField leftDomain;
    @FXML
    private TextField rightDomain;
    public void setStage(Stage stage){
        this.stage = stage;
    }
    public void showDialog(){
        stage.showAndWait();
    }
    @FXML
    public void initialize(){
        SpinnerValueFactory.IntegerSpinnerValueFactory valueFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(2, Integer.MAX_VALUE);
        spinner.setValueFactory(valueFactory);
        spinner.setEditable(true);
    }
    public void setFunction(Function function){
        this.function = function;
    }
    public void setLastButton(int lastButton){
        this.lastButton = lastButton;
    }
    @FXML
    public void newFileOk(ActionEvent av){
        try {
            Double.parseDouble(leftDomain.getText());
            Double.parseDouble(rightDomain.getText());
        } catch (NumberFormatException e) {
            System.out.println("Input String cannot be parsed to Double.");
            leftDomain.clear();
            rightDomain.clear();
            stage.hide();
            new Alert(Alert.AlertType.ERROR,"Input String cannot be parsed to Double.", ButtonType.OK).showAndWait();
            return;
        }
        if(lastButton == ok1) {
            tabFDoc.setFunction(getLeftDomainBorder(), getRightDomainBorder(), getPointsCount());
            leftDomain.clear();
            rightDomain.clear();
            stage.hide();
        }
        if(lastButton == ok2){
            if(function != null) {
                tabFDoc.setFunction(TabulatedFunctions.tabulate(function, getLeftDomainBorder(), getRightDomainBorder(), getPointsCount()));
                leftDomain.clear();
                rightDomain.clear();
                stage.hide();
            }
        }
    }
    private EventHandler<WindowEvent> closeEventHandler = new EventHandler<WindowEvent>() {
        @Override
        public void handle(WindowEvent event) {
            leftDomain.clear();
            rightDomain.clear();
            stage.hide();
        }
    };
    public EventHandler<WindowEvent> getCloseEventHandler(){
        return closeEventHandler;
    }
    public void newFileCancel(ActionEvent av){
        leftDomain.clear();
        rightDomain.clear();
        stage.hide();
    }
    public double getLeftDomainBorder(){
        return Double.parseDouble(leftDomain.getText());
    }
    public double getRightDomainBorder(){
        return Double.parseDouble(rightDomain.getText());
    }
    public int getPointsCount(){
        return (Integer)(spinner.getValue());
    }
}
