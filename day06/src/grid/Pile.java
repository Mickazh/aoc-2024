package grid;

public class Pile extends Point {

  public Pile() {
    super();
  }

  @Override
  boolean isSolid() {
    return true;
  }

  @Override
  public String toString() {
    return "#";
  }
  
}
