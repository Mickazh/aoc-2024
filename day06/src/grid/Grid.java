package grid;

import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;

public class Grid {
  private List<List<Point>> grid;

  private Guard guard;

  public Grid() {
    grid = new ArrayList<>();
  }

  public List<List<Point>> getGrid() {
    return grid;
  }

  public void addNewLine() {
    grid.add(new ArrayList<>());
  }

  public void addNewPoint(Point point) {
    grid.get(grid.size() - 1).add(point);
  }

  public void addGuard(Guard guard) {
    this.guard = guard;
    addNewPoint(guard);
  }

  public void guardGoForwardOrTurn() {
    int h = guard.getH(), w = guard.getW();
    int[] direction = guard.getDirection();
    int dH = direction[0], dW = direction[1];
    int newH = h + dH, newW = w + dW;
    Point nextPoint = grid.get(newH).get(newW);
    if (nextPoint.isSolid()) {
      guard.turn();
      guardGoForwardOrTurn(); // shouldn't do that but I don't want to repeat code
      return;
    }
    grid.get(h).set(w, new Visited()); // 
    if (!nextPoint.isVisited()) {
      guard.incrNumberOfSteps();
    }
    guard.updatePosition();
    grid.get(newH).set(newW, guard);
  }

  public int getNumberOfSteps() {
    return guard.getNumberOfSteps();
  }

  @Override
  public String toString() {
    StringJoiner joiner = new StringJoiner(System.lineSeparator());
    for (List<Point> list : grid) {
      StringBuilder builder = new StringBuilder();
      for (Point point : list) {
        builder.append(point);
      }
      joiner.add(builder);
    }
    return joiner.toString();
  }

  
}
