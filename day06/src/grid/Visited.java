package grid;

public class Visited extends Point {

  @Override
  boolean isSolid() {
    return false;
  }

  boolean isVisited() {
    return true;
  }

  @Override
  public String toString() {
    return "X";
  }
 
}
