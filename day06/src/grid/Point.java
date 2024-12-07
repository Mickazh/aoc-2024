package grid;

public abstract class Point {

  abstract boolean isSolid();

  boolean isVisited() {
    return false;
  }
}
