import java.util.*;

public class Main {
    public static void main(String arg[]) {
        Scanner snc = new Scanner(System.in);
        int n = snc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = snc.nextInt();
        }
        Main main = new Main();
        System.out.println(main.hIndex(arr));
    }

    public int hIndex(int[] citations) {
        // method 1: 排序
        Arrays.sort(citations);
        int iter = citations.length - 1;
        int hIndex = 0;
        while (iter >= 0 && citations[iter] > hIndex) { // 如果citations[iter] > hIndex，则说明第iter + 1篇论文的引用数大于 h，符合条件，继续往下搜索。
            hIndex++;
            iter--;
        }
        return hIndex;
    }
}