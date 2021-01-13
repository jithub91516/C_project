import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class ListBoundedIntSetTest {

  @BeforeClass
  public static void setUpClass() {
  }

  @Before
  public void setUp() {
    ListNode.clearCounters();
  }

  public static void assertNear(final long test, final int target, final int delta) {
    assertTrue(test >= (target - delta));
    assertTrue(test <= (target + delta));
  }

  public static void assertWithin(final String which, final long test, final int lo, final int hi) {
    assertTrue(which + " is too low", lo <= test);
    assertTrue(which + " is too high", test <= hi);
  }

  private static void assertCounters(final int constLo, final int constHi, final int getLo, final int getHi,
      final int setLo, final int setHi) {
    assertWithin("Number of constructor calls", ListNode.constructorCalls(), constLo, constHi);
    assertWithin("Number of getNext calls", ListNode.getNextCalls(), getLo, getHi);
    assertWithin("Number of setNext calls", ListNode.setNextCalls(), setLo, setHi);    
  }

  @Test
  public void testConstructor1() {
    final ListBoundedIntSet s = new ListBoundedIntSet(4);
    // state - - - -
    assertCounters(4, 4, 0, 0, 4, 4);
    assertEquals("It looks like you have a problem recording the size.", 0, s.size());
    assertEquals("It looks like you have a problem recording the capacity.", 4, s.capacity());
    assertFalse("Your contains method is telling us that it has an element it should not have.", s.contains(1));
    assertFalse("Your contains method is telling us that it has an element it should not have.", s.contains(2));
    assertFalse("Your contains method is telling us that it has an element it should not have.", s.contains(3));
    assertFalse("Your contains method is telling us that it has an element it should not have.", s.contains(4));
  }

  @Test
  public void testConstructor2() {
    final ListBoundedIntSet s = new ListBoundedIntSet(new int[] { 1, 2, 3, 4 });
    // state 1 2 3 4
    assertCounters(4, 4, 0, 0, 4, 4);
    assertEquals(4, s.size());
    assertEquals(4, s.capacity());
    assertTrue("Your contains method is telling us that it does not have an element it should have.", s.contains(1));
    assertTrue("Your contains method is telling us that it does not have an element it should have.", s.contains(2));
    assertTrue("Your contains method is telling us that it does not have an element it should have.", s.contains(3));
    assertTrue("Your contains method is telling us that it does not have an element it should have.", s.contains(4));
  }

  @Test
  public void testAddNew() {
    ListBoundedIntSet s = new ListBoundedIntSet(4);
    // state - - - -
    ListNode.clearCounters();
    assertEquals("It appears that adding a new element to a set with room is not working correctly.", 1, s.add(1));
    // state 1 - - -
    assertEquals("It appears that adding a new element to a set with room is not working correctly.", 1, s.add(2));
    // state 2 1 - -
    assertEquals("It appears that adding a new element to a set with room is not working correctly.", 1, s.add(3));
    // state 3 2 1 -
    assertEquals(1, s.add(4));
    // state 4 3 2 1
    assertCounters(0, 0, 9, 14, 6, 8);
    assertTrue("Your contains method is telling us that it does not have an element it should have. Is you add method working correctly?", s.contains(1));
    assertTrue("Your contains method is telling us that it does not have an element it should have. Is you add method working correctly?", s.contains(2));
    assertTrue("Your contains method is telling us that it does not have an element it should have. Is you add method working correctly?", s.contains(3));
    assertTrue("Your contains method is telling us that it does not have an element it should have. Is you add method working correctly?", s.contains(4));
  }

  @After
  public void tearDown() {
  }

  @AfterClass
  public static void tearDownClass() {
  }
}
