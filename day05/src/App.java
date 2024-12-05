import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Map<Integer, List<Integer>> rules = new HashMap<>();
        int count = 0;
        try {
            File fileRules = new File("rules.txt");
            Scanner fileScanner = new Scanner(fileRules);
            while (fileScanner.hasNext()) {
                String line = fileScanner.nextLine();
                int first, second;
                String[] pair = line.split("\\|");
                first = Integer.parseInt(pair[0]);
                second = Integer.parseInt(pair[1]);
                if (rules.get(first) == null) {
                    rules.put(first, new ArrayList<>());
                }
                rules.get(first).add(second);
            }
            fileScanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        try {
            File fileData = new File("data.txt");
            Scanner scannerData = new Scanner(fileData);
            while (scannerData.hasNext()) {
                String line = scannerData.nextLine();
                List<Integer> numbers = Arrays.stream(line.split(",")).map(Integer::parseInt).toList();
                if (isLineCorrect(numbers, rules)) {
                    count += numbers.get(numbers.size() / 2);
                }

            }
            scannerData.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println(count);
    }

    private static boolean isLineCorrect(List<Integer> numbers, Map<Integer, List<Integer>> rules) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            if (!rules.get(numbers.get(i)).contains(numbers.get(i + 1))) {
                return false;
            }
        }
        return true;
    }

}
