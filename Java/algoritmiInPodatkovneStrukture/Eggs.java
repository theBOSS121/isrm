import java.util.*;

public class Eggs {

    int n; // number of floors
    int k; // number of eggs

    int[] data;
    int dataWidth;

    public Eggs(int n, int k) {
        this.n = n+1;
        this.k = k+1;
        data = new int[this.n * this.k];
        dataWidth = this.k;
        for(int kk = 0; kk < this.k; kk++) {
            for(int nn = 0; nn < this.n; nn++) {
                if(nn == 0 || kk == 0) {
                    data[kk + nn * dataWidth] = 0;
                    continue;
                }
                if(kk == 1) {
                    data[kk + nn * dataWidth] = nn;
                }else if(kk == 2) {
                    int result = (int) Math.ceil(-0.5 + Math.sqrt(0.25 + 2 * nn));
                    data[kk + nn * dataWidth] = result;
                }else {
                    data[kk + nn * dataWidth] = findRecursivly(nn, kk);
                }
            }
        }

        for(int kk = 0; kk < this.k; kk++) {
            if(kk == 0) {
                System.out.printf("    ");
            }else {
                System.out.printf("%4d", kk);
            }
        }
        System.out.println();
        for(int nn = 0; nn < this.n; nn++) {
            for(int kk = 0; kk < this.k; kk++) {
                if(kk == 0) {
                    System.out.printf("%4d", nn);
                }else {
                    System.out.printf("%4d", data[kk + nn * dataWidth]);
                }
            }
            System.out.println();
        }
    }

    public int findRecursivly(int n, int k) {
        if(data[k + n * dataWidth] != 0) return data[k + n * dataWidth];
        int min = n;
        for(int i = 1; i <= n; i++) {
            int a = 1 + findRecursivly(i-1, k-1);
            int b = 1 + findRecursivly(n-i, k);
            if(a < b) {
                if(b < min) min = b;
            }else {
                if(a < min) min = a;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int floors = sc.nextInt();
        int eggs = sc.nextInt();
        new Eggs(floors, eggs);
    }
}