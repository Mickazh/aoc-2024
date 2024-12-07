import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import grid.Empty;
import grid.Grid;
import grid.Guard;
import grid.Pile;

public class Part1 {
  public static void main(String[] args) throws FileNotFoundException {
    File file = new File("input.txt");
    Scanner scannerFile = new Scanner(file);
    Grid grid = new Grid();
    int numberOfLine = 0;
    while (scannerFile.hasNext()) {
      grid.addNewLine();
      String line = scannerFile.nextLine();
      for (int i = 0; i < line.length(); i++) {
        char c = line.charAt(i);
        switch (c) {
          case '.':
            grid.addNewPoint(new Empty());
            break;
          case '#':
            grid.addNewPoint(new Pile());
            break;
          case '^':
            grid.addGuard(new Guard(numberOfLine, i));
            break;
          default:
            break;
        }
      }
      numberOfLine++;
    }
    while (true) {
      try {
        grid.guardGoForwardOrTurn();
      } catch (IndexOutOfBoundsException e) {
        System.out.println(grid.getNumberOfSteps());
        break;
      }
    }
    System.out.println(grid);
    scannerFile.close();
  }
}
