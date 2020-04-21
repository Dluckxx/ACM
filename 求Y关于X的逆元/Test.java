import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

class Test {
    public static void main(String[] args) {

        int y;
        int x;

        System.out.println("--------| Q2：求 Y 关于模 X 的逆！ |--------");

        Scanner sc = new Scanner(System.in);

        System.out.print("输入Y:");
        y = sc.nextInt();
        System.out.print("输入X:");
        x = sc.nextInt();

        sc.close();

        int left = x;
        int mid = y;
        int last = 0;

        int index;
        int count;

        List<Integer> chu = new ArrayList<Integer>();
        List<Integer> b = new ArrayList<Integer>();

        System.out.println("--------| Q2：求 " + x + " 关于模 " + y + " 的逆！ |--------");

        for (index = 0; last != 1 && index < 100; index++) {
            System.out.print("** 第" + index + "次辗转相除：");
            System.out.print(left + " = " + mid + " * " + left / mid + " + " + left % mid);
            System.out.println(" **");

            chu.add(left / mid);

            last = left % mid;
            left = mid;
            mid = last;
        }

        count = index;
        b.add(1);
        System.out.println("0 --> B(" + (count - index - 1) + ") = 1");

        while (--index != -1) {
            System.out.print(chu.get(index));
            System.out.print(" --> B(" + (count - index - 1) + ") = ");

            if (index == count - 1) {
                b.add(chu.get(index));
                System.out.println(chu.get(index));
            } else {
                b.add(chu.get(index) * b.get(count - index - 1) + b.get(count - index - 2));
                System.out.println(chu.get(index) * b.get(count - index - 1) + b.get(count - index - 2));
            }
        }

        if ((count - index - 2) % 2 == 0) {
            // n为偶数
            System.out.println("**因为n为偶数**");
            System.out.println("X - B(n) = " + (x - b.get(b.size() - 1)) + "为Y关于模X的逆元！");
        } else {
            // n为奇数
            System.out.println("**因为n为奇数**");
            System.out.println("X - B(n) = " + b.get(b.size() - 1) + "为Y关于模X的逆元！");
        }
    }
}