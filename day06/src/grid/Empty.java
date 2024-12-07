package grid;

public class Empty extends Point {

  public Empty() {
    super();
  }

  @Override
  boolean isSolid() {
    return false;
  }

  @Override
  public String toString() {
    return ".";
  }

}
