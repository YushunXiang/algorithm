import java.util.*;

/**
 * @author ysxiang 
 */
public class Main {

    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();
        System.out.println(maximumEvenSplit(n));
    }

    public static List<Long> maximumEvenSplit(long finalSum) {
        ArrayList<Long> list = new ArrayList<Long>();
        if (finalSum % 2 == 0) {
            long base = 2;
            list.add(base);
            finalSum = finalSum - 2;
            while (list.get(list.size() - 1) < finalSum) {
                base = base + 2;
                finalSum = finalSum - base;
                list.add(base);
            }
            list.set(list.size() - 1, list.get(list.size() - 1) + finalSum);
        }
        return list;
    }
}