package grid;

public class Guard extends Point {
  private static int[][] directions = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
  // first is the height and the second is the width
  private int numberOfSteps;

  private int directionIndex;

  private int h, w;

  public Guard(int h, int w) {
    super();
    this.numberOfSteps = 1;
    this.directionIndex = 0;
    this.h = h;
    this.w = w;
  }

  public int getNumberOfSteps() {
    return numberOfSteps;
  }

  public int getH() {
    return h;
  }

  public int getW() {
    return w;
  }

  @Override
  public String toString() {
    return "^";
  }

  public void turn() {
    directionIndex = (directionIndex + 1) % directions.length;
  }

  public int[] getDirection() {
    return directions[directionIndex];
  }

  @Override
  boolean isSolid() {
    return true;
  }

  void incrNumberOfSteps() {
    numberOfSteps++;
  }

  void updatePosition() {
    h += directions[directionIndex][0];
    w += directions[directionIndex][1];
  }
}
