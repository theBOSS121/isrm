import java.util.*;

public class Backpack {

    int maxVolume, n;
    
    public Backpack() {
        Scanner sc = new Scanner(System.in);
        // int maxVolume = 3, n = 4;

        maxVolume = sc.nextInt();
        n = sc.nextInt();
        int[] volumes = new int[n];
        int[] prices = new int[n];
        for(int i = 0; i < n; i++) {
            volumes[i] = sc.nextInt();
            prices[i] = sc.nextInt();
        }
        // volumes[0] = 2;
        // prices[0] = 2;
        // volumes[1] = 5;
        // prices[1] = 2;
        // volumes[2] = 4;
        // prices[2] = 0;
        // volumes[3] = 5;
        // prices[3] = 3;

        List<Solution> solutions = new ArrayList<Solution>();
        solutions.add(new Solution(0, 0));
        printSolutions(solutions, 0);
        for(int i = 0; i < n; i++) {
            int solutionsSize = solutions.size();
            for(int s = 0; s < solutionsSize; s++) {
                solutions.add(new Solution(solutions.get(s).volume + volumes[i], solutions.get(s).price + prices[i]));
            }
            Collections.sort(solutions, new SortSolution());
            
            for(int s = 0; s < solutions.size(); s++) {
                for(int ss = s+1; ss < solutions.size(); ss++) {
                    if(solutions.get(ss).volume > maxVolume) {
                        solutions.remove(ss);
                        ss--;
                        continue;
                    }
                    if(solutions.get(s).volume <= solutions.get(ss).volume && solutions.get(s).price >= solutions.get(ss).price) {
                        solutions.remove(ss);
                        ss--;
                        continue;
                    }
                }
            }
            printSolutions(solutions, i+1);
        }
    }

    private void printSolutions(List<Solution> solutions, int iteration) {   
        System.out.print(iteration + ": ");     
        for(int s = 0; s < solutions.size(); s++) {
            if(solutions.get(s).volume > maxVolume) {
                solutions.remove(s);
                s--;
                continue;
            } 
            System.out.print(solutions.get(s) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        new Backpack();
       
    }
}

class Solution {
    int volume;
    int price;

    public Solution(int v, int p) {
        this.volume = v;
        this.price = p;
    }

    public String toString() {
        return "(" + volume + ", " + price + ")";
    }
}

class SortSolution implements Comparator<Solution> {
 
    public int compare(Solution a, Solution b) {
        if(a.volume != b.volume) return a.volume - b.volume;
        else return b.price - a.price;
    }
}