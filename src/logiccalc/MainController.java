/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package logiccalc;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Hyperlink;
import javafx.scene.control.Label;
import javafx.scene.control.Tab;
import javafx.scene.control.TableView;
import javafx.scene.control.TextArea;
import javafx.scene.control.ToggleButton;

/**
 * FXML Controller class
 *
 * @author naik
 */
public class MainController implements Initializable {
    @FXML
    private Tab tabTable;
    @FXML
    private TableView<?> table;
    @FXML
    private Button btnMinus;
    @FXML
    private Label labelNums;
    @FXML
    private Button btnPlus;
    @FXML
    private TextArea textAreaExpr;
    @FXML
    private Hyperlink hyperlinkAuthor;
    @FXML
    private Button btnHelp;
    @FXML
    private Button btnDdnf;
    @FXML
    private Button btnDknf;
    @FXML
    private Button btnSimplify;
    @FXML
    private ToggleButton toggleBtnLatex;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    

    @FXML
    private void btnMinusClicked(ActionEvent event) {
    }

    @FXML
    private void btnPlusClicked(ActionEvent event) {
    }

    @FXML
    private void tableTabSelectionChanged(Event event) {
    }

    @FXML
    private void onAuthorLinkClicked(ActionEvent event) {
    }

    @FXML
    private void onHelpClicked(ActionEvent event) {
    }

    @FXML
    private void onDdnfClicked(ActionEvent event) {
    }

    @FXML
    private void onDknfClicked(ActionEvent event) {
    }

    @FXML
    private void onSimlifyClicked(ActionEvent event) {
    }

    @FXML
    private void latexToggled(ActionEvent event) {
    }
    
}
