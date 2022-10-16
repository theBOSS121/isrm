import java.util.*;
public class Recursion {
    public static void main(String[] args) {
        if(jaPalindrom("rotator")) {
            System.out.println("palindrom");
        }else {
            System.out.println("not palindrom");
        }
    }

    public static boolean jaPalindrom(String word) {
        char a = word.charAt(0);
        char b = word.charAt(word.length()-1);
        if(a == b) {
            if(word.length() > 2) {
                jaPalindrom(word.substring(1, word.length()-2));
            }
            return true;
        }else {
            return false;
        }
    }
}
