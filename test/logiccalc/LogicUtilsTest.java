/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package logiccalc;

import logiccalc.printer.PlainPrinter;
import logiccalc.printer.Printer;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author naik
 */
public class LogicUtilsTest {
    
    public LogicUtilsTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of simplify method, of class LogicUtils.
     */
    @Test
    public void testSimplify() {
        System.out.println("simplify");
        String expr = "(1+2+3)(2+!3+!4)(1+3+4)(1+!3+!4)(!1+!2+3+!4)(!1+!2+!3+4)";
        Printer printer = new PlainPrinter();
        LogicUtils.simplify(expr, printer);
        String result = printer.toString().split("СкНФ = ")[1];
        assertEquals("(1!3!2+1!4!2+1!4!3+2134+24!3!1+3!4!1+3!4!2)", result);
    }

    /**
     * Test of openBrackets method, of class LogicUtils.
     */
    @Test
    public void testOpenBrackets() {
        System.out.println("openBrackets");
        String expr = "(1+1)(!1+1)";
        String expResult = "(1)";
        String result = LogicUtils.openBrackets(expr);
        assertEquals(expResult, result);
    }
    
}
