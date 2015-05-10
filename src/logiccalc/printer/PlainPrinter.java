package logiccalc.printer;

/**
 *
 * @author Naik
 */
public class PlainPrinter extends Printer {

    @Override
    public void encodeAndPrintLine(String line) {
        super.append(line);
    }

    @Override
    public String encode(String text) {
        return text;
    }

}
