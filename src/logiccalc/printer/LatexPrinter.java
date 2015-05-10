package logiccalc.printer;

import java.util.stream.Stream;

/**
 *
 * @author Naik
 */
public class LatexPrinter extends Printer {

    @Override
    public void printLine(String line) {
        super.printLine(addLineSeparator(line));
    }

    @Override
    public void encodeAndPrintLine(String line) {
        append(encode(line));
    }

    public String encodeLine(String line) {
        for (int i = 1; i < 10; i++) {
            line = line.replace(String.valueOf(i), " x_{" + i + "} ");
        }
        line = line.replace("+", " or ");
        line = line.replace("!", " overline ");
        return addLineSeparator(line);
    }

    @Override
    public String encode(String text) {
        StringBuilder sb = new StringBuilder();
        Stream.of(text.split("\n")).forEach((line) -> {
            sb.append(addLineSeparator(line));
        });
        return sb.toString();
    }
    
    private String addLineSeparator(String line) {
        return line.concat("\n\\newline ");
    }

}
