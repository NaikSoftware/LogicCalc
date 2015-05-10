package logiccalc.printer;

/**
 *
 * @author Naik
 */
public abstract class Printer {
    
    private final StringBuilder textBuilder;
    
    public Printer() {
        textBuilder = new StringBuilder();
    }
    
    protected final StringBuilder append(String text) {
        return textBuilder.append(text);
    }
    
    public void printLine(String line) {
        append(line).append("\n");
    }
    
    public void printLine() {
        printLine("");
    }

    @Override
    public String toString() {
        return textBuilder.toString();
    }
    
    public abstract void encodeAndPrintLine(String line);
    public abstract String encode(String text);
    
}
