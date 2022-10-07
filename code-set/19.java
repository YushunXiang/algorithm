import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author ysxiang
 */
class Main {
    public ArrayList<Integer> rightBigger(ArrayList<Integer> nums) {
        ArrayList<Integer> targetNums = new ArrayList<Integer>();
        for (int iter = 0; iter < nums.size(); iter++) {
            int iterNum = nums.get(iter);
            int count = 0;
            for (int j = iter + 1; j < nums.size(); j++) {
                if (iterNum > nums.get(j)) {
                    count++;
                }
            }
            targetNums.add(count);
        }

        return targetNums;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String numStr = "";
        ArrayList<Integer> nums = new ArrayList<Integer>();
        while ((numStr = scanner.next()).equals("q") == false) {
            nums.add(Integer.parseInt(numStr));
        }
        ArrayList<Integer> targetNums = new Main().rightBigger(nums);
        for (int iter = 0; iter < targetNums.size() - 1; iter++) {
            System.out.print(targetNums.get(iter) + " ");
        }
        System.out.println(targetNums.get(targetNums.size() - 1));
    }
}