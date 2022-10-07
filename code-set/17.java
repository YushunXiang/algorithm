import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author ysxiang
 */
class Main {

    public int getSteps(
            ArrayList<Integer> nums,
            int currentSum, int targetSum,
            int frontFlag, int backFlag
    ) {
        if (currentSum > targetSum) {
            return -1;
        } else if (currentSum == targetSum) {
            return 1;
        } else {
            if (frontFlag < backFlag) {
                int front2back = getSteps( // 从前往后
                        nums,
                        currentSum + nums.get(frontFlag), targetSum,
                        frontFlag + 1, backFlag
                );
                int back2front = getSteps( // 从后往前
                        nums,
                        currentSum + nums.get(backFlag - 1), targetSum,
                        frontFlag, backFlag - 1
                );
                if (front2back == -1 && back2front == -1) {
                    return -1;
                } else if (front2back == -1) {
                    return back2front + 1;
                } else if (back2front == -1) {
                    return front2back + 1;
                } else {
                    if (back2front > front2back) {
                        return front2back + 1;
                    } else {
                        return back2front + 1;
                    }
                }
            } else {
                return -1;
            }
        }
    }

    public int minSelect(int targetSum, ArrayList<Integer> nums) {
        if (nums.size() >= 2) {
            int front2back = getSteps( // 从前往后
                    nums,
                    nums.get(0), targetSum,
                    1, nums.size());
            int back2front = getSteps( // 从后往前
                    nums,
                    nums.get(nums.size() - 1), targetSum,
                    0, nums.size() - 1
            );
            if (front2back == -1 && back2front == -1) {
                return -1;
            } else if (front2back == -1) {
                return back2front;
            } else if (back2front == -1) {
                return front2back;
            } else {
                if (back2front > front2back) {
                    return front2back;
                } else {
                    return back2front;
                }
            }
        } else if (nums.size() == 1) {
            if (nums.get(0) == targetSum) {
                return 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int targetSum = scanner.nextInt();
        String numStr = "";
        ArrayList<Integer> nums = new ArrayList<Integer>();
        while ((numStr = scanner.next()).equals("q") == false) {
            nums.add(Integer.parseInt(numStr));
        }
        System.out.println(new Main().minSelect(targetSum, nums));
    }
}