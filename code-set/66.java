import java.util.Scanner;
import java.util.Vector;

/**
 * @author ysxiang
 */
class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Vector<Integer> heights = new Vector<Integer>();
        for (int iter = 0; iter < n; iter++) {
            heights.add(scanner.nextInt());
        }
        System.out.println(new Main().solution(heights));
    }

    public int solution(Vector<Integer> heights) {
        int length = heights.size();
        int maxVolume = 0;
        for (int frontFlag = 0; frontFlag < length - 1; frontFlag++) {
            for (int backFlag = frontFlag + 1; backFlag < length; backFlag++) {
                int minHeight =
                        heights.get(frontFlag) < heights.get(backFlag) ?
                                heights.get(frontFlag) : heights.get(backFlag);
                int volume = minHeight * (backFlag - frontFlag);
                maxVolume = volume > maxVolume ? volume : maxVolume;
            }
        }
        return maxVolume;
    }
}