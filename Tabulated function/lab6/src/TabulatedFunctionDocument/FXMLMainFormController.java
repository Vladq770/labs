package TabulatedFunctionDocument;


import functions.Function;
import functions.InappropriateFunctionPointException;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.fxml.FXML;
import javafx.scene.control.cell.PropertyValueFactory;
import functions.FunctionPoint;
import javafx.stage.Stage;
import javafx.stage.FileChooser;
import javafx.stage.WindowEvent;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import static TabulatedFunctionDocument.Main.tabFDoc;


public class FXMLMainFormController {
    @FXML
    private TableView<FunctionPointT> table;
    @FXML
    private MenuItem NewFileItem;
    @FXML
    private TextField edX, edY;
    @FXML
    private Label pointOf;
    private FileChooser fileChooser;
    @FXML
    private ArrayList<FunctionPointT> points = new ArrayList<FunctionPointT>();
    @FXML
    private TableColumn<FunctionPointT, Double> xColumn;
    @FXML
    private TableColumn<FunctionPointT, Double> yColumn;
    private static Stage stage;
    public void setStage(Stage stage){
        FXMLMainFormController.stage = stage;
    }
    private NewFileWindow window;
    private ExitWindow exitWindow;
    private FunctionLoader functionLoader;
    public void createWindow(){
        try {
            window = new NewFileWindow();
            window.newFileWindow(stage);
        }catch(IOException e){}
    }
    public void createEWindow(){
        try {
            exitWindow = new ExitWindow();
            exitWindow.newExitWindow(stage);
        }catch(IOException e){}
    }
    public FXMLMainFormController(){
        functionLoader = new FunctionLoader();
        fileChooser = new FileChooser();
    }
    @FXML
    private void initPoints(){
        for(int i = 0; i < tabFDoc.getPointsCount(); ++i)
            points.add(new FunctionPointT(tabFDoc.getPoint(i)));
    }
    @FXML
    private void mouseClicked(MouseEvent mouseEvent){
        pointOf.setText("Point " + (table.getSelectionModel().getSelectedIndex() + 1) + " of " + points.size());
    }
    @FXML
    private void addPointClick(ActionEvent av) throws InappropriateFunctionPointException {
        try {
            Double.parseDouble(edX.getText());
            Double.parseDouble(edY.getText());
        } catch (NumberFormatException e) {
            System.out.println("Input String cannot be parsed to Double.");
            edX.clear();
            edY.clear();
            return;
        }
        tabFDoc.addPoint(new FunctionPoint(Double.parseDouble(edX.getText()), Double.parseDouble(edY.getText())));
        edX.clear();
        edY.clear();
    }
    @FXML
    private void deleteClick(ActionEvent av) throws InappropriateFunctionPointException {
        if(table.getSelectionModel().getSelectedItem() != null) {
            tabFDoc.deletePoint(table.getSelectionModel().getSelectedIndex());
        }
        else {
            try {
                Double.parseDouble(edX.getText());
                Double.parseDouble(edY.getText());
            } catch (NumberFormatException e) {
                System.out.println("Input String cannot be parsed to Double.");
                edX.clear();
                edY.clear();
                return;
            }
            FunctionPoint temp = new FunctionPoint(Double.parseDouble(edX.getText()), Double.parseDouble(edY.getText()));
            for(int i = 0; i < tabFDoc.getPointsCount(); ++i){
                if(tabFDoc.getPoint(i).equals(temp)){
                    tabFDoc.deletePoint(i);
                    break;
                }
            }
        }
        edX.clear();
        edY.clear();
    }
    @FXML
    public void initialize(){
        xColumn.setCellValueFactory(new PropertyValueFactory<FunctionPointT, Double>("x"));
        yColumn.setCellValueFactory(new PropertyValueFactory<FunctionPointT, Double>("y"));
        initPoints();
        table.getItems().addAll(points);
        pointOf.setText("Point 0 of " + points.size());
    }
    private EventHandler<WindowEvent> closeEventHandler = new EventHandler<WindowEvent>() {
        @Override
        public void handle(WindowEvent event) {
            if(tabFDoc.isModified()){
                event.consume();
                exitWindow.getCtrl().showDialog();
            }
        }
    };
    public EventHandler<WindowEvent> getCloseEventHandler(){
        return closeEventHandler;
    }
    @FXML
    public void newFileAction(ActionEvent av){
        window.getCtrl().setLastButton(1);
        window.getCtrl().showDialog();
    }
    /*
    Загрузка из Json файла
     */
    @FXML
    public void openFileAction(ActionEvent av){
        if(fileChooser == null){
            fileChooser = new FileChooser();
        }
        fileChooser.setTitle("Open File");
        File file = fileChooser.showOpenDialog(stage);
        if(file != null){
                tabFDoc.loadFunction(file.getAbsolutePath());
        }
    }
    @FXML
    public void saveAction(ActionEvent av){
       tabFDoc.saveFunction();
    }
    @FXML
    public void saveAsAction(ActionEvent av){
        if(fileChooser == null){
            fileChooser = new FileChooser();
        }
        fileChooser.setTitle("Save File");
        File file = fileChooser.showSaveDialog(stage);
        if(file != null){
            tabFDoc.saveFunctionAs(file.getAbsolutePath());
        }
    }
    @FXML
    public void exitFileAction(ActionEvent av){
        if(tabFDoc.isModified())
            exitWindow.getCtrl().showDialog();
        else
            Platform.exit();
    }
    @FXML
    public void loadFunctionAction(ActionEvent av){
        fileChooser.setTitle("Open File");
        File file = fileChooser.showOpenDialog(stage);
        Object obj = null;
        if(file != null)
            obj = functionLoader.functionLoader(file.getAbsolutePath());
        if(obj != null){
            window.getCtrl().setLastButton(2);
            window.getCtrl().setFunction((Function) obj);
            window.getCtrl().showDialog();
        }
    }
    @FXML
    public void redraw(){
        points.clear();
        initPoints();
        table.getItems().clear();
        table.getItems().addAll(points);
        pointOf.setText("Point 0 of " + points.size());
    }
}
