package logiccalc;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.control.TextArea;

/**
 * FXML Controller class
 *
 * @author Naik
 */
public class TextResultController implements Initializable {
    @FXML
    private TextArea textAreaResultText;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    

    @FXML
    private void resultTextClose(ActionEvent event) {
        ((Node)event.getTarget()).getScene().getWindow().hide();
    }
    
}
