public class Main {

    public static void main(String[] args) {
        int vsota = 0;
        // System.out.println(10 * 9 / 2 + 9 * 8 / 2);
        
        for(int l = 0; l < 10; l++) {
            for(int k = l; k < 10; k++) {
                for(int j = k; j < 10; j++) {
                    for(int i = 1; i < 11; i++) {
                        vsota += ((i-j-k-l) * (i-k-l-j-1)) / 2;
                    }
                    System.out.println(vsota);
                }
            }
        }
        System.out.println(vsota);
    }
}