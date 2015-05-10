package logiccalc;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Hyperlink;
import javafx.scene.control.Label;
import javafx.scene.control.Tab;
import javafx.scene.control.TableView;
import javafx.scene.control.TextArea;
import javafx.scene.control.ToggleButton;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.Window;
import logiccalc.printer.LatexPrinter;
import logiccalc.printer.PlainPrinter;
import logiccalc.printer.Printer;

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
        Printer printer;
        if (toggleBtnLatex.isSelected()) {
            printer = new LatexPrinter();
        } else {
            printer = new PlainPrinter();
        }
        if (tabTable.isSelected()) {
        } else {
            LogicUtils.simplify(textAreaExpr.getText(), printer);
            System.out.println(printer);
        }
        showResult(printer.toString(), ((Node) event.getTarget()).getScene().getWindow());
    }

    private void showResult(String text, Window window) {
        Stage stage = new Stage();
        stage.initOwner(window);
        stage.initModality(Modality.WINDOW_MODAL);
        Parent root = null;
        try {
            root = FXMLLoader.load(getClass().getResource("text_result.fxml"));
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }

        Scene scene = new Scene(root);
        TextArea textArea = (TextArea) scene.lookup("#textAreaResultText");
        textArea.setText(text);

        stage.setTitle("Logic Calc result");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    private void latexToggled(ActionEvent event) {
    }

}
