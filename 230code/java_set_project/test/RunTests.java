import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

import org.junit.runner.RunWith;
import org.junit.runner.notification.Failure;
import org.junit.runners.Suite;

@RunWith(Suite.class)
@Suite.SuiteClasses({ ListBoundedIntSetTest.class, })
public class RunTests {

  public static void main(String[] args) {
    JUnitCore runner = new JUnitCore();
    Result r = runner.run(RunTests.class);
    for (Failure failure : r.getFailures()) {
      System.out.println(failure.toString());
    }
  }

}
